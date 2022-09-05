//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
pair<ll,int> dp[2211][2211];
ll a[2211],b[2211];
int n,k;
ll calc(ll coef)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
			if(i<=j)dp[i][j]=min(dp[i][j],MP(dp[i-1][j-1].FF+a[i]+b[j]+coef,dp[i-1][j-1].SS+1));
		}
	}
//	cout<<dp[n][n].FF<<","<<dp[n][n].SS<<endl;
	return dp[n][n].SS;
}
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<=n;i++)geti(b[i]);
	ll l=-Imx,r=Imx;
	while(l<=r)
	{
		ll m=l+r>>1;
		int curk=calc(m);
		if(curk>=k)l=m+1;
		else r=m-1;
	}
//	cout<<"r="<<r<<endl;
	calc(r);
	cout<<dp[n][n].FF-r*k<<endl;
	return 0;
}