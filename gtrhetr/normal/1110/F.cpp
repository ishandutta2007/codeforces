#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<int,ll>
#define inf 2333333333333333333LL

struct hhhh { int l,r,id; };

set<pll> st[500010];
vector<hhhh> v[500010];

ll mn[2000010],tag[2000010],dep[500010],ans[500010];
int dfn[500010],out[500010],n,m,cl;
bool bo[500010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void dfs(int x)
{
	dfn[x]=++cl;
	for (set<pll>::iterator it=st[x].begin();it!=st[x].end();it++)
	{
		pll hh=*it;
		dep[hh.first]=dep[x]+hh.second;
		dfs(hh.first);
	}
	out[x]=cl;
	if (st[x].empty()) bo[x]=true;
}

inline ll min(const ll &x,const ll &y) { return (x<y)?x:y; }

inline void pushdown(int o)
{
	if (!tag[o]) return;
	mn[o<<1]+=tag[o];tag[o<<1]+=tag[o];
	mn[o<<1|1]+=tag[o];tag[o<<1|1]+=tag[o];
	tag[o]=0;
}

inline void pushup(int o) { mn[o]=min(mn[o<<1],mn[o<<1|1]); }

inline void build(int o,int l,int r)
{
	mn[o]=inf;tag[o]=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}

int xx,yy;
ll hhh;

inline void update(int o,int l,int r)
{
	if (l==r) { mn[o]=hhh;return; }
	int mid=(l+r)>>1;
	if (xx<=mid) update(o<<1,l,mid);
	else update(o<<1|1,mid+1,r);
	pushup(o);
}

inline void update(int o,int l,int r,int x,ll hh)
{
	xx=x;hhh=hh;
	update(o,l,r);
}

inline void modify(int o,int l,int r)
{
	if (l>=xx&&r<=yy) { mn[o]+=hhh;tag[o]+=hhh;return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (xx<=mid) modify(o<<1,l,mid);
	if (yy>mid) modify(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y,ll hh)
{
	xx=x;yy=y;hhh=hh;
	modify(o,l,r);
}

inline ll query(int o,int l,int r)
{
	if (l>=xx&&r<=yy) return mn[o];
	pushdown(o);
	int mid=(l+r)>>1;ll res=inf;
	if (xx<=mid) res=min(res,query(o<<1,l,mid));
	if (yy>mid) res=min(res,query(o<<1|1,mid+1,r));
	return res;
}

inline ll query(int o,int l,int r,int x,int y)
{
	xx=x;yy=y;
	return query(o,l,r);
}

inline void gao(int x)
{
	for (int i=0;i<v[x].size();i++)
	{
		hhhh hh=v[x][i];
		ans[hh.id]=query(1,1,n,hh.l,hh.r);
	}
	for (set<pll>::iterator it=st[x].begin();it!=st[x].end();it++)
	{
		pll hh=*it;
		int t=hh.first;
		modify(1,1,n,1,n,hh.second);
		modify(1,1,n,dfn[t],out[t],-hh.second*2);
		gao(t);
		modify(1,1,n,1,n,-hh.second);
		modify(1,1,n,dfn[t],out[t],hh.second*2);
	}
}

int main()
{
	n=rd();m=rd();
	for (int i=2;i<=n;i++)
	{
		int x=rd();ll y=rd();
		st[x].insert(pll(i,y));
	}
	cl=0;dfs(1);
	build(1,1,n);
	for (int i=1;i<=n;i++) if (bo[i]) update(1,1,n,dfn[i],dep[i]);
	for (int i=1;i<=m;i++)
	{
		int x=rd(),l=rd(),r=rd();
		v[x].push_back((hhhh){l,r,i});
	}
	gao(1);
	for (int i=1;i<=m;i++) print(ans[i]);
	return 0;
}