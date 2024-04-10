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
#define INF 0x3f3f3f3f3f3f3f3f

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

const int N=5005;
int t,n,dp[N],lcp[N][N];
char s[N];

inline bool cmp(int x,int y)
{
	if(lcp[x][y]==n-x+1) return 0;
	return s[x+lcp[x][y]]>s[y+lcp[x][y]];
}

inline int query(int x,int y)
{
	return cmp(x,y)?dp[y]+n-x+1-lcp[x][y]:0;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n+1;++i)
			for(int j=1;j<=n+1;++j)
				lcp[i][j]=0;
		for(int i=n;i>=0;--i)
			for(int j=n;j>=0;--j)
				if(i==j) lcp[i][j]=n-i;
				else if(s[i]==s[j])
					lcp[i][j]=lcp[i+1][j+1]+1;
				else lcp[i][j]=0;
		dp[1]=n;
		int ans=n;
		for(int i=2;i<=n;++i)
		{
			dp[i]=n-i+1;
			for(int j=1;j<=i-1;++j)
				dp[i]=max(dp[i],query(i,j));
			ans=max(ans,dp[i]);
		}
		printf("%lld\n",ans);
	}
}