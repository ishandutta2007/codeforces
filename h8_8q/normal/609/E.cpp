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

const int N=2e5+5;
int n,m,dp[N][21],fa[N],sm[N][21],dep[N],ans,Ans[N];

struct edge
{
	int u,v,w,id;
	bool operator < (const edge &x)const
	{
		return w<x.w;
	}
}ee[N];

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline void kruskal();
void dfs(int u,int fa);
inline int query(int x,int y);

signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		ee[i]=(edge){u,v,read(),i};
	}
	kruskal();
	dfs(1,0);
	for(int i=1;i<=m;++i)
		Ans[ee[i].id]=ans+ee[i].w-query(ee[i].u,ee[i].v);
	for(int i=1;i<=m;++i) write(Ans[i]),puts("");
	return 0;
}

inline void kruskal()
{
	sort(ee+1,ee+1+m);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	int sum=0;
	for(int i=1;i<=m;++i)
	{
		int f1=find(ee[i].u);
		int f2=find(ee[i].v);
		if(f1!=f2)
		{
			fa[f1]=f2;++sum;ans+=ee[i].w;
			add(ee[i].u,ee[i].v,ee[i].w);
			add(ee[i].v,ee[i].u,ee[i].w);
		}
		if(sum==n-1) break;
	}
}

void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	dp[u][0]=fa;
	for(int i=1;i<=19;++i)
	{
		dp[u][i]=dp[dp[u][i-1]][i-1];
		sm[u][i]=max(sm[u][i-1],sm[dp[u][i-1]][i-1]);
	}
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		sm[v][0]=e[i].w;
		dfs(v,u);
	}
}

inline int query(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int res=0;
	for(int i=19;i>=0;--i)
		if(dep[dp[x][i]]>=dep[y])
			res=max(res,sm[x][i]),x=dp[x][i];
	if(x==y) return res;
	for(int i=19;i>=0;--i)
		if(dp[x][i]!=dp[y][i])
		{
			res=max(res,max(sm[x][i],sm[y][i]));
			x=dp[x][i],y=dp[y][i];
		}
	return max(res,max(sm[x][0],sm[y][0]));
}