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

const int N=3e5+5,mod=1e9+7;
int t,n,m,dp[15][N];

int work(int x,int y);

signed main()
{
	memset(dp,-1,sizeof(dp));
	t=read();
	while(t--)
	{
		n=read();m=read();
		int ans=0;
		while(n)
		{
			ans=(ans+work(n%10,m))%mod;
			n/=10;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

int work(int x,int y)
{
	if(y==0) return 1;
	if(dp[x][y]!=-1)
		return dp[x][y];
	int res=0;
	if(x<9) res=work(x+1,y-1);
	else res=(work(1,y-1)+work(0,y-1))%mod;
	return dp[x][y]=res;
}