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

const int N=4e5+5;
int n,a[N],dp[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

int dfs(int u,int fa,int x)
{
	int res=1,fl=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		res&=dfs(v,u,x);
		dp[u]+=dp[v];fl=0;
		if(dp[u]>2e14)
			dp[u]=2e14;
	}
	if(fl)
	{
		if(x<a[u])
			return 0;
		dp[u]=x-a[u];
		return 1;
	}
	if(!res||dp[u]<a[u])
		return 0;
	dp[u]-=a[u];
	return 1;
}

inline bool check(int x)
{
	memset(dp,0,sizeof(dp));
	return dfs(1,0,x);
}

signed main()
{
	n=read();
	for(int i=2;i<=n;++i)
	{
		int u=read();
		add(u,i);add(i,u);
	}
	for(int i=1;i<=n;++i)
		a[i]=read();
	int l=0,r=2e14,ans=-1;
	while(l<=r)
	{
		if(check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	write(ans);
	return 0;
}