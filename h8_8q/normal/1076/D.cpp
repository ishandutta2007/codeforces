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

const int N=3e5+5;
int n,m,k,dis[N],vis[N];

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

struct Node
{
	int u,w;
	bool operator < (const Node &x)const
	{
		return w>x.w;
	}
};

inline void dij(int st)
{
	for(int i=1;i<=n;++i)
		dis[i]=INF,vis[i]=0;
	priority_queue<Node> qu;
	qu.push((Node){st,0});
	dis[st]=0;
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

vector<int> ans;

void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		if(dis[v]!=dis[u]+e[i].w) continue;
		ans.push_back((i+1)/2);
		dfs(v);
	}
}

signed main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	dij(1);
	for(int i=1;i<=n;++i)
		vis[i]=0;
	dfs(1);
	printf("%lld\n",min(n-1,k));
	for(int i=0;i<ans.size()&&i<k;++i)
		printf("%lld ",ans[i]);
	return 0;
}