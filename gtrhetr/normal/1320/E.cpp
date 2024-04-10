#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

struct node { int t,next; }a[400010];

vector<int> v[200010];

pii h[200010];

int num[200010];

int fa[200010][20],dep[200010];
int head[200010],dfn[200010],c[400010],n,m,cl,cnt,tot;

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
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs(int x)
{
	dfn[x]=++cl;
	for (int i=1;i<20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x][0]) continue;
		dep[t]=dep[x]+1;
		fa[t][0]=x;pre_dfs(t);
	}
}

inline int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	int t=dep[x]-dep[y];
	for (int i=19;~i;i--) if ((t>>i)&1) x=fa[x][i];
	if (x==y) return x;
	for (int i=19;~i;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

inline int getdis(int x,int y) { return dep[x]+dep[y]-dep[lca(x,y)]*2; }

int st[400010],p[400010],pt,top;

inline bool cmp(const int &x,const int &y) { return dfn[x]<dfn[y]; }

inline void link(int x,int y)
{
	v[x].push_back(y);
	v[y].push_back(x);
}

inline void build()
{
	sort(c+1,c+cnt+1,cmp);
	cnt=unique(c+1,c+cnt+1)-c-1;
	st[top=1]=1;p[pt=1]=1;
	for (int i=2;i<=cnt;i++)
	{
		int x=c[i],y=lca(st[top],x);
		p[++pt]=x;p[++pt]=y;
		while (top>1&&dep[st[top-1]]>dep[y]) link(st[top-1],st[top]),top--;
		if (top&&dep[y]<dep[st[top]]) link(y,st[top]),top--;
		if (y!=st[top]) st[++top]=y;
		st[++top]=x;
	}
	while (top>1) link(st[top-1],st[top]),top--;
}

pii dis[400010];

int from[400010];
bool inq[400010];

struct hhhh
{
	pii y;int x;
	hhhh(pii yy,int xx):y(yy),x(xx) {}
};

inline bool operator <(const hhhh &x,const hhhh &y) { return y.y<x.y; }

priority_queue<hhhh> q;

inline void work()
{
	int m1=rd(),m2=rd();
	c[cnt=1]=1;
	for (int i=1;i<=m1;i++) h[i].first=rd(),h[i].second=rd(),c[++cnt]=h[i].first;
	for (int i=1;i<=m2;i++) num[i]=rd(),c[++cnt]=num[i];
	build();
	while (!q.empty()) q.pop();
	for (int i=1;i<=pt;i++) from[p[i]]=0,dis[p[i]]=pii(n+1,0),inq[p[i]]=false;
	for (int i=1;i<=m1;i++) from[h[i].first]=i,dis[h[i].first]=pii(0,i),q.push(hhhh(pii(0,i),h[i].first));
	while (!q.empty())
	{
		hhhh hh=q.top();q.pop();
		int x=hh.x,y=from[x];
		if (inq[x]) continue;
		inq[x]=true;
		for (int t:v[x])
		{
			if (inq[t]) continue;
			pii now((getdis(t,h[y].first)+h[y].second-1)/h[y].second,y);
			if (now<dis[t]) dis[t]=now,from[t]=now.second,q.push(hhhh(now,t));
		}
	}
	for (int i=1;i<=m2;i++) print(from[num[i]]);
	putchar('\n');
	for (int i=1;i<=pt;i++) v[p[i]].clear();
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd();
		add(x,y);add(y,x);
	}
	cl=0;pre_dfs(1);
	m=rd();
	while (m--) work();
	return 0;
}