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
int n, m;
int a[1000111];
int dp[2][9][9];
void upd(int &x, int v)
{
	x = min(x, v);
}
int main()
{
	getii(n, m);
	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		int x;
		geti(x);
		a[x]++;
	}
	int tot = 0;
	for (int i=1; i<=m; i++)
	{
		while (a[i]>=9) a[i] -= 3, ans++;
		tot += a[i];
	}
	memset(dp, 20, sizeof(dp));
	int p = 1;
	dp[p][a[1]][a[2]] = 0;
	int inf = dp[0][0][0];
	for (int i=1; i<=m; i++)
	{
		int np = p^1;
		memset(dp[np], 20, sizeof(dp[np]));
		for (int x=0; x<9; x++)
		{
			for (int y=0; y<9; y++)
			{
				int &cur = dp[p][x][y];
				if (cur==inf) continue;
				for (int z=0; z<=2&&z<=x&&z<=y&&z<=a[i+2]; z++)
				{
					upd(dp[np][y-z][a[i+2]-z], cur+(x-z)%3);
				}
			}
		}
		p = np;
	}
	assert((tot-dp[p][0][0])%3==0);
	cout<<ans+(tot-dp[p][0][0])/3<<endl;
	return 0;
}