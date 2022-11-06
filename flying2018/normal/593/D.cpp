#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt=1;
int ids[N];
ll wr[N<<1];
void add(int u,int v,ll w1)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	wr[cnt]=w1;
	head[u]=cnt;
}
int dep[N],fa[N],ffa[N];
ll w[N];
void dfs(int u,int f)
{
	dep[u]=dep[fa[u]=f]+1;
	ffa[u]=w[u]==1?ffa[fa[u]]:u;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		w[v]=wr[i];
		ids[i/2]=v;
		dfs(v,u);
	}
}
int find(int x){return ffa[x]==x?x:(ffa[x]=find(ffa[x]));}
#define MM 1000000000000000001ll
ll work(int x,int y,ll w1)
{
	ll ans=w1;
	for(;x!=y;x=find(fa[x]))
	{
		if(dep[x]<dep[y]) swap(x,y);
		ans=ans/w[x];
		if(!ans) return 0;
	}
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int opt;
		ll x,y,z;
		scanf("%d%lld%lld",&opt,&x,&y);
		if(opt==1)
		{
			scanf("%lld",&z);
			printf("%lld\n",work(x,y,z));
		}
		else
		{
			x=ids[x];
			w[x]=y;
			if(y==1) ffa[x]=ffa[fa[x]];
		}
	}
	return 0;
}