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
const int mod = 998244353;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxm = 100111;
const int maxn = 20;
int m, n;
void FWT(ll a[], int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<(1<<n); j++)
		{
			if ((j>>i)&1) continue;
			ll tmp = a[j];
			a[j] = (a[j]+a[j+(1<<i)])%mod;
			a[j+(1<<i)] = (tmp-a[j+(1<<i)])%mod;
		}
	}
}
ll X, Y, Z;
ll a[1<<maxn], b[1<<maxn];
int main()
{
	getii(m, n);
	getiii(X, Y, Z);
	for (int i=0; i<m; i++)
	{
		int A, B, C;
		getiii(A, B, C);
		for (int j=0; j<(1<<3); j++)
		{
			ll msk = 0;
			if (j&1) msk ^= A;
			if ((j>>1)&1) msk ^= B;
			if ((j>>2)&1) msk ^= C;
			a[msk<<3|j]++;
		}
	}
	FWT(a, n+3);
	for (int i=0; i<(1<<n); i++)
	{
		ll ans = 1;
		for (int j=0; j<(1<<3); j++)
		{
			ll v = 0;
			if (j&1) v -= X; else v += X;
			if ((j>>1)&1) v -= Y; else v += Y;
			if ((j>>2)&1) v -= Z; else v += Z;
			ans = ans*qpow(v, a[i<<3|j]/8)%mod;
		}
		b[i] = ans;
	}
	FWT(b, n);
	for (int i=0; i<(1<<n); i++) puti((1ll*b[i]*qpow(2, mod-1-n)%mod+mod)%mod);
	return 0;
}