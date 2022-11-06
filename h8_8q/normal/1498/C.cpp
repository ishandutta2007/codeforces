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

const int N=1005,mod=1e9+7;
int t,n,m,dp[N][2][N],sum[N][2];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			dp[1][0][i]=dp[1][1][i]=1;
		for(int j=0;j<=1;++j)
			for(int k=1;k<=n;++k)
				sum[k][j]=(sum[k-1][j]+dp[1][j][k])%mod;
		for(int i=2;i<=m-1;++i)
		{
			for(int j=0;j<=1;++j)
				for(int k=1;k<=n;++k)
					if(j==1)
						dp[i][1][k]=(1+sum[k-1][0])%mod;
					else dp[i][0][k]=(1+sum[n][1]-sum[k][1]+mod)%mod;
			for(int j=0;j<=1;++j)
				for(int k=1;k<=n;++k)
					sum[k][j]=(sum[k-1][j]+dp[i][j][k])%mod;
		}
			
		int ans=1;
		for(int i=1;i<=n;++i)
			ans+=dp[m-1][1][i],ans%=mod;
		printf("%lld\n",ans);
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				dp[j][0][i]=dp[j][1][i]=0;
	}
	return 0;
}