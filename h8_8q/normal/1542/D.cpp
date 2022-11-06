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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1005,mod=998244353;
int n,dp[N][N],ans;

struct opt
{
	int x,y;
}a[N];

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		char s[50];
		scanf("%s",s+1);
		if(s[1]=='+')
			a[i]=(opt){1,read()};
		else a[i]=(opt){0,0};
	}
	for(int i=1;i<=n;++i)
		if(a[i].x==1)
		{
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			for(int j=1;j<=i-1;++j)
				for(int k=0;k<=j;++k)
				{
					dp[j][k]=(dp[j][k]+dp[j-1][k])%mod;
					if(a[j].x==0)
					{
						dp[j][k]=(dp[j][k]+dp[j-1][k+1])%mod;
						if(k==0) dp[j][k]=(dp[j][k]+dp[j-1][k])%mod;
					}
					if(a[j].x==1)
					{
						if(a[j].y<a[i].y&&k!=0)
							dp[j][k]=(dp[j][k]+dp[j-1][k-1])%mod;
						else if(a[j].y>=a[i].y)
							dp[j][k]=(dp[j][k]+dp[j-1][k])%mod;
					}
				}
			for(int j=0;j<=i-1;++j)
				dp[i][j+1]=dp[i-1][j];
			for(int j=i+1;j<=n;++j)
				for(int k=1;k<=j;++k)
				{
					dp[j][k]=(dp[j][k]+dp[j-1][k])%mod;
					if(a[j].x==0)
						dp[j][k]=(dp[j][k]+dp[j-1][k+1])%mod;
					if(a[j].x==1)
					{
						if(a[j].y<=a[i].y&&k!=0)
							dp[j][k]=(dp[j][k]+dp[j-1][k-1])%mod;
						else if(a[j].y>a[i].y)
							dp[j][k]=(dp[j][k]+dp[j-1][k])%mod;
					}
				}
			int res=0;
			for(int j=0;j<=n;++j)
				res+=dp[n][j],res%=mod;
			ans=(ans+res*a[i].y%mod)%mod;
		}
	printf("%lld\n",ans);
	return 0;
}