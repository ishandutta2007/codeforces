//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
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
ll qpow(ll x,ll k){return k==0?1:qpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,k;
ll ifac[1000111],fac[1000111],dp[1000111];
ll C(int x,int y){return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
int main()
{
	fac[0]=1;
	for(int i=1;i<=1000005;i++)fac[i]=fac[i-1]*i%mod;
	ifac[1000005]=qpow(fac[1000005],mod-2);
	for(int i=1000004;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	dp[0]=1;
	ll sum=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		dp[i]=sum*fac[i-1]%mod;
		sum=(sum+dp[i]*ifac[i])%mod;
		if(i-k>=0)
		{
			sum=(sum-dp[i-k]*ifac[i-k]%mod+mod)%mod;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[i-1]*1*C(n-1,i-1)%mod*fac[n-i]%mod)%mod;
	}
	cout<<(fac[n]-ans+mod)%mod<<endl;
	return 0;
}