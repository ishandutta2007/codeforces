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
#define fan(x) (((x-1)^1)+1)
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

const int N=405;
int t,n,a[N],dp[N][N];

signed main()
{
	t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        sort(a+1,a+1+n);
        dp[1][0]=1e18;
        for(int i=1;i<=400;++i)
            dp[1][i]=min(dp[1][i-1],abs(a[1]-i));
        for(int i=2;i<=n;++i)
        {
            dp[i][0]=1e18;
            for(int j=1;j<=400;++j)
                dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(a[i]-j));
        }
        int ans=1e18;
        for(int i=1;i<=400;++i)
            ans=min(ans,dp[n][i]);
        printf("%lld\n",ans);
    }
	return 0;
}