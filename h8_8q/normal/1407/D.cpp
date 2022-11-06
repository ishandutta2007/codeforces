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

const int N=3e5+5;
int n,a[N],dp[N],mx[N],mn[N],t1,t2;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	dp[0]=1e18;
	mx[++t1]=1;mn[++t2]=1;
	for(int i=2;i<=n;++i)
	{
		dp[i]=dp[i-1]+1;
		while(t1>=1&&a[i]>=a[mx[t1]])
		{
			if(a[i]!=a[mx[t1]])
				dp[i]=min(dp[i],dp[mx[t1-1]]+1);
			--t1;
		}
		while(t2>=1&&a[i]<=a[mn[t2]])
		{
			if(a[i]!=a[mn[t2]])
				dp[i]=min(dp[i],dp[mn[t2-1]]+1);
			--t2;
		}
		mx[++t1]=i;mn[++t2]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}