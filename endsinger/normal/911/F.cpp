#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int d[3][N],n,x,y;
long long ans;
vector<int>e[N],out;
queue<int>q;
void bfs(int *dis,int b)
{
	for(int i=1;i<=n;i++)
		dis[i]=-1;
	dis[b]=0;
	q.push(b);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:e[u])
		{
			if(dis[v]==-1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
int dfs(int u,int f,int t)
{
	int zh=0;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		zh|=dfs(v,u,t);
	}
	if(u==y)
		zh=1;
	if(t==0&&zh==0)
	{
		out.push_back(u);
		out.push_back(d[1][u]>d[2][u]?x:y);
		out.push_back(u);
		ans+=max(d[1][u],d[2][u]);
	}
	if(t==1&&zh==1&&f)
	{
		out.push_back(u);
		out.push_back(x);
		out.push_back(u);
		ans+=d[1][u];
	}
	return zh;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bfs(d[0],1);
	for(int i=1;i<=n;i++)
		if(d[0][i]>d[0][x])
			x=i;
	bfs(d[1],x);
	for(int i=1;i<=n;i++)
		if(d[1][i]>d[1][y])
			y=i;
	bfs(d[2],y);
	dfs(x,0,0);
	dfs(x,0,1);
	printf("%I64d\n",ans);
	for(int i=0;i<out.size();i+=3)
		printf("%d %d %d\n",out[i],out[i+1],out[i+2]);
	return 0;
}