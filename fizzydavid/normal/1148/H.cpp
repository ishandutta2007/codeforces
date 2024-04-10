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
int n;
struct SGT
{
	struct node
	{
		int mx, lz;
		void addlz(int L)
		{
			lz += L;
			mx += L;
		}
	};
	vector<node> a;
	int n;
	void init(int _n)
	{
		n = _n;
		a.resize(n*4);
	}
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
		a[p].mx = max(a[ls].mx, a[rs].mx);
	}
	void add(int x, int y, int v, int l, int r, int p)
	{
		if (r<x||y<l) return;
		if (x<=l&&r<=y)
		{
			a[p].addlz(v);
			return;
		}
		pushdown(p);
		int m = l+r>>1;
		add(x, y, v, l, m, ls);
		add(x, y, v, m+1, r, rs);
		update(p);
	}
	void add(int x, int y, int v) {add(x, y, v, 0, n, 1);}
	
	int query(int x, int y, int l, int r, int p)
	{
		if (x>y) return -1e9;
		if (x<=l&&r<=y) return a[p].mx;
		pushdown(p);
		int m = l+r>>1;
		if (x<=m&&m<y) return max(query(x, y, l, m, ls), query(x, y, m+1, r, rs));
		else if (x<=m) return query(x, y, l, m, ls);
		else return query(x, y, m+1, r, rs);
	}
	int query(int x, int y) {return query(x, y, 0, n, 1);}
	
	int querynxt(int x, int v, int l, int r, int p)
	{
		if (r<x||a[p].mx<v) return n+1;
		if (x<=l&&l==r) return l;
		pushdown(p);
		int m = l+r>>1;
		int ret = querynxt(x, v, l, m, ls);
		if (ret!=n+1) return ret; else return querynxt(x, v, m+1, r, rs);
	}
	int querynxt(int x, int v) {return querynxt(x, v, 0, n, 1);}
	
	int querypre(int x, int v, int l, int r, int p)
	{
		if (x<l||a[p].mx<v) return 0;
		if (r<=x&&l==r) return r;
		pushdown(p);
		int m = l+r>>1;
		int ret = querypre(x, v, m+1, r, rs);
		if (ret!=0) return ret; else return querypre(x, v, l, m, ls);
	}
	int querypre(int x, int v) {return querypre(x, v, 0, n, 1);}
	
}T;
struct tag
{
	int v, bt, et;
	ll sum;
	tag(int V=0, int BT=0, int ET=0, ll SUM=0) : v(V), bt(BT), et(ET), sum(SUM) {}
	ll query(int t) {return 1ll*v*(t-et)+sum;}
};
tag operator + (const tag &a, const tag &b)
{
	if (a.v==0) return b;
	if (b.v==0) return a;
	return tag(b.v, a.bt, b.et, a.sum+b.sum+1ll*(b.bt-a.et)*a.v);
}
struct SGT2
{
	int tot;
	struct node
	{
		int tl, tr;
		tag t;
		void clear_lz() {t.v = 0;}
		void addlz(const tag &nt)
		{
			t = t + nt;
		}
		ll query(int T)
		{
			return 1ll*(T-t.et)*t.v+t.sum;
		}
	}a[maxn*88];
	#define tls a[p].tl
	#define trs a[p].tr
	void pushdown(int p)
	{
		if (a[p].t.v!=0)
		{
			a[tls].addlz(a[p].t);
			a[trs].addlz(a[p].t);
			a[p].clear_lz();
		}
	}
	int newnode(int q)
	{
		int p = ++tot;
		a[p] = a[q];
		return p;
	}
	void set(int x, int y, int v, int t, int l, int r, int p)
	{
		if (x<=l&&r<=y)
		{
			a[p].addlz(tag(v, t, t, 0));
			return;
		}
		if (!tls||tls<p) tls = newnode(tls);
		if (!trs||trs<p) trs = newnode(trs);
		pushdown(p);
		int m = l+r>>1;
		if (x<=m) set(x, y, v, t, l, m, tls);
		if (m<y) set(x, y, v, t, m+1, r, trs);
	}
	tag query(int x, int l, int r, int p)
	{
		if (!p) return tag();
		if (l==r) return a[p].t;
		int m = l+r>>1;
		if (x<=m) return query(x, l, m, tls)+a[p].t;
		else return query(x, m+1, r, trs)+a[p].t;
	}
	int queryv(int x, int l, int r, int p)
	{
		if (a[p].t.v!=0||l==r) return a[p].t.v;
		if (!p) return 0;
		int m = l+r>>1;
		if (x<=m) return queryv(x, l, m, tls);
		else return queryv(x, m+1, r, trs);	
	}
}T2;
int rt[maxn];
void Set(int l, int r, int v, int t)
{
	T2.set(l, r, v, t, 0, n+1, rt[t]);
}
void modify(int x, int v, int t)
{
	static int lst[maxn];
	int pnxt = T.querynxt(x, -lst[x]+1);
	int dlt = v-lst[x];
	T.add(x, x, -dlt);
	lst[x] = v;
	v = min(v, -T.query(0, x-1, 0, n+1, 1));
	while (v>0)
	{
		int nnxt = T.querynxt(x, -v+1);
		Set(x, nnxt-1, v, t);
		if (nnxt==pnxt) break;
		x = nnxt;
		v = lst[x];
	}
}
ll queryhsum(int L, int R, int K)
{
	return T2.query(K, 0, n+1, rt[R]).query(R+1)-T2.query(K, 0, n+1, rt[L-1]).query(L);
}
ll query(int L, int R, int K)
{
	int pt0, pt1;
	int l, r;
	l = L, r = R;
	while (l<=r)
	{
		int m = l+r>>1;
		if (T2.queryv(K-1, 0, n+1, rt[m])<=L-1) l = m+1;
		else r = m-1;
	}
	pt0 = l;
	l = pt0, r = R;
	while (l<=r)
	{
		int m = l+r>>1;
		if (T2.queryv(K, 0, n+1, rt[m])<=L-1) l = m+1;
		else r = m-1;
	}
	pt1 = l;
	ll ret = queryhsum(pt0, R, K-1);
	ret -= 1ll*(L-1)*(pt1-pt0);
	ret -= queryhsum(pt1, R, K);
	return ret;
}
int main()
{
	geti(n);
	T.init(n+1);
	ll lans = 0;
	for (int i=1; i<=n; i++)
	{
		int v, l, r, k;
		getii(v, l);
		getii(r, k);
		v = (v+lans)%(n+1);
		l = (l+lans)%i+1;
		r = (r+lans)%i+1;
		if (l>r) swap(l, r);
		k = (k+lans)%(n+1);
//		cerr<<v<<" "<<l<<","<<r<<" "<<k<<endl;
		k++; v++;
		rt[i] = T2.newnode(rt[i-1]);
		modify(0, i, i);
		modify(v, i, i);
		lans = query(l, r, k);
		putsi(lans);
		assert(lans>=0);
	}
	return 0;
}