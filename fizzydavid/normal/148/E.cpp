//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
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
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
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
int n,m,sz[101],a[101][101],sum[101][101],dp[2][10011]; 
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)
	{
		geti(sz[i]);
		for(int j=1;j<=sz[i];j++)
		{
			geti(a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sz[i];j++)
		{
			int tsum=0;
			for(int k=1;k<=j;k++)tsum+=a[i][k];
			sum[i][j]=tsum;
			for(int k=j-1;k>=0;k--)
			{
				tsum=tsum-a[i][k+1]+a[i][sz[i]-(j-k)+1];
				sum[i][j]=max(sum[i][j],tsum);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int p=i&1;
		for(int j=0;j<=m;j++)dp[p^1][j]=0;
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=sz[i];k++)
			{
				if(j+k<=m)dp[p^1][j+k]=max(dp[p^1][j+k],dp[p][j]+sum[i][k]);
			}
		}
	}
	putsi(dp[(n+1)&1][m]);
	return 0;
}