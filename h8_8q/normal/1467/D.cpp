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
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define max Max
#define min Min
#define abs Abs

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

const int N=5005,mod=1e9+7;
int n,k,q,a[N],dp[N][N],sum[N],ans;

signed main()
{
	n=read();k=read();q=read();
	for(int i=1;i<=n;++i)
		dp[i][0]=1,a[i]=read();
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
		{
			if(j!=1) dp[j][i]+=dp[j-1][i-1],dp[j][i]%=mod;
			if(j!=n) dp[j][i]+=dp[j+1][i-1],dp[j][i]%=mod;
		}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=k;++j)
			sum[i]+=dp[i][j]*dp[i][k-j]%mod,sum[i]%=mod;
	for(int i=1;i<=n;++i)
		ans+=sum[i]*a[i]%mod,ans%=mod;
	while(q--)
	{
		int x=read(),y=read();
		ans=((ans-sum[x]*a[x]%mod)%mod+mod)%mod;
		ans+=sum[x]*y%mod;ans%=mod;
		a[x]=y;
		printf("%lld\n",ans);
	}
	return 0;
}