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
int n,a[52],dp[52][52][52][52],ndp[52][52][52][52];
void add(int &x,ll y)
{
	x=(x+y)%mod;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[0][0][a[1]][0]=1;
	for(int i=2;i<=n;i++)
	{
						
		for(int c0=0;c0<=n;c0++)
		{
			for(int c1=0;c1<=n-c0;c1++)
			{
				if(c0>0||c1>0)dp[c0][c1][0][0]=(dp[c0][c1][0][0]+dp[0][0][c0][c1])%mod;
			}
		}
		for(int pc0=0;pc0<=n;pc0++)
		{
			for(int pc1=0;pc1<=n-pc0;pc1++)
			{
				for(int c0=0;c0<=n;c0++)
				{
					for(int c1=0;c1<=n-c0;c1++)
					{
						ll v=dp[pc0][pc1][c0][c1];
						if(!v)continue;
						if(pc0)add(ndp[pc0-1][pc1][c0][c1],v*pc0);
						if(pc1)add(ndp[pc0+1][pc1-1][c0][c1],v*pc1);
					}
				}
			}
		}
		swap(dp,ndp);
		memset(ndp,0,sizeof(ndp));
		for(int pc0=0;pc0<=n;pc0++)
		{
			for(int pc1=0;pc1<=n-pc0;pc1++)
			{
				for(int c0=0;c0<=n;c0++)
				{
					for(int c1=0;c1<=n-c0;c1++)
					{
						ll v=dp[pc0][pc1][c0][c1];
						if(!v)continue;
						if(a[i]==2)
						{
							add(ndp[pc0][pc1][c0+1][c1],v);
							if(c0)add(ndp[pc0][pc1][c0-1][c1],v*c0);
							if(c1)add(ndp[pc0][pc1][c0+1][c1-1],v*c1);
						}
						if(a[i]==3)
						{
							add(ndp[pc0][pc1][c0][c1+1],v);
							if(c0)add(ndp[pc0][pc1][c0-1+1][c1],v*c0);
							if(c1)add(ndp[pc0][pc1][c0+1+1][c1-1],v*c1);
							if(c0>=2)add(ndp[pc0][pc1][c0-2][c1],v*c0*(c0-1)/2);
							if(c0>=1&&c1>=1)add(ndp[pc0][pc1][c0][c1-1],v*c0*c1);
							if(c1>=2)add(ndp[pc0][pc1][c0+2][c1-2],v*c1*(c1-1)/2);
						}
					}
				}
			}
		}
		swap(dp,ndp);
		memset(ndp,0,sizeof(ndp));
	}
	ll ans=dp[0][0][0][0];
	if(a[1]>=2)ans=ans*500000004%mod;
	if(a[1]>=3)ans=ans*333333336%mod;
	cout<<ans<<endl;
	return 0;
}