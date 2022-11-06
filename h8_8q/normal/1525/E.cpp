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

const int N=25,M=5e4+5,mod=998244353;
int n,m,a[N][M],sum[N],dp[N],ans;

inline int q_pow(int a,int b);

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=read();
	int tmp=1;
	for(int i=2;i<=n;++i)
		tmp=tmp*q_pow(i,mod-2)%mod;
	for(int i=1;i<=m;++i)
	{
		memset(sum,0,sizeof(sum));
		for(int j=1;j<=n;++j)
			sum[n+1-a[j][i]]++;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int res=0;
		for(int j=0;j<n;++j)
		{
			res+=sum[j];
			dp[j+1]=dp[j]*res%mod;
			res=max(0,res-1);
		}
		ans=(ans+1-dp[n]*tmp%mod+mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}