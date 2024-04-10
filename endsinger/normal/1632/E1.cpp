#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,d[N],fa[N][20],ans[N],dx,dy,vd,md;
vector<int>e[N],p[N];
void dfs(int u,int f)
{
	d[u]=d[f]+1;
	md=max(md,d[u]);
	fa[u][0]=f;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
}
int lca(int u,int v)
{
	if(d[u]<d[v])
		swap(u,v);
	for(int i=18;i>=0;i--)
		if(d[fa[u][i]]>=d[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=18;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dis(int u,int v)
{
	return d[u]+d[v]-2*d[lca(u,v)];
}
void add(int u)
{
	if(!dx)
	{
		dx=u;
		return;
	}
	if(!dy)
	{
		dy=u;
		vd=dis(dx,dy);
		return;
	}
	int d1=dis(u,dx),d2=dis(u,dy);
	if(d1>d2)
	{
		if(d1>vd)
			dy=u,vd=d1;
	}
	else
	{
		if(d2>vd)
			dx=u,vd=d2;
	}
}
void sol()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		e[i].clear();
		p[i].clear();
		for(int j=0;j<=18;j++)
			fa[i][j]=0;
		d[i]=0;
		ans[i]=n;
	}
	dx=dy=vd=md=0,d[0]=-1;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans[i]=md;
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int i=1;i<=n;i++)
		p[d[i]].push_back(i);
	for(int i=n;i>=1;i--)
	{
		for(auto j:p[i])
			add(j);
		int h=i-1-(vd+1)/2;
		if(h>=0)
			ans[h]=i-1;
	}
	for(int i=n-1;i>=1;i--)
		ans[i]=min(ans[i],ans[i+1]);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}