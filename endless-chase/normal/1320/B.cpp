#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,x,y,k,dist[222222],mx,mn,cur;
vector<int> g[222222],rg[222222];
int a[222222];
void bfs(int s)
{
	queue<int> q;
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<rg[x].size();i++)
		{
			int to=rg[x][i];
			if (!~dist[to])
			{
				dist[to]=dist[x]+1;
				q.push(to);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		rg[y].push_back(x);
	}
	scanf("%d",&k);
	for (int i=1;i<=k;i++) scanf("%d",&a[i]);
	bfs(a[k]);
	cur=a[1];
	for (int i=1;i<k;i++)
	{
		if (dist[a[i+1]]+1==dist[a[i]]);
		else mn++;
		for (int j=0;j<g[cur].size();j++)
		{
			int to=g[cur][j];
			if (to==a[i+1]) continue;
			if (dist[to]+1==dist[cur])
			{
				mx++;
				break;
			}
		}
		cur=a[i+1];
	}
	printf("%d %d\n",mn,mx);
	return Accepted;
}