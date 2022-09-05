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
char s[maxn];
int fail[maxn];
int c[2], n;
int main()
{
	scanf("%s", s+1);
	n = strlen(s+1);
	for (int i=1; i<=n; i++) c[s[i]-'0']++;
	scanf("%s", s+1);
	n = strlen(s+1);
	fail[1] = 0;
	for (int i=2; i<=n; i++)
	{
		int &f = fail[i];
		f = fail[i-1];
		while (f&&s[f+1]!=s[i]) f = fail[f];
		if (s[f+1]==s[i]) f++;
	}
	int it = 0;
	while (true)
	{
		while (it&&(it==n||c[s[it+1]-'0']==0)) it = fail[it];
		char ch = s[it+1];
		if (c[ch-'0']>0)
		{
			c[ch-'0']--;
			putchar(ch);
			it++;
		}
		else break;
	}
	while (c[0]--) putchar('0');
	while (c[1]--) putchar('1');
	return 0;
}