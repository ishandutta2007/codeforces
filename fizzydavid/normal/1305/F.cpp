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
const int maxn = 200111;
int n;
ll a[maxn];

vector<ll> fact(ll X)
{
	vector<ll> ret;
	for (ll t = 2; t*t<=X; t++)
	{
		if (X%t==0)
		{
			ret.PB(t);
			while (X%t==0) X/=t;
		}
	}
	if (X>1) ret.PB(X);
	return ret;
}
int main()
{
	srand((unsigned long long)new char);
	geti(n);
	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		geti(a[i]);
		ans += a[i]&1;
	}
	random_shuffle(a+1, a+n+1);
	for (int i=1; i<=50&&i<=n; i++)
	{
		for (ll X=a[i]-1; X<=a[i]+1; X++)
		{
			if (X<=1) continue;
			vector<ll> v = fact(X);
			for (auto x : v)
			{
				ll cur = 0;
				for (int j=1; j<=n; j++)
				{
					if (a[j]<x) cur += x-a[j];
					else cur += min(a[j]%x, x-a[j]%x);
					if (cur>=ans) break;
				}
				if (cur<ans) ans = cur;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}