#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

struct node { int t,v,next; }a[1000010];
struct edge { int s,t,v; }e[500010];

pii h[500010];

int head[500010],from[500010],fa[500010],dep[500010],f[500010],n,k,m,tt,tot;
bool vis[500010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline int find(int x) { return (x==from[x])?x:from[x]=find(from[x]); }

inline void dfs(int x)
{
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]) continue;
		dep[t]=dep[x]+1;
		fa[t]=x;f[t]=a[i].v;
		dfs(t);
	}
}

int main()
{
	n=rd();k=rd();m=rd();tot=0;
	for (int i=1;i<=n;i++) from[i]=i;
	for (int i=1;i<=k;i++)
	{
		h[i].first=rd();h[i].second=rd();
		add(h[i].first,h[i].second,1);
		add(h[i].second,h[i].first,1);
		int f1=find(h[i].first),f2=find(h[i].second);
		from[f1]=f2;
	}
	for (int i=1;i<=m;i++)
	{
		e[i].s=rd();e[i].t=rd();e[i].v=rd();
		int f1=find(e[i].s),f2=find(e[i].t);
		if (f1!=f2) add(e[i].s,e[i].t,0),add(e[i].t,e[i].s,0),vis[i]=true,from[f1]=f2;
	}
	dep[1]=1;dfs(1);
	for (int i=1;i<=n;i++) from[i]=i;
	ll ans=0;tt=0;
	for (int i=1;i<=m;i++) if (!vis[i])
	{
		int x=e[i].s,y=e[i].t;
		x=find(x);y=find(y);
		while (x!=y)
		{
			if (dep[x]<dep[y]) swap(x,y);
			if (f[x]) ans+=e[i].v,tt++;
			from[x]=fa[x];x=find(x);
		}
	}
	if (tt<k) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}