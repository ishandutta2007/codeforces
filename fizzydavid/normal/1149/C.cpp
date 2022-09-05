//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
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
const int maxn = 200111;
int n, q;
struct info
{
	int dlt, mn, mx, ans;
	info()
	{
		dlt = mn = mx = ans = 0;
	}
	void out()
	{
		cerr<<"dlt="<<dlt<<" mn="<<mn<<" mx="<<mx<<" ans="<<ans<<endl;
	}
};
info operator + (const info &a, const info &b)
{
	info ret;
	ret.dlt = a.dlt+b.dlt;
	ret.mn = min(a.mn, a.dlt+b.mn);
	ret.mx = max(a.mx, a.dlt+b.mx);
	ret.ans = max(max(a.ans, b.ans-a.dlt), b.mx+a.dlt-a.mn-a.mn);
	return ret;
}
const int B = 262144;
struct SGTinfo
{
	info a[B+B];
	void change(int x, info v)
	{
		x += B;
		a[x] = v;
		for (int i=x>>1; i; i>>=1) a[i] = a[i<<1]+a[i<<1|1];
	}
	info query(int x, int y)
	{
		info retl, retr;
		x += B-1; y += B+1;
		while (x^y^1)
		{
			if (~x&1) retl = retl+a[x^1];
			if ( y&1) retr = a[y^1]+retr;
			x>>=1;
			y>>=1;
		}
		return retl+retr;
	}
}T, Tr;
int a[maxn];
info IU, ID;
void update(int x)
{
	if (a[x]==1)
	{
		T.change(x, IU);
		Tr.change(n-x+1, ID);
	}
	else
	{
		T.change(x, ID);
		Tr.change(n-x+1, IU);
	}
}
struct SGT
{
	struct node
	{
		pair<int,int> mx;
		int lz;
		void addlz(int L)
		{
			lz += L;
			mx.FF += L;
		}
	}a[maxn*4];
	#define ls p<<1
	#define rs p<<1|1
	void pushdown(int p)
	{
		if (a[p].lz!=0)
		{
			a[ls].addlz(a[p].lz);
			a[rs].addlz(a[p].lz);
			a[p].lz = 0;
		}
	}
	void update(int p)
	{
		a[p].mx = max(a[ls].mx, a[rs].mx);
	}
	void build(int l, int r, int p)
	{
		a[p].lz = 0;
		if (l==r)
		{
			a[p].mx = MP(0, l);
			return;
		}
		int m = l+r>>1;
		build(l, m, ls);
		build(m+1, r, rs);
		update(p);
	}
	void add(int x, int y, int v, int l, int r, int p)
	{
		if (y<l||r<x) return;
		if (x<=l&&r<=y)
		{
			a[p].addlz(v);
			return;
		}
		pushdown(p);
		int m = (l+r)>>1;
		add(x, y, v, l, m, ls);
		add(x, y, v, m+1, r, rs);
		update(p);
	}
}sgt;


int query(pair<int,int> M)
{
//	for (int i=1; i<=n; i++) cerr<<a[i]<<" "; cerr<<endl;
//	cerr<<"M="<<M.FF<<","<<M.SS<<endl;
	int ans = 0;
	info cur;
	cur.dlt = cur.mn = cur.mx = M.FF; cur.ans = -M.FF;
	info tmp;
//	T.query(M.SS, n).out();
//	Tr.query(n-M.SS+2, n).out();
	
	tmp = cur+T.query(M.SS, n);
//	cerr<<tmp.ans<<endl;
	ans = max(ans, M.FF+tmp.ans);
	tmp = cur+Tr.query(n-M.SS+2, n);
//	cerr<<tmp.ans<<endl;
	ans = max(ans, M.FF+tmp.ans);
	return ans;
}

int main()
{
	IU.dlt = IU.mx = IU.ans = 1;
	ID.dlt = -1; ID.mn = -1; ID.ans = 1;
	getii(n, q);
	n = 2*(n-1);
	sgt.build(1, n+1, 1);
	
	for (int i=1; i<=n; i++)
	{
		char c = getreal();
		if (c=='(') a[i] = 1; else a[i] = -1;
		update(i);
		sgt.add(i+1, n+1, a[i], 1, n+1, 1);
	}
	putsi(query(sgt.a[1].mx));
	for (int i=1; i<=q; i++)
	{
		int x, y;
		getii(x, y);
		if (x>y) swap(x, y);
		sgt.add(x+1, y, a[y]-a[x], 1, n+1, 1);
		swap(a[x], a[y]);
		update(x);
		update(y);
		putsi(query(sgt.a[1].mx));
	}
	return 0;
}