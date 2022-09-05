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
const int maxn = 500111;
int Tn;
int n, a[maxn], b[maxn], tot;
vector<int> con[maxn];
void dfs(int x)
{
	for (auto u : con[x]) dfs(u);
	a[x] = ++tot;
}
void solve()
{
	geti(n);
	for (int i=1; i<=n+1; i++) con[i].clear();
	for (int i=1; i<=n; i++)
	{
		geti(b[i]);
		if (b[i]==-1) b[i] = i+1;
	}
	for (int i=n; i>=1; i--) con[b[i]].PB(i);
	tot = 0;
	dfs(n+1);
	vector<pair<int,int> > v; v.PB(MP(n+1, n+1));
	bool ok = true;
	for (int i=n; i>=1; i--)
	{
		while (v.back().FF<=a[i]) v.pop_back();
		ok &= v.back().SS==b[i];
		v.PB(MP(a[i], i));
		if (!ok) break;
	}
	if (!ok) puts("-1");
	else
	{
		for (int i=1; i<=n; i++) puti(a[i]); puts("");
	}
}
int main()
{
	geti(Tn);
	while (Tn--)
	{
		solve();
	}
	return 0;
}