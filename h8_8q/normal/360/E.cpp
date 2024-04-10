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

const int N=1e5+5;
int n,m,K,s1,s2,t,l[N],r[N],k,dis[N],vis[N],p1[N],p2[N];

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

struct Node
{
	int u,w;
	bool operator < (const Node &x)const
	{
		return w>x.w;
	}
};

inline void add(int u,int v,int w);
inline void dij(int st);
void work(int x);

signed main()
{
	//freopen("yanglib.in","r",stdin);
	//freopen("stdb.out","w",stdout);
	n=read();m=read();K=read();m+=K;
	s1=read();s2=read();t=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		if(i<=m-K)
		{
			l[i]=w,r[i]=w;
			add(v,u,l[i]);
		}
		else
		{
			l[i]=w;r[i]=read();
			add(v,u,l[i]);
		}
	}
	dij(t);
	if(dis[s1]==INF||dis[s2]==INF)
	{
		printf("qwq\n");
		return 0;
	}
	for(int i=1;i<=m;++i)
		e[i].w=r[i];
	work(s1);
	dij(t);
	if(dis[s1]<dis[s2])
	{
		printf("WIN\n");
		for(int i=m-K+1;i<=tot;++i)
			printf("%lld ",e[i].w);
	}
	else if(dis[s1]==dis[s2])
	{
		printf("DRAW\n");
		for(int i=m-K+1;i<=tot;++i)
			printf("%lld ",e[i].w);
	}
	else printf("LOSE\n");
	return 0;
}

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

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
				p1[v]=u;p2[v]=i;
				qu.push((Node){v,dis[v]});
			}
		}
	}
}

void work(int x)
{
	if(x==t) return;
	e[p2[x]].w=l[p2[x]];
	work(p1[x]);
}