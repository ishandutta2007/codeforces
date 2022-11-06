#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 200010
#define ll long long
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
int deg[N];
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
	deg[u]++;
}
queue<int>q;
ll w[N];
bool cut[N];
int fa[N];
void topo(int n,int x)
{
	for(int i=1;i<=n;i++)
	if(deg[i]==1 && i!=x) q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		cut[u]=true;
		q.pop();
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(cut[v]) continue;
			fa[u]=v,deg[v]--;
			if(deg[v]==1) q.push(v);
		}
	}
}
ll sm;
ll dfs(int u)
{
	sm+=w[u];
	ll maxn=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(!cut[v] || v==fa[u]) continue;
		maxn=max(maxn,dfs(v));
	}
	return maxn+w[u];
}
int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	ll ans=0,res=0;
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]),ans+=w[i];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	scanf("%d",&x);deg[x]++;
	topo(n,x);
	for(int i=1;i<=n;i++)
	if(cut[i] && !cut[fa[i]]) res=max(res,dfs(i));
	printf("%lld\n",ans+res-sm);
	return 0;
}