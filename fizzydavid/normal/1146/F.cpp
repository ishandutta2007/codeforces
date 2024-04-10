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
const int mod = 998244353;
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
int dp[3][maxn];
vector<int> son[maxn];
void upd(int &x, int v) {x=(x+v)%mod;}
void dfs(int x)
{
	if (son[x].size()==0)
	{
		dp[0][x] = dp[1][x] = dp[2][x] = 1;
	}
	else
	{
		for (auto u : son[x])
		{
			dfs(u);
		}
		int f[3] = {}, nf[3] = {};
		f[0] = 1;
		for (auto u : son[x])
		{
			int in = dp[1][u], out = ((dp[0][u]-dp[1][u])%mod+dp[2][u])%mod;
			memset(nf, 0, sizeof(nf));
			for (int i=0; i<3; i++)
			{
				upd(nf[i], 1ll*f[i]*out%mod);
				upd(nf[min(2, i+1)], 1ll*f[i]*in%mod);
			}
			swap(f, nf);
		}
		upd(f[1], f[2]);
		upd(f[0], f[1]);
		dp[0][x] = f[0];
		dp[1][x] = f[1];
		dp[2][x] = f[2];
	}
}
int main()
{
	geti(n);
	for (int i=2; i<=n; i++)
	{
		int p;
		geti(p);
		son[p].PB(i);
	}
	dfs(1);
	int ans = ((dp[0][1]-dp[1][1])%mod+dp[2][1])%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}