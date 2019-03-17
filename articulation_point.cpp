#include<bits/stdc++.h>
using namespace std;
#define MAX 500

void articulation_point_util(vector<vector<int> >&g,int vis[],int parent[],int low[],int disc[],int ap[],int s)
{
	static int time=0;
	int childern=0;
	vis[s]=1;

	disc[s]=low[s]=++time;

	for(auto it=g[s].begin();it!=g[s].end();it++)
	{
		int curr=*it;
		if(vis[curr]==-1)
		{
			childern++;
			parent[curr]=s;
			articulation_point_util(g,vis,parent,low,disc,ap,curr);

			low[s]=min(low[s],low[curr]);

			if(parent[s]==-1 && childern>1)
				ap[s]=true;
			else if(parent[s]!=-1 && disc[s]<=low[curr])
				ap[s]=true;
		}
		else if(curr!=parent[s])
		{
			low[s]=min(low[s],disc[curr]);
		}
	}

}
void articulation_point(vector<vector<int> >&g,int V)
{
	int vis[V];
	int parent[V];
	int low[V];
	int disc[V];
	int ap[V];

	for(int i=0;i<V;i++)
	{
		vis[i]=-1;
		parent[i]=-1;
		ap[i]=-1;
	}

	for(int i=0;i<V;i++)
	{
		if(vis[i]==-1)
			articulation_point_util(g,vis,parent,low,disc,ap,i);
	}
	for(int i=0;i<V;i++)
	{
		if(ap[i]!=-1)
			cout << i << " ";
	}

}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,x,y;
		cin >> n >> m;
		vector<vector<int> >g(MAX);
		for(int i=0;i<m;i++)
		{
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		articulation_point(g,n);
		cout << endl;

	}
}
