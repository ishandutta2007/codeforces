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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,l,r;
int dp[2][10011];
int a[10011];
bool f[10011];
vector<int> vip,p;
int main()
{
	getiii(n,l,r);
	int len=0;
	for(int i=1;i<=n;i++)geti(a[i]),len+=a[i];
	for(int i=1;i<=n;i++)geti(f[i]);
	for(int i=1;i<=n;i++)
	{
		if(f[i])vip.PB(a[i]);
		else p.PB(a[i]);
	}
	sort(vip.begin(),vip.end());
	reverse(vip.begin(),vip.end());
	for(int i=0;i<=len;i++)dp[0][i]=dp[1][i]=-233333333;
	dp[0][0]=0;
	for(int i=0;i<p.size();i++)
	{
		int x=p[i];
//		cerr<<"x="<<x<<endl;
		for(int j=len-x;j>=0;j--)dp[0][j+x]=dp[0][j]>dp[0][j+x]?dp[0][j]:dp[0][j+x];
	}
	for(int i=0;i<vip.size();i++)
	{
		int x=vip[i];
//		cerr<<"x="<<x<<endl;
		for(int j=len;j>len-x;j--)dp[1][j]=dp[0][j]>dp[1][j]?dp[0][j]:dp[1][j];
		for(int j=len-x;j>=0;j--)
		{
			int c=dp[0][j]+(l<=j&&j<=r);
			dp[0][j+x]=c>dp[0][j+x]?c:dp[0][j+x];
			c=dp[1][j]+(l<=j&&j<=r);
			dp[1][j+x]=c>dp[1][j+x]?c:dp[1][j+x];
			dp[1][j]=dp[0][j]>dp[1][j]?dp[0][j]:dp[1][j];
		}
//		for(int j=0;j<=len;j++)cerr<<dp[0][j]<<" ";cerr<<endl;
//		for(int j=0;j<=len;j++)cerr<<dp[1][j]<<" ";cerr<<endl;
	}
	
	int mx=0;
	for(int i=0;i<=len;i++)mx=max(mx,max(dp[0][i],dp[1][i]+(l<=i&&i<=r)));
	cout<<mx<<endl;
	return 0;
}