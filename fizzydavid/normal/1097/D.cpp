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
ll n, m, inv[101];
ll solve(ll p, int k)
{
	ll dp[70] = {}, ndp[70];
	dp[k] = 1;
	for (int i=0; i<m; i++)
	{
		memset(ndp, 0, sizeof(ndp));
		for (int j=0; j<=k; j++)
		{
			for (int t=0; t<=j; t++)
			{
				ndp[t] = (ndp[t]+dp[j]*inv[j+1])%mod;
			}
		}
		swap(dp, ndp);
	}
	ll ret = 0, pw = 1;
	p %= mod;
	for (int i=0; i<=k; i++)
	{
		ret = (ret+dp[i]*pw)%mod;
		pw = pw*p%mod;
	}
	return ret;
}
int main()
{
	for (int i=1; i<=100; i++) inv[i] = qpow(i, mod-2);
	cin>>n>>m;
	ll ans = 1;
	for (ll i=2; i*i<=n; i++)
	{
		if (n%i==0)
		{
			int cnt = 0;
			while (n%i==0)
			{
				n /= i;
				cnt++;
			}
			ans = ans*solve(i, cnt)%mod;
		}
	}
	if (n>1) ans = ans*solve(n, 1)%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}