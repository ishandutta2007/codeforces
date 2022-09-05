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
int n, K;
vector<int> con[100111];
int dp[100111][205], sz[100111], dps[100111][205];
void upd(int &x, ll v) {x=(x+v)%mod;}
int polymul(int a[], int an, int b[], int bn, int c[])
{
	int cn = min(K, an+bn);
	static int ret[205];
	for (int i=0; i<=cn; i++) ret[i] = 0;
	for (int i=0; i<=an; i++)
	{
		for (int j=0; j<=bn&&i+j<=cn; j++)
		{
			upd(ret[i+j], 1ll*a[i]*b[j]);
		}
	}
	for (int i=0; i<=cn; i++) c[i] = ret[i];
	return cn;
}
int ta[205] = {1, 1}, tmp[205], ans[205];
void dfs(int x, int pre=-1)
{
	sz[x] = 0;
	dp[x][0] = 1;
	for (auto u: con[x])
	{
		if (u==pre) continue;
		dfs(u, x);
		int tsz = polymul(ta, 1, dps[u], sz[u], tmp);
		upd(tmp[0], 1);
		sz[x] = polymul(tmp, tsz, dp[x], sz[x], dp[x]);
		for (int i=0; i<=tsz; i++) upd(ans[i], mod-tmp[i]);
	}
	for (int i=0; i<=sz[x]; i++) upd(ans[i], dp[x][i]);
	for (int i=0; i<=sz[x]; i++) upd(dps[x][i], dp[x][i]*2ll);
	upd(dps[x][0], mod-1);
	for (int i=0; i<=sz[x]; i++) upd(ans[i], dp[x][i]);
}
ll s[211][211], fac[211];
int main()
{
	s[0][0] = 1;
	for (int i=1; i<=200; i++)
	{
		for (int j=1; j<=i; j++)
		{
			s[i][j] = (s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
		}
	}
	fac[0] = 1;
	for (int i=1; i<=200; i++) fac[i] = 1ll*fac[i-1]*i%mod;
	getii(n, K);
	for (int i=1; i<n; i++)
	{
		int x, y;
		getii(x, y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
	ll S = 0;
	for (int i=0; i<=K; i++)
	{
		S = (S+fac[i]*s[K][i]%mod*ans[i]%mod)%mod;
	}
	cout<<(S%mod+mod)%mod<<endl;
	return 0;
}