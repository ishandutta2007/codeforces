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

const int N=2e6+5,mod=998244353;
int n,m,dp[N],d[N],e[N],vis[N],pri[N],pre[N];

signed main()
{
	for(int i=2;i<=2000000;++i)
	{
		if(!vis[i]) pri[++m]=i,d[i]=2,e[i]=1;
		for(int j=1;j<=m&&i*pri[j]<=2000000;++j)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				d[i*pri[j]]=d[i]/(e[i]+1)*(e[i]+2);
				e[i*pri[j]]=e[i]+1;
				break;
			}
			else 
			{
				d[i*pri[j]]=d[i]*2;
				e[i*pri[j]]=1;
			}
		}
	}
	n=read();
	dp[1]=1;dp[0]=1;
	pre[0]=1,pre[1]=2;
	for(int i=2;i<=n;++i)
	{
		dp[i]=pre[i-1];
		dp[i]=(dp[i]+d[i]-1)%mod;
		pre[i]=(pre[i-1]+dp[i])%mod;
	}
		
	printf("%lld\n",dp[n]);
	return 0;
}