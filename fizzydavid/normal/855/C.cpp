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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
ll kissme(ll x,ll k){return k==0?1:kissme(x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,m;
ll X,K,dp[100111][11],dp1[100111][11],dp2[100111][11];
ll dps[100111][11];
vector<int>con[100111];
ll tc[11],tmp[11],tmp2[11];
void combine(ll a[],ll b[],ll c[])
{
	memset(tc,0,sizeof(tc));
	for(int i=0;i<=10;i++)
	{
		for(int j=0;i+j<=10;j++)
		{
			tc[i+j]=(tc[i+j]+a[i]*b[j])%mod;
		}
	}
	for(int i=0;i<=10;i++)c[i]=tc[i];
}
void add(ll a[],ll b[],ll c[])
{
	for(int i=0;i<=10;i++)c[i]=(a[i]+b[i])%mod;
	for(int i=0;i<=10;i++)tc[i]=c[i];	
}
void dfs(int x,int pre)
{
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		dfs(u,x);
	}
	dps[x][0]=1;
	dp[x][0]=1;
	dp1[x][0]=1;
	dp2[x][0]=1;
	
	int cnt=0;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		cnt++;
		add(dp[u],dp1[u],tmp);
		combine(dp[x],tmp,dp[x]);
		
		add(tmp,dp2[u],tmp);
		combine(dps[x],tmp,dps[x]);
		
		combine(dp1[x],tmp,dp1[x]);
		combine(dp2[x],dps[u],dp2[x]);
	}
	for(int i=0;i<=10;i++)dp[x][i]=dp[x][i]*(m-X)%mod;
	for(int i=0;i<=10;i++)dp1[x][i]=dp1[x][i]*(X-1)%mod;
	
	for(int i=0;i<=10;i++)dp2[x][i]=dp2[x][i]%mod*kissme(X-1,cnt)%mod;
	for(int i=9;i>=0;i--)dp2[x][i+1]=dp2[x][i];dp2[x][0]=0;
/*	cerr<<"x="<<x<<endl;
	for(int i=0;i<=10;i++)cerr<<dp[x][i]<<" ";cerr<<endl;
	for(int i=0;i<=10;i++)cerr<<dp1[x][i]<<" ";cerr<<endl;
	for(int i=0;i<=10;i++)cerr<<dp2[x][i]<<" ";cerr<<endl;
	*/
}
int main()
{
	getii(n,m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	getii(X,K);
	dfs(1,-1);
	ll ans=0;
	for(int i=0;i<=K;i++)ans+=dp[1][i]+dp1[1][i]+dp2[1][i];
	cout<<ans%mod<<endl;
	return 0;
}