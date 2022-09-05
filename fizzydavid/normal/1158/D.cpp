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
const int maxn = 2011;
typedef pair<int,int> point;
int n;
point a[maxn];
point operator - (const point &a, const point &b) {return point(a.FF-b.FF, a.SS-b.SS);}
ll operator * (const point &a, const point &b) {return 1ll*a.FF*b.SS-1ll*a.SS*b.FF;}
char s[maxn];
bool vis[maxn];
int get_next(int p, int coef)
{
	int q = -1;
	for (int i=1; i<=n; i++)
	{
		if (vis[i]) continue;
		if (q==-1) q = i;
		else
		{
			if (((a[i]-a[p])*(a[q]-a[p]))*coef>0)
			{
				q = i;
			}
		}
	}
	return q;
}
int main()
{
	geti(n);
	int S = 1;
	for (int i=1; i<=n; i++)
	{
		getii(a[i].FF, a[i].SS);
		if (a[i]<a[S]) S = i;
	}
	int p = S;
	puti(p);
	vis[p] = true;
	for (int i=1; i<=n-2; i++)
	{
		s[i] = getreal();
		p = get_next(p, s[i]=='L'?1:-1);
		puti(p);
		vis[p] = true;
	}
	for (int i=1; i<=n; i++) if (!vis[i]) puti(i);
	
	return 0;
}