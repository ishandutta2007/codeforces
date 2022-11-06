#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
int f[N],siz[N],fa[N],val[N];
void pre(int u,int p)
{
	siz[u]=1;
	fa[u]=p;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==p) continue;
		pre(v,u);
		siz[u]+=siz[v];
	}
}
int dn[N],maxn;
void dfs(int u,int x)
{
	dn[u]=1;
	int res=0,r2=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[u]) continue;
		dfs(v,x);
		if(dn[v]==siz[v]) dn[u]+=siz[v];
		else if(res<dn[v]) r2=res,res=dn[v];
		else r2=max(r2,dn[v]);
	}
	dn[u]+=res;
	if(val[u]<x) dn[u]=0;
	maxn=max(maxn,dn[u]+r2);
}
int main()
{
	int n,m=0,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]),m=max(m,val[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	int rt=min_element(val+1,val+n+1)-val;
	pre(rt,0);
	int l=1,r=m,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		maxn=0;dfs(rt,mid);
		if(maxn>=k) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}