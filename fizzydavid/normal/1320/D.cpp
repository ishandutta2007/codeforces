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
int BS = 100000;
char s[200111];
int n;
int pw[1<<20];
int go[20][200111];
int hs[20][200111];
int query(int x, int len)
{
	int ret = 0;
	for (int i=19; i>=0; i--)
	{
		if (go[i][x]-x<=len)
		{
			len -= go[i][x]-x;
			ret = (1ll*ret*pw[1<<i]+hs[i][x])%mod;
			x = go[i][x];
		}
	}
//	cerr<<"x="<<x<<" len="<<len<<endl;
	if (len>0)
	{
		if (len&1)
		{
			ret = (1ll*ret*BS+'1')%mod;
		}
	}
//	cerr<<"ret="<<ret<<endl;
	return ret;
}
int main()
{
	srand((unsigned long long)new char);
	BS += rand()%100000;
	pw[0] = 1;
	for (int i=1; i<(1<<20); i++) pw[i] = 1ll*pw[i-1]*BS%mod;

	scanf("%d", &n);
	scanf("%s", s+1);
	go[0][n+1] = n+2;
	go[0][n+2] = n+2;
	for (int i=n; i>=1; i--)
	{
		if (s[i]=='0')
		{
			go[0][i] = i+1;
			hs[0][i] = s[i];
		}
		else
		{
			if (s[i+1]=='1')
			{
				go[0][i] = go[0][i+2];
				hs[0][i] = hs[0][i+2];
			}
			else
			{
				go[0][i] = i+1;
				hs[0][i] = s[i];
			}
		}
		assert(go[0][i]>0);
	}
	for (int i=1; i<20; i++)
	{
		for (int j=1; j<=n+2; j++)
		{
			go[i][j] = go[i-1][go[i-1][j]];
			hs[i][j] = (1ll*hs[i-1][j]*pw[1<<(i-1)]+hs[i-1][go[i-1][j]])%mod;
		}
	}

	int q;
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		int x, y, len;
		scanf("%d%d%d", &x, &y, &len);
		int xl = query(x, len);
		int yl = query(y, len);
		if (xl==yl) puts("YES"); else puts("NO");
	}
	return 0;
}