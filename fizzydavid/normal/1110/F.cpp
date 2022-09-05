//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 500111;
ll ia[maxn];
struct SGT
{
	struct node
	{
		ll lz, mn;
		void addlz(ll L)
		{
			lz += L;
			mn += L;
		}
	}a[maxn*4];
	#define ls p<<1
	#define rs p<<1|1
	void pushdown(int p)
	{
		if (a[p].lz)
		{
			a[ls].addlz(a[p].lz);
			a[rs].addlz(a[p].lz);
			a[p].lz = 0;
		}
	}
	void update(int p)
	{
		a[p].mn = min(a[ls].mn, a[rs].mn);
	}
	void add(int x, int y, ll v, int l, int r, int p)
	{
		if (x<=l&&r<=y)
		{
			a[p].addlz(v);
			return;
		}
		if (r<x||y<l) return;
		pushdown(p);
		int m = l+r>>1;
		add(x, y, v, l, m, ls);
		add(x, y, v, m+1, r, rs);
		update(p);
	}
	ll query(int x, int y, int l, int r, int p)
	{
		if (x<=l&&r<=y) return a[p].mn;
		if (r<x||y<l) return 1e18;
		pushdown(p);
		int m = l+r>>1;
		return min(query(x, y, l, m, ls), query(x, y, m+1, r, rs));
	}
	void build(int l, int r, int p)
	{
		a[p].lz = 0;
		if (l==r)
		{
			a[p].mn = ia[l];
			return;
		}
		int m = l+r>>1;
		build(l, m, ls);
		build(m+1, r, rs);
		update(p);
	}
}sgt;
int n, q;
vector<pair<pair<int,int>,int> > qr[maxn];
int p[maxn];
ll w[maxn], sum[maxn];
vector<int> son[maxn];
int dfnr[maxn];
ll ans[maxn];
void pdfs(int x)
{
	if (son[x].size()==0)
	{
		ia[x] = sum[x];
	}
	else ia[x] = 1e17;
	for (auto u : son[x])
	{
		sum[u] = sum[x]+w[u];
		pdfs(u);
	}
}
void dfs(int x)
{
	for (auto p : qr[x])
	{
//		cerr<<"query:"<<p.FF.FF<<","<<p.FF.SS<<endl;
		ans[p.SS] = sum[x]+sgt.query(p.FF.FF, p.FF.SS, 1, n, 1);
	}
	for (auto u : son[x])
	{
//		cerr<<"add:"<<u<<","<<dfnr[u]<<" "<<-2*w[u]<<endl;
		sgt.add(u, dfnr[u], -2*w[u], 1, n, 1);
		dfs(u);
		sgt.add(u, dfnr[u], 2*w[u], 1, n, 1);
//		cerr<<"add:"<<u<<","<<dfnr[u]<<" "<<2*w[u]<<endl;
	}
}
int main()
{
	getii(n, q);
	for (int i=2; i<=n; i++)
	{
		getii(p[i], w[i]);
		son[p[i]].PB(i);
	}
	pdfs(1);
	sgt.build(1, n, 1);
	for (int i=n; i>=2; i--)
	{
		dfnr[i] = max(dfnr[i], i);
		dfnr[p[i]] = max(dfnr[p[i]], dfnr[i]);
	}
	for (int i=1; i<=q; i++)
	{
		int x, l, r;
		getiii(x, l, r);
		qr[x].PB(MP(MP(l, r), i));
	}
	dfs(1);
	for (int i=1; i<=q; i++) putsi(ans[i]);
	return 0;
}