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
const int mod=998244353;
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
int n,a,b;
ll dp_scc[2011],dp[2011];
ll dp_c[2011][2011];
ll P,pwP[2011],pw1P[2011];
int main()
{
	cin>>n>>a>>b;
	P=1ll*a*qpow(b,mod-2)%mod;
	pwP[0]=1;
	for(int i=1;i<=2005;i++)pwP[i]=pwP[i-1]*P%mod;
	pw1P[0]=1;
	for(int i=1;i<=2005;i++)pw1P[i]=pw1P[i-1]*(1-P+mod)%mod;
	
	for(int i=0;i<=n;i++)
	{
		dp_c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			dp_c[i][j]=(dp_c[i-1][j]*pwP[j]+dp_c[i-1][j-1]*pw1P[i-j])%mod;
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)cerr<<dp_c[i][j]<<" ";cerr<<endl;
	}*/
	dp_scc[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp_scc[i]=1;
		for(int j=1;j<i;j++)
		{
			dp_scc[i]=(dp_scc[i]-dp_c[i][j]*dp_scc[j]%mod+mod)%mod;
		}
	}
//	for(int i=1;i<=n;i++)cerr<<dp_scc[i]<<" ";cerr<<endl;
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ll coef=dp_c[i][j]*dp_scc[j]%mod;
			dp[i]+=coef*(i*(i-1)/2-(i-j)*(i-j-1)/2+(j==i?0:dp[j])+dp[i-j])%mod;
		}
		dp[i]=(dp[i]%mod+mod)%mod;
		dp[i]=dp[i]*qpow((1-dp_scc[i]+mod)%mod,mod-2)%mod;
	}
	cout<<dp[n]<<endl;
	return 0;
}