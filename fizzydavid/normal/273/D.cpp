//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
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
int n,m;
int dp[152][152][152][4];
int sum[152][152][152][4];
int calcsum(int i,int l1,int l2,int r1,int r2,int t)
{
	return (0ll+sum[i][l2][r2][t]-sum[i][l1-1][r2][t]-sum[i][l2][r1-1][t]+sum[i][l1-1][r1-1][t])%mod;
}
int main()
{
	cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
		{
			for(int r=l;r<=m;r++)
			{
				for(int t=0;t<4;t++)
				{
					int &v=dp[i][l][r][t];
					if(t==0)
					{
						v=1;
						v=(0ll+v+calcsum(i-1,l,r,l,r,0))%mod;
					}
					else if(t==1)
					{
						v=(0ll+v+calcsum(i-1,1,l,l,r,1))%mod;
						v=(0ll+v+calcsum(i-1,1,l-1,l,r,0))%mod;
					}
					else if(t==2)
					{
						v=(0ll+v+calcsum(i-1,l,r,r,m,2))%mod;
						v=(0ll+v+calcsum(i-1,l,r,r+1,m,0))%mod;
					}
					else if(t==3)
					{
						v=(0ll+v+calcsum(i-1,1,l,r,m,3))%mod;
						v=(0ll+v+calcsum(i-1,1,l-1,r,m,2))%mod;
						v=(0ll+v+calcsum(i-1,1,l,r+1,m,1))%mod;
						v=(0ll+v+calcsum(i-1,1,l-1,r+1,m,0))%mod;
					}
					ans+=v;
//					cout<<i<<" "<<l<<" "<<r<<" "<<t<<" "<<v<<endl;
				}
			}
		}
		for(int l=1;l<=m;l++)
		{
			for(int r=1;r<=m;r++)
			{
				for(int t=0;t<4;t++)
				{
					sum[i][l][r][t]=(0ll+sum[i][l-1][r][t]+sum[i][l][r-1][t]-sum[i][l-1][r-1][t]+dp[i][l][r][t])%mod;
				}
			}
		}
		ans%=mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}