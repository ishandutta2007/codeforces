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
int n, m;
ll A, B;
vector<pair<int,int> > con[77];
int id[77], tot, gid[77], gtot;
bool vis[77];
vector<int> v;
void dfs(int x)
{
	vis[x] = true; v.PB(x);
	for (auto e : con[x])
	{
		if (!vis[e.FF]&&e.SS==A)
		{
			dfs(e.FF);
		}
	}
}
int dis[77][77], dp[1<<17][77], ans[77];
void upd(int &x, int v) {x = min(x, v);}
int main()
{
	getii(n, m);
	getii(A, B);
	memset(dis, 63, sizeof(dis));
	for (int i=0; i<=n; i++) dis[i][i] = 0;
	for (int i=1; i<=m; i++)
	{
		int x, y;
		ll w;
		getiii(x, y, w);
		con[x].PB(MP(y, w));
		con[y].PB(MP(x, w));
	}
	for (int i=1; i<=n; i++)
	{
		if (!vis[i])
		{
			v.clear();
			dfs(i);
			int g = v.size()>=4?tot++:-1;
			gtot++;
			for (auto x : v) id[x] = g, gid[x] = gtot;
		}
	}
	
	for (int i=1; i<=n; i++) for (auto e : con[i]) if (gid[i]!=gid[e.FF]&&id[e.FF]==-1||gid[i]==gid[e.FF]&&e.SS==A)
	{
		dis[i][e.FF] = e.SS;
	}
	for (int k=1; k<=n; k++) for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	
	memset(dp, 63, sizeof(dp));
	int inf = dp[0][0];
	if (id[1]!=-1) dp[1<<id[1]][1] = 0; else dp[0][1] = 0;
	memset(ans, 63, sizeof(ans));
	for (int msk=0; msk<(1<<tot); msk++)
	{
		for (int x=1; x<=n; x++)
		{
			if (dp[msk][x]==inf) continue;
			for (int y=1; y<=n; y++)
			{
				upd(dp[msk][y], dp[msk][x]+dis[x][y]);
			}
		}
		for (int x=1; x<=n; x++)
		{
			if (dp[msk][x]==inf) continue;
			for (auto e : con[x])
			{
				int u = e.FF;
				if (id[u]!=-1&&!((msk>>id[u])&1)) upd(dp[msk|(1<<id[u])][u], dp[msk][x]+e.SS);
			}
			upd(ans[x], dp[msk][x]);
		}
	}
	for (int i=1; i<=n; i++) puti(ans[i]);
	return 0;
}