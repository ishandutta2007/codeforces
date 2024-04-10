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

const int N=105,M=2005;
int n,m,a[N],dp[N*M],pre[N*M];

void print(int x)
{
	if(!x) return;
	
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),m+=a[i];
	if(m%2==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=200000;++i)
		dp[i]=1e9;
	for(int i=1;i<=n;++i)
		for(int j=200000;j>=a[i];--j)
			dp[j]=min(dp[j],dp[j-a[i]]+1);
	if(dp[m/2]==1e9)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;++i)
		if(a[i]%2==1)
		{
			printf("1\n%d\n",i);
			return 0;
		}
	for(int i=1;i<=n;++i)
		if(dp[(m-a[i])/2]==1e9)
		{
			printf("1\n%d\n",i);
			return 0;
		}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(dp[(m-a[i]-a[j])/2]==1e9)
			{
				printf("2\n%d %d\n",i,j);
				return 0;
			}
	return 0;
}