#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define lowbit(x) (x&-x)

struct node { int t,next; }a[200010];

int f[100010][310];
int fa[100010],son[100010],dep[100010],top[100010],size[100010];
int head[100010],h[100010],in[100010],out[100010],num[100010],c[100010],g[100010],n,q,k,m,r,cl,tot;

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

inline bool cmp(const int &x,const int &y) { return h[x]<h[y]; }

inline int pls(const int x,const int y) { return (x+y<mod)?x+y:x+y-mod; }
inline int mns(const int x,const int y) { return (x-y<0)?x-y+mod:x-y; }

inline void link(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline int lca(int x,int y)
{
	for (;top[x]!=top[y];x=fa[top[x]]) if (dep[top[x]]<dep[top[y]]) swap(x,y);
	if (dep[x]>dep[y]) swap(x,y);
	return x;
}

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
	in[x]=++cl;top[x]=tp;
	if (son[x]) dfs2(son[x],tp);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]||t==son[x]) continue;
		dfs2(t,t);
	}
	out[x]=cl;
}

inline void add(int x,int y) { for (;x<=n;x+=lowbit(x)) c[x]=pls(c[x],y); }

inline int sum(int x)
{
	int res=0;
	for (;x;x-=lowbit(x)) res=pls(res,c[x]);
	return res;
}

int main()
{
	n=rd();q=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();link(x,y);link(y,x); }
	cl=0;dep[1]=1;dfs1(1);dfs2(1,1);
	while (q--)
	{
		k=rd();m=rd();r=rd();
		for (int i=1;i<=k;i++) num[i]=rd();
		for (int i=1;i<=k;i++) add(in[num[i]],1),add(out[num[i]]+1,mod-1);
		for (int i=1;i<=k;i++)
		{
			int hh=lca(num[i],r);
			h[num[i]]=sum(in[num[i]])+sum(in[r])-sum(in[hh])-sum(in[fa[hh]])-1;
		}
		for (int i=1;i<=k;i++) g[i]=num[i];
		sort(g+1,g+k+1,cmp);
		f[0][0]=1;
		for (int i=1;i<=m;i++) f[0][i]=0;
		for (int i=1;i<=k;i++) for (int j=1;j<=m;j++) f[i][j]=pls((ll)f[i-1][j]*(j-h[g[i]])%mod,f[i-1][j-1]);
		int ans=0;
		for (int i=0;i<=m;i++) ans=pls(ans,f[k][i]);
		print(ans);
		for (int i=1;i<=k;i++) add(in[num[i]],mod-1),add(out[num[i]]+1,1);
	}
	return 0;
}