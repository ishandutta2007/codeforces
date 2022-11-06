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

const int N=105;
int t,n,m,a[N],b[N],dp[N][N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=a[i-1]+read();
		m=read();
		for(int i=1;i<=m;++i)
			b[i]=b[i-1]+read();
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
			{
				dp[i][j]=a[i]+b[j];
				if(i!=0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
				if(j!=0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
			}
		printf("%lld\n",dp[n][m]);
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				dp[i][j]=0;
	}
	return 0;
}