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
struct node
{
	ll mx, lz;
}a[4000111];
#define ls p<<1
#define rs p<<1|1
void update(int p)
{
	a[p].mx = max(a[ls].mx, a[rs].mx);
}
void pushdown(int p)
{
	if (a[p].lz)
	{
		a[ls].mx += a[p].lz;
		a[ls].lz += a[p].lz;
		a[rs].mx += a[p].lz;
		a[rs].lz += a[p].lz;
		a[p].lz = 0;
	}
}
void add(int x, int y, ll v, int l, int r, int p)
{
	if (x<=l&&r<=y)
	{
		a[p].mx += v;
		a[p].lz += v;
		return;
	}
	pushdown(p);
	int m = l+r>>1;
	if (x<=m) add(x, y, v, l, m, ls);
	if (m<y) add(x, y, v, m+1, r, rs);
	update(p);
}
int n, m, k;
const int M = 1000001;
int v1[1000111];
int v2[1000111];
vector<pair<int,int> > qv[1000111];
int main()
{
	getiii(n, m, k);
	for (int i=1; i<=M; i++) v1[i] = v2[i] = -1e17;
	for (int i=1; i<=n; i++)
	{
		int x, y;
		getii(x, y);
		v1[x] = max(v1[x], -y);
	}
	for (int i=1; i<=m; i++)
	{
		int x, y;
		getii(x, y);
		v2[x] = max(v2[x], -y);
	}
	for (int i=1; i<=M; i++) add(i, i, v2[i], 1, M, 1);
	for (int i=1; i<=k; i++)
	{
		int x, y, c;
		getiii(x, y, c);
		qv[x].PB(MP(y, c));
	}
	ll ans = -1e17;
	for (int i=1; i<=M; i++)
	{
		ans = max(ans, v1[i]+a[1].mx);
		for (auto x : qv[i])
		{
			add(x.FF+1, M, x.SS, 1, M, 1);
		}
	}
	cout<<ans<<endl;
	return 0;
}