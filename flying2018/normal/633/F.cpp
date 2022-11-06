#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
ll w[N];
ll f[N][4];// 0:, 1:, 2:, 3: 
ll g[N];
void dfs(int u,int pre)
{
	f[u][0]=f[u][1]=f[u][2]=f[u][3]=w[u];
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==pre) continue;
		dfs(v,u);
		f[u][3]=max(f[u][3],max(f[v][3],f[u][1]+f[v][1]));
		f[u][3]=max(f[u][3],max(f[u][0]+f[v][2],f[u][2]+f[v][0]));
		f[u][2]=max(f[u][2],max(f[v][2]+w[u],max(f[u][0]+f[v][1],f[v][0]+w[u]+g[u])));
		f[u][1]=max(f[u][1],max(f[v][1],f[u][0]+f[v][0]));
		f[u][0]=max(f[u][0],w[u]+f[v][0]);
		g[u]=max(g[u],f[v][1]);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%lld\n",f[1][3]);
	return 0;
}