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
const int maxn = 5000111;
int head[maxn], to[maxn], nxt[maxn], tot=1;
int n, m, d, w[maxn];
void add_edge(int x, int y)
{
	nxt[++tot] = head[x];
	head[x] = tot;
	to[tot] = y;
}
int dtot, dfn[maxn], low[maxn], g[maxn], gtot, st[maxn], stn;
int nhead[maxn], nto[maxn], nnxt[maxn], ntot=1, nw[maxn];
void nadd_edge(int x, int y)
{
//	cerr<<"nadd_edge:"<<x<<","<<y<<endl;
	nnxt[++ntot] = nhead[x];
	nhead[x] = ntot;
	nto[ntot] = y;
}

bool hs[maxn];
vector<int> tmp;
void tarjan(int x)
{
	dfn[x] = low[x] = ++dtot; st[stn++] = x;
	for (int i=head[x]; i; i=nxt[i])
	{
		int u = to[i];
		if (!dfn[u]) tarjan(u), low[x] = min(low[x], low[u]);
		else if (!g[u]) low[x] = min(low[x], dfn[u]);
	}
	if (low[x]==dfn[x])
	{
		gtot++;
		tmp.clear();
		while (true)
		{
			int u = st[--stn];
			g[u] = gtot;
			if (w[u])
			{
				if (!hs[u%n])
				{
					nw[gtot]++;
					hs[u%n] = 1;
					tmp.PB(u%n);
				}
			}
			if (u==x) break;
		}
		for (auto x : tmp) hs[x] = 0;
	}
}
int dp[maxn];
int dfs(int x)
{
	if (dp[x]!=-1) return dp[x];
//	cerr<<"dfs:"<<x<<endl;
	dp[x] = 0;
	for (int i=nhead[x]; i; i=nnxt[i]) dp[x] = max(dp[x], dfs(nto[i]));
	dp[x] += nw[x];
	return dp[x];
}
int main()
{
	getiii(n, m, d);
	for (int i=1; i<=m; i++)
	{
		int x, y;
		getii(x, y);
		for (int j=0; j<d; j++) add_edge(j*n+x, ((j+1)%d)*n+y);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<d; j++)
		{
			char c = getreal();
			w[j*n+i] = c-'0';
		}
	}
	tarjan(1);
//	for (int i=1; i<=n*d; i++) cerr<<g[i]<<" "; cerr<<endl;
//	for (int i=1; i<=gtot; i++) cerr<<nw[i]<<" "; cerr<<endl;
	for (int i=1; i<=n*d; i++)
	{
		for (int j=head[i]; j; j=nxt[j])
		{
			if (g[i]&&g[to[j]]&&g[i]!=g[to[j]])
			{
				nadd_edge(g[i], g[to[j]]);
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	cout<<dfs(g[1])<<endl;
	return 0;
}