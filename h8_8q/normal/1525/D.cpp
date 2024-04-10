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

const int N=5005;
int n,m,k,a[N],b[N],dp[N][N];

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int c=read();
		if(c) a[++m]=i;
		else b[++k]=i;
	}
	memset(dp,0x3f,sizeof(dp));
	for(int j=0;j<=k;++j)
		dp[0][j]=0;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=k;++j)
			dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(a[i]-b[j]));
	printf("%lld\n",dp[m][k]);
	return 0;
}