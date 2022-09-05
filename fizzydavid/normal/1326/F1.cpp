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

const int mod = 1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}


int n;
char adj[18][18];
vector<ll> dp[1<<14][14];
void upd(int &x, int v)
{
	x += v;
}
ll ans[1<<14];
int main()
{
	cin>>n;
	for (int i=0; i<n; i++) cin>>adj[i];
	for (int i=1; i<(1<<n); i++)
	{
		int cnt = __builtin_popcount(i);
		for (int j=0; j<n; j++)
		{
			if ((i>>j)&1)
			{
				assert(cnt>0);
				dp[i][j].resize(1<<cnt-1);
			}
		}
	}
	for (int i=0; i<n; i++) dp[1<<i][i][0] = 1;
	for (int i=1; i<(1<<n); i++)
	{
		int cnt = __builtin_popcount(i);
		for (int j=0; j<n; j++)
		{
			if ((i>>j)&1)
			{
				for (int k=0; k<n; k++)
				{
					if (!((i>>k)&1))
					{
						char c = adj[j][k];
						for (int t=0; t<(1<<cnt-1); t++)
						{
							ll &v = dp[i][j][t];
							if (v)
							{
								dp[i|1<<k][k][t+(c=='1')*(1<<cnt-1)] += v;
							}
						}
					} 
				}
				if (cnt==n)
				{
					for (int t=0; t<(1<<n-1); t++) ans[t] += dp[i][j][t];
				}
			}
		}
	}
	for (int i=0; i<(1<<n-1); i++) puti(ans[i]);
	return 0;
}