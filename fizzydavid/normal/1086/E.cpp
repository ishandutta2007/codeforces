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
const int mod=998244353;
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
const int maxn = 2011;
struct BIT
{
	int a[maxn];
	void add(int x, int v) { for(int i=x; i<maxn; i+=i&(-i)) a[i]+=v;}
	int query(int x)
	{
		if (x<0) return 0;
		int ret = 0;
		for (int i=x; i; i-=i&(-i)) ret+=a[i];
		return ret;
	}
	int query(int l, int r) {return l>r?0:query(r)-query(l-1);}
	void clear()
	{
		memset(a, 0, sizeof(a));
	}
}B, B1, B2;
int n;
ll D[maxn], fac[maxn];
ll dp[maxn][maxn];
int a[maxn][maxn];
ll get_rank(int a[])
{
	B.clear();
	ll ret = 0;
	for (int i=1; i<=n; i++) B.add(i, 1);
	for (int i=1; i<=n; i++)
	{
		B.add(a[i], -1);
		ret += B.query(a[i])*fac[n-i]%mod;
	}
	return ret%mod;
}
bool hs[maxn];
int cnt;
void delres(int x, int y, bool flag)
{
	if (hs[x])
	{
		if (flag==0) B2.add(y, -1);
		return;
	}
	B1.add(y, -1);
	if (flag) B2.add(y, 1);
	cnt--;
	hs[x] = 1;
}
ll get_rank(int b[], int a[])
{
	B1.clear();
	B2.clear();
	cnt = n;
	static int pos[maxn];
	for (int i=1; i<=n; i++) pos[b[i]] = i;
	for (int i=1; i<=n; i++) B1.add(i, 1);
	memset(hs, 0, sizeof(hs));
	ll ret = 0;
	for (int i=1; i<=n; i++)
	{
		ll cnt1, cnt2;
		if (hs[i])
		{
			cnt1 = B2.query(a[i]-1);
			cnt2 = B1.query(a[i]-1);
			ret = (ret+cnt1*dp[n-i][cnt]+cnt2*dp[n-i][cnt-1])%mod;
		}
		else
		{
			cnt1 = B2.query(a[i]-1);
			cnt2 = B1.query(a[i]-1);
			if (b[i]<a[i]) cnt2--;
			ret = (ret+cnt1*dp[n-i][cnt-1]+cnt2*dp[n-i][cnt-2])%mod;
		}
//		cerr<<"cnt1="<<cnt1<<" cnt2="<<cnt2<<endl;
		delres(i, b[i], 1);
		delres(pos[a[i]], a[i], 0);
//		for (int j=1; j<=n; j++) cerr<<B1.query(j,j)<<" ";cerr<<endl;
//		for (int j=1; j<=n; j++) cerr<<B2.query(j,j)<<" ";cerr<<endl;
		
	}
//	cerr<<"ret="<<ret<<endl;
	return ret;
}
int main()
{
	geti(n);
	fac[0] = 1;
	for (int i=1; i<=n; i++) fac[i] = fac[i-1]*i%mod;
	D[1] = 0;
	for (int i=2; i<=n; i++)
	{
		D[i] = D[i-1]*i%mod;
		if (i&1) D[i] = (D[i]-1)%mod;
		else D[i] = (D[i]+1)%mod;
	}
	dp[0][0] = 1;
	dp[1][0] = 1;
	for (int i=2; i<=n; i++)
	{
		dp[i][0] = fac[i];
		for (int j=1; j<=i; j++)
		{
			if (i>j) dp[i][j] = (1ll*(i-j)*dp[i-1][j]+1ll*j*dp[i-1][j-1])%mod;
			else dp[i][j] = 1ll*(i-1)*dp[i-1][j-2]%mod;
		}
	}
//	for (int i=1; i<=n; i++) cerr<<D[i]<<" "; cerr<<endl;
//	for (int i=1; i<=n; i++) cerr<<dp[i][i]<<" "; cerr<<endl;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			geti(a[i][j]);
		}
	}
	ll ans = get_rank(a[1])*qpow(D[n], n-1)%mod;
	for (int i=2; i<=n; i++)
	{
//		cerr<<"ans="<<ans<<endl;
		ans += get_rank(a[i-1], a[i])*qpow(D[n], n-i)%mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}