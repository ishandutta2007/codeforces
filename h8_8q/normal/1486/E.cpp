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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5,M=1e7+5;
int n,m,k,dis[N*55],vis[N*55],id[N][55];

struct Edge
{
	int v,w,ne;
}e[N*55*2];
int head[N*55],tot;

struct Node
{
	int u,w;
	bool operator < (const Node &x)const
	{
		return w>x.w;
	}
};

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

inline void dij(int st)
{
	for(int i=1;i<=k;++i)
		dis[i]=2e9;
	dis[st]=0;
	priority_queue<Node> qu;
	qu.push((Node){st,0});
	while(!qu.empty())
	{
		int u=qu.top().u;
		qu.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(!vis[v]) qu.push((Node){v,dis[v]});
			}
		}
	}
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=0;j<=50;++j)
			id[i][j]=++k;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		add(id[u][0],id[v][w],w*w);
		add(id[v][0],id[u][w],w*w);
		for(int j=1;j<=50;++j)
		{
			add(id[v][j],id[u][0],w*w+j*w*2);
			add(id[u][j],id[v][0],w*w+j*w*2);
		}
	}
	dij(id[1][0]);
	for(int i=1;i<=n;++i)
		if(dis[id[i][0]]==2e9)
			printf("-1 ");
		else printf("%d ",dis[id[i][0]]);
	return 0;
}