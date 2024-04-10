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
string tabs[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int n, k;
int tab[10], a[2011];
bool f[2011][2011*7];
int main()
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<7; j++)
		{
			tab[i] += (tabs[i][j]-'0')<<j;
		}
	}
	getii(n, k);
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<7; j++)
		{
			char c;
			c = getreal();
			a[i] += (c-'0')<<j;
		}
	}
	f[n+1][0] = true;
	for (int i=n; i>=1; i--)
	{
		for (int j=9; j>=0; j--)
		{
			if ((tab[j]&a[i])==a[i])
			{
				int c = __builtin_popcount(tab[j]-a[i]);
				for (int t=0; t<=n*7; t++) f[i][t+c] |= f[i+1][t];
			}
		}
	}
	if (f[1][k])
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=9; j>=0; j--)
			{
				if ((tab[j]&a[i])==a[i])
				{
					int c = __builtin_popcount(tab[j]-a[i]);
					if (k>=c&&f[i+1][k-c])
					{
						putchar('0'+j);
						k -= c;
						break;
					}
				}
			}
		}
	}
	else
	{
		puts("-1");
	}
	return 0;
}