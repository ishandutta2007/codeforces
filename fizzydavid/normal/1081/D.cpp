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
const int maxn = 100111;
int n, m, k;
vector<pair<int,pair<int,int> > > E;
int f[maxn];
bool sp[maxn];
int gf(int x) {return f[x]==x?x:f[x]=gf(f[x]);}
int main()
{
	getiii(n, m, k);
	for (int i=1; i<=n; i++) f[i] = i;
	for (int i=1; i<=k; i++)
	{
		int x;
		geti(x);
		sp[x] = 1;
	}
	for (int i=1; i<=m; i++)
	{
		int x, y, w;
		getiii(x, y, w);
		E.PB(MP(w,MP(x,y)));
	}
	sort(E.begin(), E.end());
	int ans = 0;
	for (int i=0; i<E.size(); i++)
	{
		int w = E[i].FF;
		int x = E[i].SS.FF;
		int y = E[i].SS.SS;
		if (gf(x)==gf(y)) continue;
		x = gf(x);
		y = gf(y);
		f[x] = y;
		if (sp[y]&&sp[x])
		{
			ans = w;
		}
		sp[y] |= sp[x];
	}
	for (int i=1; i<=k; i++) puti(ans);
	return 0;
}