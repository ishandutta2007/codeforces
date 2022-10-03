#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define y1 DCXISSOHANDSOME

struct node { int t,next; }a[30000010];

vector<int> v[100010];
vector<pii> h[400010];
stack<int> st;

int id1[400010],id2[400010];
int fa[100010],son[100010],dep[100010],top[100010],dfn[100010],size[100010];
int head[30000010],n,m,cl,tt,tot;
bool vis[30000010];

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
	for (int t:v[x])
	{
		if (t==fa[x]) continue;
		dep[t]=dep[x]+1;
		fa[t]=x;dfs1(t);
		size[x]+=size[t];
		if (size[t]>size[son[x]]) son[x]=t;
	}
}

inline void dfs2(int x,int tp)
{
	dfn[x]=++cl;top[x]=tp;
	if (son[x]) dfs2(son[x],tp);
	for (int t:v[x])
	{
		if (t==fa[x]||t==son[x]) continue;
		dfs2(t,t);
	}
}

inline int calc(const int &x,const int &y) { return (x-1)*2+y+1; }

inline void modify(int o,int l,int r,int x,int y,pii hh)
{
	if (l>=x&&r<=y) { h[o].push_back(hh);return; }
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh); 
}

inline void work(int x,int y,pii hh)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		modify(1,1,n,dfn[top[x]],dfn[x],hh);
		x=fa[top[x]];
	}
	if (dep[x]>dep[y]) swap(x,y);
	if (dep[x]<dep[y]) modify(1,1,n,dfn[x]+1,dfn[y],hh);
}

inline void gao1(int o,int l,int r,int now)
{
	for (pii hh:h[o])
	{
		add(now,calc(hh.first,hh.second^1));
		int hhh=++tt;
		add(now,hhh);add(calc(hh.first,hh.second),hhh);
		now=hhh;
	}
	if (l==r) return;
	int mid=(l+r)>>1;
	gao1(o<<1,l,mid,now);
	gao1(o<<1|1,mid+1,r,now);
}

inline int gao2(int o,int l,int r)
{
	int now=++tt;
	if (l<r)
	{
		int mid=(l+r)>>1;
		add(gao2(o<<1,l,mid),now);
		add(gao2(o<<1|1,mid+1,r),now);
	}
	for (int i=h[o].size()-1;i>=0;i--)
	{
		pii hh=h[o][i];
		add(now,calc(hh.first,hh.second^1));
		int hhh=++tt;
		add(now,hhh);add(calc(hh.first,hh.second),hhh);
		now=hhh;
	}
	return now;
}

inline bool dfs(int x)
{
	if (vis[x]) return true;
	if (x<=m*2&&vis[((x-1)^1)+1]) return false;
	vis[x]=true;st.push(x);
	for (int i=head[x];i;i=a[i].next) if (!dfs(a[i].t)) return false;
	return true;
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();v[x].push_back(y);v[y].push_back(x); }
	dep[1]=1;cl=0;dfs1(1);dfs2(1,1);
	m=rd();tt=m*2;
	for (int i=1;i<=m;i++)
	{
		int x1=rd(),y1=rd(),x2=rd(),y2=rd();
		work(x1,y1,pii(i,0));
		work(x2,y2,pii(i,1));
	}
	gao1(1,1,n,++tt);
	gao2(1,1,n);
	for (int i=1;i<=m;i++) if (!vis[calc(i,0)]&&!vis[calc(i,1)])
	{
		while (!st.empty()) st.pop();
		if (!dfs(calc(i,0)))
		{
			while (!st.empty()) vis[st.top()]=false,st.pop();
			if (!dfs(calc(i,1))) { puts("NO");return 0; }
		}
	}
	puts("YES");
	for (int i=1;i<=m;i++) if (vis[calc(i,0)]) print(1);else print(2);
	return 0;
}