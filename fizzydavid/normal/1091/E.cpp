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
const int mod=1e9+7;
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
int n;
ll sum;
ll a[maxn];
ll ia[maxn];
struct SGT
{
	struct node
	{
		ll mn, lz;
		void addlz(ll Lz)
		{
			lz += Lz;
			mn += Lz;
		}
	}a[maxn*4];
	#define ls p<<1
	#define rs p<<1|1
	void update(int p)
	{
		a[p].mn = min(a[ls].mn, a[rs].mn);
	}
	void pushdown(int p)
	{
		if (a[p].lz)
		{
			a[ls].addlz(a[p].lz);
			a[rs].addlz(a[p].lz);
			a[p].lz=0;
		}
	}
	void build(int l, int r, int p)
	{
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
	void add(int x, int y, ll v, int l, int r, int p)
	{
		if (y<l||r<x) return;
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
}sgt;
vector<int> ans;
int cur;
void add(int x)
{
//	cerr<<"add:"<<x<<endl;
	sgt.add(x, n, -1, 1, n, 1);
	sgt.add(a[x]+1, x-1, 1, 1, n, 1);
	a[x]++;
	cur++;
}
void check()
{
	if ((cur+sum)%2==0)
	{
//		cerr<<"mn="<<sgt.a[1].mn<<endl;
		if (sgt.a[1].mn>=0) ans.PB(cur);
	}
}
void precalc()
{
	static ll ssum[maxn];
	for (int i=n; i>=1; i--) ssum[i] = ssum[i+1]+a[i];
	for (int i=1; i<=n; i++)
	{
		ia[i] = ia[i-1]-a[i];
	}
	int it = 1;
	for (int i=n; i>=1; i--)
	{
		while (a[it]>i) it++;
		ll cur = 0;
		if (it<=i) cur = ssum[i+1];
		else cur = ssum[it]+1ll*(it-i-1)*i;
		ia[i] += cur+1ll*i*(i-1);
	}
	/*
	for (int i=1; i<=n; i++)
	{
		cerr<<ia[i]<<" ";
	}cerr<<endl;
	for (int i=1; i<=n; i++)
	{
		ll c = 0;
		for (int j=1; j<=i; j++) c -= a[j];
		for (int j=i+1; j<=n; j++) c += min(a[j], i);
		c += 1ll*i*(i-1);
		cerr<<c<<" ";
	}cerr<<endl;
	*/
	sgt.build(1, n, 1);
}
int main()
{
	geti(n);
	for (int i=1; i<=n; i++)
	{
		geti(a[i]);
		sum += a[i];
	}
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	n++;
//	for (int i=1; i<=n; i++) cerr<<a[i]<<" "; cerr<<endl;
	precalc();
	check();
	a[0] = n-1;
	for (int i=n; i>=1; i--)
	{
		while (a[i]<a[i-1])
		{
			add(i);
			check();
		}
	}
	if (!ans.size()) puts("-1");
	else for (auto x:ans) puti(x);
	return 0;
}