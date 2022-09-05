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
const int maxn = 311;
int dp[maxn][maxn]; //dp[i][j] i j0~j 
int tab[maxn][maxn][maxn]; //tab[l][r][x] [l,r] [x, y] y 
int n, m;
vector<int> v;
int pos[maxn], pl[maxn], pr[maxn];
int getid(int x) {return lower_bound(v.begin(), v.end(), x)-v.begin();}
void upd(int &x, int v) {x=max(x, v);}
int mx[maxn][maxn];
void prework()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=n; j++)
		{
			mx[i][j] = max(mx[i][j-1], pr[j]);
		}
	}
	for (int l=1; l<=n; l++)
	{
		for (int x=0; x<=m; x++) tab[l][l-1][x] = x;
		for (int r=l; r<=n; r++)
		{
			for (int x=0; x<m; x++)
			{
				int &cur = tab[l][r-1][x];
				for (int t=r; t<=n; t++)
				{
					if (pl[t]<=cur)
					{
						upd(tab[l][t][x], max(cur, max(pos[t], mx[r][t-1])));
					}
				}
				if (pos[r]<=cur) upd(tab[l][r][x], max(cur, pr[r]));
			}
		}
	}
}
int solve()
{
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<m; j++)
		{
			int &cur = dp[i][j];
			upd(dp[i+1][j], cur);
			upd(dp[i][j+1], cur);
			for (int r=i+1; r<=n; r++)
			{
				int tr = tab[i+1][r][j];
				upd(dp[r][tr], cur+v[tr]-v[j]);
			}
		}
	}
	return dp[n][m-1];
}
pair<int,int> a[maxn];
int main()
{
	geti(n);
	for (int i=1; i<=n; i++)
	{
		int x, y;
		getii(x, y);
		a[i] = MP(x, y);
	}
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++)
	{
		int x = a[i].FF, y = a[i].SS;
		pos[i] = x;
		pl[i] = x-y;
		pr[i] = x+y;
		v.PB(x);
		v.PB(x-y);
		v.PB(x+y);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	m = v.size();
	for (int i=1; i<=n; i++)
	{
		pos[i] = getid(pos[i]);
		pl[i] = getid(pl[i]);
		pr[i] = getid(pr[i]);
	}
	prework();
	cout<<solve()<<endl;
	return 0;
}