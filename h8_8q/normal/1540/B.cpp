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

const int N=505,mod=1e9+7;
int n,x,y,a[N],vis[N],dep[N],dp[N][15],C[N][N],ans;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

inline void add(int u,int v);
void dfs(int u,int fa);
inline int lca(int x,int y);

signed main()
{
	n=read();
	C[0][0]=1;
	for(int i=1;i<=n*2;++i)
		for(int j=0;j<=i;++j)
		{
			if(i==0&&j==0) continue;
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	for(int i=0;i<=n*2;++i)
		for(int j=0;j<=i;++j)
			C[i][j]=(C[i][j]+C[i][j-1])%mod;
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;++i)
	{
		dep[i]=0;
		dfs(i,0);
		for(int j=1;j<=n;++j)
			for(int k=j-1;k>=1;--k)
			{
				int LCA=lca(j,k);
				int p1=dep[j]-dep[LCA];
				int p2=dep[k]-dep[LCA];
				if(LCA==j) ans++;
				if(LCA==j||LCA==k)
					continue;
				int fm=q_pow(2,p1+p2-1);
				int fz=C[p1+p2-1][p2-1];
				ans=(ans+fz*q_pow(fm,mod-2)%mod)%mod;
			}
	}
	ans=ans*q_pow(n,mod-2)%mod;
	printf("%lld\n",ans);
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	dp[u][0]=fa;
	for(int i=1;i<=10;++i)
		dp[u][i]=dp[dp[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
}

inline int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=10;i>=0;--i)
		if(dep[dp[x][i]]>=dep[y])
			x=dp[x][i];
	if(x==y) return x;
	for(int i=10;i>=0;--i)
		if(dp[x][i]!=dp[y][i])
			x=dp[x][i],y=dp[y][i];
	return dp[x][0];
}