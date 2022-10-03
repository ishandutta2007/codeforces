#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

struct node { int t,next; }a[1000010];

ll size[500010],f[500010],g[500010],g1[500010],ans=inf;
int head[500010],son[500010],d[500010],h[500010],n,tt,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline ll calc(ll n) { return n*(n-1)/2; }

inline void pre_dfs(int x,int y)
{
	size[x]=1;son[x]=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		pre_dfs(t,x);son[x]++;
		size[x]+=size[t];
	}
	if (!son[x]) f[x]=0;
	else
	{
		f[x]=inf;
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (t==y) continue;
			f[x]=min(f[x],f[t]+calc(size[x]-size[t]));
		}
	}
}

inline void dfs(int x,int y)
{
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs(t,x);
	}
	if (son[x]<2) return;
	tt=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		ll now=size[t];
		h[++tt]=now;
		ll hh=f[t]*2-n*now*2+now+now*now;
		if (hh<g[now]) g1[now]=g[now],g[now]=hh;
		else if (hh<g1[now]) g1[now]=hh;
	}
	sort(h+1,h+tt+1);
	tt=unique(h+1,h+tt+1)-h-1;
	ll res=inf;
	for (int i=1;i<=tt;i++) if (g1[h[i]]<inf) res=min(res,(ll)n*n-n+g[h[i]]+g1[h[i]]+(ll)h[i]*h[i]*2);
	if (tt>1)
	{
		for (int i=1;i<tt;i++) for (int j=i+1;j<=tt;j++) res=min(res,(ll)n*n-n+g[h[i]]+g[h[j]]+(ll)h[i]*h[j]*2);
	}
	ans=min(ans,res);
	for (int i=1;i<=tt;i++) g[h[i]]=g1[h[i]]=inf;
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x);d[x]++;d[y]++; }
	if (n==2) { puts("2");return 0; }
	int rt=0;
	for (int i=1;i<=n;i++) if (d[i]>1) { rt=i;break; }
	for (int i=1;i<=n;i++) g[i]=inf;
	pre_dfs(rt,0);
	dfs(rt,0);
	printf("%lld\n",calc(n)*2-ans/2);
	return 0;
}