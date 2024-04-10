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
int n;
vector<pair<ll, ll> > v;
vector<pair<ll, ll> > a;
bool above(pair<ll,ll> x, pair<ll,ll> y, pair<ll,ll> z)
{
	assert(x.FF!=y.FF);
	ll C0 = x.SS-x.FF*x.FF;
	ll C1 = y.SS-y.FF*y.FF;
	ll K0 = x.FF;
	ll K1 = y.FF;
	ll P = C0-C1;
	ll Q = K0-K1;
	//b = P/Q;
	if (Q<0) P = -P, Q = -Q;
	ll b = P;
	ll c = C0*Q-K0*b;
	ll dlt = Q*z.SS-Q*z.FF*z.FF-b*z.FF-c;
//	cerr<<"dlt="<<dlt<<endl;
	return dlt>=0;
}
int main()
{
	geti(n);
	for (int i=1; i<=n; i++)
	{
		ll x, y;
		getii(x, y);
		v.PB(MP(x, y));
	}
	sort(v.begin(), v.end());
	for (auto p : v)
	{
		if (a.size()>0&&a.back().FF==p.FF)
		{
			a.pop_back();
		}
		while (a.size()>=2&&above(a[a.size()-2], a[a.size()-1], p)) a.pop_back();
		a.PB(p);
	}
	putsi(a.size()-1);
	return 0;
}