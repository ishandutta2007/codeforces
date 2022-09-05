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
ll K;
ll t[5011];
ll fac[5011],ifac[5011];
ll ffac[5011],inv[5011];
int n;
ll a[5011],dp[5011][5011];
ll f[5011],g[5011];
ll A,iA;//prod(ai+A*x)
ll solve(int x)
{
	for(int i=0;i<=n;i++)f[i]=dp[n][i];
	for(int i=n;i>=1;i--)
	{
		g[i-1]=f[i]*iA%mod;
		f[i-1]=(f[i-1]-g[i-1]*a[x]%mod+mod)%mod;
	}
//	for(int i=0;i<n;i++)cerr<<g[i]<<" ";cerr<<endl;
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		ll cur=ffac[i+1]%mod*inv[i+1]%mod*g[i]%mod;
		ret+=cur; 
	}
//	cerr<<"ret="<<ret%mod<<endl;
	return ret%mod;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=5010;i++)fac[i]=fac[i-1]*i%mod;
	ifac[5010]=qpow(fac[5010],mod-2);
	for(int i=5009;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=5005;i++)inv[i]=qpow(i,mod-2);
	
	getii(n,K);
	ffac[0]=1;
	for(int i=1;i<=n+1;i++)ffac[i]=(ffac[i-1]*(K-i+1)%mod+mod)%mod;
	for(int i=1;i<=n;i++)geti(a[i]);
	
	A=(mod-qpow(n,mod-2))%mod;
	iA=qpow(A,mod-2);
	//prod(a_i+A*x)
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j]*a[i]%mod;
			if(j>0)dp[i][j]=(dp[i][j]+A*dp[i-1][j-1])%mod;
		}
	}
	
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=solve(i);
	}
	ans%=mod;
	ans=ans*qpow(n,mod-2)%mod;
	cout<<ans<<endl;
	
	return 0;
}