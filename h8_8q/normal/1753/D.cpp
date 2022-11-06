#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>
#include<assert.h>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
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

const int N=2e6+5;
int n,m,p,q,id[N];
char s[N],lis[N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

#define id(x,y) (((x)-1)*m+(y))

vector<pair<int,int> > ps;

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

int dis[N],vis[N];

struct node
{
	int u,w;
	bool operator < (const node &p)const
	{
		return w>p.w;
	}
};

inline int dij()
{
	for(int i=1;i<=n*m;++i)
		dis[i]=INF,vis[i]=0;
	priority_queue<node> qu;
	for(int i=0;i<SZ(ps);++i)
	{
		int u=id(ps[i].fi,ps[i].se);
		qu.push((node){u,0});dis[u]=0;
	}
	while(!qu.empty())
	{
		int u=qu.top().u;
		qu.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				qu.push((node){v,dis[v]});
			}
		}
	}
	int res=INF;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(i!=n) res=min(res,dis[id(i,j)]+dis[id(i+1,j)]);
			if(j!=m) res=min(res,dis[id(i,j)]+dis[id(i,j+1)]);
		}
	return res;
}

signed main()
{
	n=read();m=read();
	p=read();q=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",lis+1);
		for(int j=1;j<=m;++j)
		{
			s[id(i,j)]=lis[j];
			if(lis[j]=='.')
				ps.push_back(mp(i,j));
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[id(i,j)]!='#')
				for(int k=0;k<4;++k)
				{
					int xx=i+dx[k];
					int yy=j+dy[k];
					if(xx<1||xx>n||yy<1||yy>m)
						continue;
					if(s[id(xx,yy)]=='#'||s[id(xx,yy)]=='.')
						continue;
					int px=xx,py=yy,w=0;
					if(s[id(xx,yy)]=='L') py++;
					if(s[id(xx,yy)]=='R') py--;
					if(s[id(xx,yy)]=='U') px++;
					if(s[id(xx,yy)]=='D') px--;
					if(px==i&&py==j) continue;
					if(abs(px-i)==1) w=p;
					else w=q;
					add(id(i,j),id(px,py),w);
				}
	int ans=dij();
	if(ans==INF) puts("-1");
	else write(ans);
	return 0;
}