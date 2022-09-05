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
int Tn;
ll n;
ll getnum(ll x)
{
	ll ret = 0;
	for (int i=0; i<60; i++)
	{
		ll b = 1ll<<(i-i%2);
		int j = (x%(b*4))/b;
		int c;
		if (i%2==0) c = j>=2;
		else c = j>=1&&j<=2;
		ret |= ((ll)c)<<i;
	}
	return ret;
}
ll solve(int id, ll x)
{
	x--;
	ll i = x/3;
	int j = x%3;
//	cerr<<"solve:"<<id<<" "<<i<<" "<<j<<endl;
	ll a = (1ll<<(id+id))+i;
	ll b = (1ll<<(id+id+1))+getnum(i);
	ll c = a^b;
	if (j==0) return a;
	if (j==1) return b;
	if (j==2) return c;
}
int main()
{
	geti(Tn);
	while (Tn--)
	{
		geti(n);
		for (int i=0; ;i++)
		{
			ll tot = 1ll<<(i+i);
			if (n>3*tot) n -= 3*tot;
			else
			{
				putsi(solve(i, n));
				break;
			}
		} 
	}
	return 0;
}
/*
7
10
100
123
1234
1234123
1235134523
123412341234
*/