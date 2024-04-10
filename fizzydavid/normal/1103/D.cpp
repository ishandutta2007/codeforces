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
const int maxn = 1000111;
const int maxm = 11;
void upd(ll &x, ll v)
{
	x = v<x?v:x;
}
int n, m;
ll K;
pair<ll,ll> a[maxn];
vector<ll> pr;
vector<ll> fact(ll x)
{
	vector<ll> ret;
	for (ll i=2; 1ll*i*i<=x; i++)
	{
		if (x%i==0)
		{
			while (x%i==0) x/=i;
			ret.PB(i);
		}
	}
	if (x>1) ret.PB(x);
	return ret;
}
ll c[maxn][maxm];
set<int> st;
int tabcnt[1<<maxm];
ll tab[1<<maxm];
ll dp[maxm+1][1<<maxm];
void add_number(ll c[], ll cost)
{
	vector<int> v;
	vector<int> del;
	for (auto i : st)
	{
		ll p = 1;
		for (int j=0; j<m; j++)
		{
			if ((i>>j)&1)
			{
				p = p*c[j];
			}
		}
		if (p<=K)
		{
			v.PB(i);
			tabcnt[i]++;
			if (tabcnt[i]==m)
			{
				del.PB(i);
			}
		}
	}
	for (auto x : del) st.erase(x);
	
	for (int i=m-1; i>=0; i--)
	{
		for (auto x : v)
		{
			int msk = (1<<m)-1-x;
			int m = msk;
			while (true)
			{
				upd(dp[i+1][m|x], dp[i][m]+cost);
				if (m==0) break;
				m = (m-1)&msk;
			}
		}
	}
}
map<ll, ll> cnt;
int main()
{
	getii(n, K);
	ll g = 0;
	for (int i=1; i<=n; i++)
	{
		ll x;
		geti(x);
		a[i].SS = x;
		g = __gcd(g, x);
	}
	for (int i=1; i<=n; i++) geti(a[i].FF);
	pr = fact(g);
	m = pr.size();
	assert(m<=maxm);
	memset(tab, 20, sizeof(tab));
	sort(a+1, a+n+1);
	
	memset(dp, 20, sizeof(dp));
	ll inf = dp[0][0];
	dp[0][0] = 0;
	for (int i=0; i<(1<<m); i++) st.insert(i);
	
	for (int i=1; i<=n; i++)
	{
		ll tmp = 1;
		for (int j=0; j<m; j++)
		{
			ll x = a[i].SS;
			c[i][j] = 1;
			while (x%pr[j]==0)
			{
				x /= pr[j];
				c[i][j] *= pr[j];
				tmp *= pr[j];
			}
		}
		a[i].SS = tmp;
		cnt[a[i].SS]++;
		if (cnt[a[i].SS]<=m+1)
		{
			add_number(c[i], a[i].FF);
		}
	}
	
	
	ll ans = inf;
	for (int i=0; i<=m; i++) if (dp[i][(1<<m)-1]<inf) upd(ans, dp[i][(1<<m)-1]*i);
	if (ans>=1e16) puts("-1");
	else cout<<ans<<endl;
	return 0;
}