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
const int maxn = 200111;
int n, m, q;
int p[maxn], pos[maxn];
int a[maxn], nxt[maxn];
int lst[maxn];
int go[20][maxn];
int tor[maxn];

int main()
{
	getiii(n, m, q);
	for (int i=1; i<=n; i++)
	{
		geti(p[i]);
		pos[p[i]] = i;
	}
	for (int i=1; i<=m; i++)
	{
		geti(a[i]);
		a[i] = pos[a[i]];
	}
	for (int i=m; i>=1; i--)
	{
		int na = a[i]%n+1;
		nxt[i] = lst[na];
		lst[a[i]] = i;
	}
	for (int i=m; i>=1; i--)
	{
		go[0][i] = nxt[i];
		for (int j=1; j<20; j++) go[j][i] = go[j-1][go[j-1][i]];
	}
	for (int i=m; i>=1; i--)
	{
		int x = i;
		for (int j=0; j<20; j++)
		{
			if (((n-1)>>j)&1)
			{
				x = go[j][x];
			}
		}
		if (x>0) tor[i] = x; else tor[i] = m+1;
	}
//	for (int i=1; i<=m; i++) cerr<<tor[i]<<" "; cerr<<endl;
	for (int i=m-1; i>=1; i--) tor[i] = min(tor[i+1], tor[i]);
	for (int i=1; i<=q; i++)
	{
		int l, r;
		getii(l, r);
		bool ok = tor[l]<=r;
		putchar('0'+ok);
	}
	return 0;
}