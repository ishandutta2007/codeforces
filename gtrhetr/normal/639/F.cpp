#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

struct node { int t,v,next; }a[600010];

unordered_map<int,bool> mp[300010];
vector<int> v[300010];
stack<int> st;

int dfn[300010],low[300010],from[300010],cl,cnt;
int head[300010],n,m,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print1() { putchar('Y');putchar('E');putchar('S');putchar('\n'); }
inline void print2() { putchar('N');putchar('O');putchar('\n'); }

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x,int y)
{
	dfn[x]=low[x]=++cl;st.push(x);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (!dfn[t])
		{
			dfs(t,a[i].v);
			low[x]=min(low[x],low[t]);
			if (low[t]>dfn[x])
			{
				cnt++;
				while (233)
				{
					int hh=st.top();st.pop();from[hh]=cnt;
					if (hh==t) break;
				}
			}
		}
		else if (a[i].v!=y) low[x]=min(low[x],dfn[t]);
	}
}

int fa[300010],son[300010],dep[300010],top[300010],size[300010];

inline void dfs1(int x)
{
	size[x]=1;
	for (int t:v[x])
	{
		if (t==fa[x]) continue;
		dep[t]=dep[x]+1;
		fa[t]=x;dfs1(t);
		size[x]+=size[t];
		if (size[x]>size[son[x]]) son[x]=t;
	}
}

inline void dfs2(int x,int tp)
{
	top[x]=tp;dfn[x]=++cl;
	if (son[x]) dfs2(son[x],tp);
	for (int t:v[x]) if (t!=fa[x]&&t!=son[x]) dfs2(t,t);
}

inline int lca(int x,int y)
{
	for (;top[x]!=top[y];x=fa[top[x]]) if (dep[top[x]]<dep[top[y]]) swap(x,y);
	if (dep[x]>dep[y]) swap(x,y);
	return x;
}

pii h[300010];

int c[1000010],tt,R=0;
int d[300010],ni,mi;

int p[2000010],pt;

namespace gao2
{

struct node { int t,v,next; }a[5000010];

int head[300010],dfn[300010],low[300010],from[300010],cl,C,tt,tot;

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline void link(int x,int y)
{
	if (x==cnt||y==cnt) return;
	add(x,y,++tt);add(y,x,tt);
}

inline void dfs(int x,int y)
{
	dfn[x]=low[x]=++cl;st.push(x);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (!dfn[t])
		{
			dfs(t,a[i].v);
			low[x]=min(low[x],low[t]);
			if (low[t]>dfn[x])
			{
				C++;
				while (233)
				{
					int hh=st.top();st.pop();from[hh]=C;
					if (hh==t) break;
				}
			}
		}
		else if (a[i].v!=y) low[x]=min(low[x],dfn[t]);
	}
}

inline void work()
{
	cl=C=0;
	for (int i=1;i<=pt;i++) if (!dfn[p[i]])
	{
		dfs(p[i],0);C++;
		while (!st.empty()) from[st.top()]=C,st.pop();
	}
	for (int i=1;i<=pt;i++) dfn[p[i]]=low[p[i]]=head[p[i]]=0;
}

}

inline int rotate(int x) { return (x+R-1)%n+1; }

int s[2000010],tp;

inline bool cmp(const int &x,const int &y) { return dfn[x]<dfn[y]; }

inline void build()
{
	c[++tt]=cnt;sort(c+1,c+tt+1,cmp);
	tt=unique(c+1,c+tt+1)-c-1;
	s[tp=1]=cnt;p[pt=1]=cnt;
	gao2::tt=gao2::tot=0;
	for (int i=2;i<=tt;i++)
	{
		int x=c[i],y=lca(x,s[tp]);
		p[++pt]=x;p[++pt]=y;
		while (tp>1&&dep[s[tp-1]]>=dep[y]) gao2::link(s[tp],s[tp-1]),tp--;
		if (tp&&dep[y]<dep[s[tp]]) gao2::link(y,s[tp]),tp--;
		if (dep[y]>dep[s[tp]]) s[++tp]=y;
		s[++tp]=x;
	}
	for (;tp>1;tp--) gao2::link(s[tp-1],s[tp]);
	for (int i=1;i<=mi;i++) gao2::link(h[i].first,h[i].second);
	gao2::work();
}

int main()
{
	n=rd();m=rd();int Q=rd();
	for (int i=1;i<=m;i++) { int x=rd(),y=rd();add(x,y,i);add(y,x,i); }
	cl=cnt=0;
	vector<int> root;
	for (int i=1;i<=n;i++) if (!dfn[i])
	{
		dfs(i,0);cnt++;root.push_back(cnt);
		while (!st.empty()) from[st.top()]=cnt,st.pop();
	}
	cnt++;
	for (int t:root) v[cnt].push_back(t),v[t].push_back(cnt);
	for (int i=1;i<=n;i++) for (int j=head[i];j;j=a[j].next)
	{
		int t=a[j].t;
		if (from[i]!=from[t]&&!mp[from[i]][from[t]])
		{
			mp[from[i]][from[t]]=mp[from[t]][from[i]]=true;
			v[from[i]].push_back(from[t]);
			v[from[t]].push_back(from[i]);
		}
	}
	memset(dfn,0,sizeof(dfn));
	dep[cnt]=1;cl=0;dfs1(cnt);dfs2(cnt,cnt);
	for (int t=1;t<=Q;t++)
	{
		ni=rd();mi=rd();
		tt=0;
		for (int i=1;i<=ni;i++) d[i]=from[rotate(rd())],c[++tt]=d[i];
		for (int i=1;i<=mi;i++)
		{
			int x=from[rotate(rd())],y=from[rotate(rd())];
			h[i]=pii(x,y);c[++tt]=x;c[++tt]=y;
		}
		build();
		bool flag=true;
		for (int i=2;i<=ni;i++) if (gao2::from[d[i]]!=gao2::from[d[1]]) flag=false;
		R=(R+t*flag)%n;
		if (flag) print1();
		else print2();
	}
	return 0;
}