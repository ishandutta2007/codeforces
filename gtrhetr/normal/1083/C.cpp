#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define getmin(a,b) ((dep[a]<dep[b])?(a):(b))

struct node { int t,next; }a[400010];

int mn[400010][20],dfn[400010],mxd[400010],dep[200010],cl;
int head[200010],fa[200010],id[200010],p[200010],n,m,tot;

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

inline void dfs(int x,int y)
{
	dfn[x]=++cl;mn[cl][0]=x;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dep[t]=dep[x]+1;dfs(t,x);
		mn[++cl][0]=x;
	}
}

inline int lca(int x,int y)
{
	int l=dfn[x],r=dfn[y];
	if (l>r) swap(l,r);
	int d=r-l+1;
	return getmin(mn[l][mxd[d]],mn[r-(1<<mxd[d])+1][mxd[d]]);
}

pii h[800010];
bool bo[800010];

inline bool check(int x,int y,int h1,int h2)
{
	int hh=lca(x,y);
	if (lca(h1,hh)!=hh||lca(h2,hh)!=hh) return false;
	if (!(lca(x,h1)==h1||lca(y,h1)==h1)) return false;
	if (!(lca(x,h2)==h2||lca(y,h2)==h2)) return false;
	return true;
}

inline void pushup(int o)
{
	if (!bo[o<<1]||!bo[o<<1|1]) { bo[o]=false;h[o]=pii(-1,-1);return; }
	int h1=h[o<<1].first,h2=h[o<<1].second,h3=h[o<<1|1].first,h4=h[o<<1|1].second;
	bo[o]=true;
	if (check(h1,h2,h3,h4)) { h[o].first=h1;h[o].second=h2;return; }
	if (check(h1,h3,h2,h4)) { h[o].first=h1;h[o].second=h3;return; }
	if (check(h1,h4,h2,h3)) { h[o].first=h1;h[o].second=h4;return; }
	if (check(h2,h3,h1,h4)) { h[o].first=h2;h[o].second=h3;return; }
	if (check(h2,h4,h1,h3)) { h[o].first=h2;h[o].second=h4;return; }
	if (check(h3,h4,h1,h2)) { h[o].first=h3;h[o].second=h4;return; }
	bo[o]=false;h[o]=pii(-1,-1);
}

inline pii merge(pii x,pii y)
{
	int h1=x.first,h2=x.second,h3=y.first,h4=y.second;
	pii res;
	if (!h1||!h2||!h3||!h4) return pii(h1|h3,h2|h4);
	if (check(h1,h2,h3,h4)) { res.first=h1;res.second=h2;return res; }
	if (check(h1,h3,h2,h4)) { res.first=h1;res.second=h3;return res; }
	if (check(h1,h4,h2,h3)) { res.first=h1;res.second=h4;return res; }
	if (check(h2,h3,h1,h4)) { res.first=h2;res.second=h3;return res; }
	if (check(h2,h4,h1,h3)) { res.first=h2;res.second=h4;return res; }
	if (check(h3,h4,h1,h2)) { res.first=h3;res.second=h4;return res; }
	return pii(-1,-1);
}

inline void build(int o,int l,int r)
{
	if (l==r) { h[o]=pii(id[l],id[r]);bo[o]=true;return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y)
{
	if (l==r) { h[o]=pii(y,y);bo[o]=true;return; }
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y);
	else modify(o<<1|1,mid+1,r,x,y);
	pushup(o);
}

inline int query(int o,int l,int r,pii now)
{
	if (l==r)
	{
		if (merge(now,h[o]).first!=-1) return l+1;
		return l;
	}
	int mid=(l+r)>>1;
	if (!bo[o<<1]) return query(o<<1,l,mid,now);
	pii hh=merge(now,h[o<<1]);
	if (hh.first!=-1) return query(o<<1|1,mid+1,r,hh);
	return query(o<<1,l,mid,now);
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<=n;i++) p[i]=rd(),id[p[i]]=i;
	for (int i=2;i<=n;i++) fa[i]=rd(),add(fa[i],i),add(i,fa[i]);
	dep[1]=1;dfs(1,0);
	for (int i=1;(1<<i)<=cl;i++) mxd[1<<i]=i;
	for (int i=1;i<=cl;i++) if (!mxd[i]) mxd[i]=mxd[i-1];
	for (int j=1;(1<<j)<=cl;j++) for (int i=1;i+(1<<j)-1<=cl;i++) mn[i][j]=getmin(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
	build(1,0,n-1);
	m=rd();
	while (m--)
	{
		int type=rd();
		if (type==1)
		{
			int x=rd(),y=rd();
			modify(1,0,n-1,p[x],y);
			modify(1,0,n-1,p[y],x);
			swap(p[x],p[y]);
		}
		else print(query(1,0,n-1,pii(0,0)));
	}
	return 0;
}