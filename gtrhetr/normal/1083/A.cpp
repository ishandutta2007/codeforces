#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { int t,next; }a[3000010];

ll maxn[4000010],tag[4000010];
ll num[1000010],dis[1000010],ans;
int head[1000010],dfn[1000010],out[1000010],pid[1000010],n,cl,tt,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs(int x,int y)
{
	dfn[x]=++cl;pid[cl]=x;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dis[t]=dis[x]+num[t];
		pre_dfs(t,x);
	}
	out[x]=cl;
}

inline void pushup(int o) { maxn[o]=max(maxn[o<<1],maxn[o<<1|1]); }

inline void pushdown(int o)
{
	if (!tag[o]) return;
	maxn[o<<1]+=tag[o];maxn[o<<1|1]+=tag[o];
	tag[o<<1]+=tag[o];tag[o<<1|1]+=tag[o];
	tag[o]=0;
}

inline void build(int o,int l,int r)
{
	if (l==r) { maxn[o]=dis[pid[l]];return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y,ll hh)
{
	if (l>=x&&r<=y) { maxn[o]+=hh;tag[o]+=hh;return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void dfs(int x,int y)
{
	ans=max(ans,maxn[1]);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		modify(1,1,tt,dfn[t],out[t],-num[x]);
		if (dfn[t]>1) modify(1,1,tt,1,dfn[t]-1,num[t]);
		if (out[t]<tt) modify(1,1,tt,out[t]+1,tt,num[t]);
		dfs(t,x);
		modify(1,1,tt,dfn[t],out[t],num[x]);
		if (dfn[t]>1) modify(1,1,tt,1,dfn[t]-1,-num[t]);
		if (out[t]<tt) modify(1,1,tt,out[t]+1,tt,-num[t]);
	}
}

int main()
{
	n=rd();tt=n;tot=0;
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd(),z=rd();
		num[++tt]=-z;
		add(x,tt);add(tt,x);
		add(y,tt);add(tt,y);
	}
	cl=0;dis[1]=num[1];pre_dfs(1,0);
	build(1,1,tt);
	ans=0;dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}