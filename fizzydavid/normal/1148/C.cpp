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
const int maxn = 300111;
int n;
int a[maxn], b[maxn];
vector<pair<int,int> > V;
void exc(int x, int y)
{
	assert(abs(x-y)*2>=n);
	V.PB(MP(x, y));
	swap(a[x], a[y]);
	swap(b[a[x]], b[a[y]]);
}
int main()
{
	geti(n);
	for (int i=1; i<=n; i++)
	{
		geti(a[i]);
		b[a[i]] = i;
	}
	for (int i=n-1; i>n/2; i--)
	{
		if (b[i]>n/2) exc(b[i], 1);
		else exc(b[i], n), exc(n, 1);
		exc(1, i);
	}
	for (int i=n/2; i>=1; i--)
	{
		if (b[i]>n/2) exc(b[i], 1), exc(1, n);
		else exc(b[i], n);
		exc(i, n);
	}
	for (int i=1; i<=n; i++) assert(a[i]==i);
	putsi(V.size());
	for (auto x : V) putsii(x.FF, x.SS);
	return 0;
}