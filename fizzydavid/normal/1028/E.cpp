//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
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
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn=200111;
int n;
ll a[maxn];
ll b[maxn];
int main()
{
	geti(n);
	for(int i=0;i<n;i++)
	{
		geti(a[i]);
	}
	bool same=1;
	for(int i=0;i<n;i++)same&=a[i]==a[0];
	if(same)
	{
		if(a[0]==0)
		{
			puts("YES");
			for(int i=0;i<n;i++)puti(1);
		}
		else
		{
			puts("NO");
		}
	}
	else
	{
		int it=-1;
		for(int i=0;i<n;i++)
		{
			if(a[i]>0&&a[(i+n-1)%n]<a[i])
			{
				it=i;
				break;
			}
		}
		assert(it!=-1);
		b[it]=a[it];
		for(int i=1;i<n;i++)
		{
			int cur=(it-i+n)%n;
			int nxt=(it-(i-1)+n)%n;
			ll x=b[nxt];
			x=max(1ll,(mod/x))*x;
			b[cur]=x+a[cur];
		}
	  	puts("YES");
		for(int i=0;i<n;i++)puti(b[i]);
		for(int i=0;i<n;i++)assert(b[i]>=1&&b[i]<=1e18&&b[i]%b[(i+1)%n]==a[i]);
    }
	return 0;
}