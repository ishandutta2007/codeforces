#include<bits/stdc++.h>
using namespace std;

struct node { int t,next; }a[400010];

map<int,int> mp[200010];

int fa[200010],son[200010],dep[200010],top[200010],dfn[200010],out[200010],pid[200010],size[200010];
int head[200010],n,m,cl,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void dfs1(int x)
{
	size[x]=1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]) continue;
		dep[t]=dep[x]+1;
		fa[t]=x;dfs1(t);
		size[x]+=size[t];
		if (size[t]>size[son[x]]) son[x]=t;
	}
}

inline void dfs2(int x,int tp)
{
	dfn[x]=++cl;pid[cl]=x;top[x]=tp;
	if (son[x]) dfs2(son[x],tp);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]||t==son[x]) continue;
		dfs2(t,t);
	}
	out[x]=cl;
}

inline int lca(int x,int y)
{
	for (;top[x]!=top[y];x=fa[top[x]]) if (dep[top[x]]<dep[top[y]]) swap(x,y);
	if (dep[x]>dep[y]) swap(x,y);
	return x;
}

inline int jump(int x,int y)
{
	for (;top[x]!=top[y];x=fa[top[x]]) if (fa[top[x]]==y) return top[x];
	return pid[dfn[y]+1];
}

int tag[800010],sum[800010];

inline void pushup(int o)
{
	if (tag[o]) sum[o]=0;
	else sum[o]=sum[o<<1]+sum[o<<1|1];
}

inline void build(int o,int l,int r)
{
	sum[o]=r-l+1;tag[o]=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y)
	{
		tag[o]+=hh;
		if (tag[o]) sum[o]=0;
		else sum[o]=((l==r)?1:(sum[o<<1]+sum[o<<1|1]));
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void gao(int x,int y,int tag)
{
	int hh=lca(x,y);
	if (hh==y) swap(x,y);
	if (hh==x)
	{
		int hhh=jump(y,x);
		int l1=dfn[hhh],r1=out[hhh],l2=dfn[y],r2=out[y];
		if (l1<l2) modify(1,1,n,l1,l2-1,tag);
		if (r2<r1) modify(1,1,n,r2+1,r1,tag);
	}
	else
	{
		if (dfn[x]>dfn[y]) swap(x,y);
		int l1=dfn[x],r1=out[x],l2=dfn[y],r2=out[y];
		if (l1>1) modify(1,1,n,1,l1-1,tag);
		if (r1<l2-1) modify(1,1,n,r1+1,l2-1,tag);
		if (r2<n) modify(1,1,n,r2+1,n,tag);
	}
}

int main()
{
	n=rd();m=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	dep[1]=1;cl=0;dfs1(1);dfs2(1,1);
	build(1,1,n);
	while (m--)
	{
		int x=rd(),y=rd();
		if (x>y) swap(x,y);
		if (mp[x][y]) gao(x,y,-1);
		else gao(x,y,1);
		mp[x][y]^=1;
		print(sum[1]);
	}
	return 0;
}