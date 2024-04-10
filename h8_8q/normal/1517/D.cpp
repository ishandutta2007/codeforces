#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=505;
int n,m,k,a[N][N],b[N][N],dp[N][N][15];

signed main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m-1;++j)
			a[i][j]=read();
	for(int i=1;i<=n-1;++i)
		for(int j=1;j<=m;++j)
			b[i][j]=read();
	if(k%2==1)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("-1 ");
			printf("\n");
		}
		return 0;
	}
	for(int p=1;p<=k/2;++p)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				dp[i][j][p]=1e18;
				if(i-1>=1) dp[i][j][p]=min(dp[i][j][p],dp[i-1][j][p-1]+b[i-1][j]*2);
				if(i+1<=n) dp[i][j][p]=min(dp[i][j][p],dp[i+1][j][p-1]+b[i][j]*2);
				if(j-1>=1) dp[i][j][p]=min(dp[i][j][p],dp[i][j-1][p-1]+a[i][j-1]*2);
				if(j+1<=m) dp[i][j][p]=min(dp[i][j][p],dp[i][j+1][p-1]+a[i][j]*2);
			}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			printf("%lld ",dp[i][j][k/2]);
		printf("\n");
	}
	return 0;
}