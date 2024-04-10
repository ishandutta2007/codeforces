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
const int maxn = 11011;
const int maxm = 6011;
const int maxc = 211;
int head[maxn], deg[maxn], nxt[maxm*2], to[maxm*2], tot=1;
vector<pair<int,int> > con[maxn];
void add_edge(int x, int y, int id)
{
	nxt[++tot] = head[x];
	head[x] = tot;
	to[tot] = y;
	deg[x]++;
	swap(x, y);
	nxt[++tot] = head[x];
	head[x] = tot;
	to[tot] = y;
	deg[x]++;
}
int match[maxn][maxc];
int n, n1, n2, m, k;
int ans[maxm], lst[maxn];
int find_color(int x)
{
	for (int i=1; i<=k; i++) if (!match[x][i]) return i;
	assert(false);
}
void aug(int e, int c, int pc)
{
	int x = to[e^1], y = to[e];
	if (match[y][c]) aug(match[y][c], pc, c); else match[y][pc] = 0;
	match[x][c] = e;
	match[y][c] = e^1;
	ans[e>>1] = c;
}
void solve()
{
	for (int x=1; x<=n; x++)
	{
		for (int e = head[x]; e; e=nxt[e])
		{
			int y = to[e];
			if (ans[e>>1]) continue;
			int c = find_color(x);
			int pc = find_color(y);
			aug(e, c, pc);
		}
	}
}
int main()
{
	getii(n1, n2);
	getii(m, k);
	n = n1+n2;
	for (int i=1; i<=n; i++) lst[i] = i;
	for (int i=1; i<=m; i++)
	{
		int x, y;
		getii(x, y);
		y += n1;
		add_edge(lst[x], lst[y], i);
		if (deg[lst[x]]>=k) lst[x] = ++n;
		if (deg[lst[y]]>=k) lst[y] = ++n;
	}
	solve();
	int cnt = 0;
	for (int i=1; i<=n1+n2; i++) cnt += deg[lst[i]]>0;
	putsi(cnt);
	for (int i=1; i<=m; i++) puti(ans[i]);
	return 0;
}