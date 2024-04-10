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

const int maxn = 2e6;
const int mod = 1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
struct node
{
	ll mx, lz;
}a[maxn];
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
int query(int x, int y, int l, int r, int p)
{
	if (x<=l&&r<=y) return a[p].mx;
	pushdown(p);
	int m = l+r>>1;
	if (x<=m&&m<y) return max(query(x, y, l, m, ls), query(x, y, m+1, r, rs));
	else if (x<=m) return query(x, y, l, m, ls);
	else return query(x, y, m+1, r, rs);
}
int n, m, k;
int p[maxn], q[maxn];
bool check(int mx)
{
	return -query(p[mx], n, 1, n, 1)>min(0, -query(1, p[mx], 1, n, 1));
}
void add(int x)
{
	add(p[x], n, -1, 1, n, 1);
}
void del(int x)
{
	add(x, n, 1, 1, n, 1);
}
int main()
{
	geti(n);
	for (int i=1; i<=n; i++)
	{
		int x;
		geti(x);
		p[x] = i;
	}
	for (int i=1; i<=n; i++) geti(q[i]);
	int mx = n; add(mx);
	for (int i=1; i<=n; i++)
	{
		while (!check(mx)) mx--, add(mx);
		puti(mx);
		del(q[i]);
	}
	return 0;
}