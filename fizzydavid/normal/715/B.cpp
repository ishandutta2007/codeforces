//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,m,S,T;
int head[1011],nxt[20011],to[20011],cost[20011],tot=1;
ll diss[1011],dist[1011],L;
set<pair<ll,int> >st;
bool vis[1011];
int pre[1011];
void dijkstra(int S,ll dis[])
{
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=n;i++)dis[i]=1e18;
	dis[S]=0;
	st.insert(MP(0,S));
	memset(vis,0,sizeof(vis));
	while(st.size()>0)
	{
		int u=st.begin()->SS;st.erase(st.begin());
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(dis[v]>dis[u]+cost[i])
			{
				dis[v]=dis[u]+cost[i];
				pre[v]=i;
				st.insert(MP(dis[v],v));
			}
		}
	}
}
void initd()
{
	dijkstra(S,diss);
	dijkstra(T,dist);
}
bool erased[10011],path[10011];
void out()
{
	puts("YES");
	for(int i=1;i<=m;i++)
	{
		printf("%d %d %d\n",to[i*2+1]-1,to[i*2]-1,cost[i*2]);
	}
}
int main()
{
	getiii(n,m,L);
	getii(S,T);
	S++;T++;
	for(int i=1;i<=m;i++)
	{
		int x,y,d;
		getiii(x,y,d);
		x++;y++;
		if(d==0)erased[i]=1,d++;
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		cost[tot]=d;
		nxt[++tot]=head[y];
		head[y]=tot;
		cost[tot]=d;
		to[tot]=x;
	}
	dijkstra(S,diss);
	int id=0;
	for(int i=pre[T];i!=0;i=pre[to[i^1]])
	{
		path[i/2]=1;
		if(erased[i/2]&&id==0)id=i;
	}
	if(id==0)
	{
		if(diss[T]==L)out();
		else puts("NO");
		return 0;
	}
	for(int i=1;i<=m;i++)if(erased[i]&&!path[i])cost[i*2]=cost[i*2+1]=L;
	initd();
	for(int i=1;i<=m;i++)
	{
		if(erased[i]&&path[i])
		{
			ll mn=min(diss[to[i*2]]+dist[to[i*2+1]],dist[to[i*2]]+diss[to[i*2+1]]);
			cost[i*2]+=max(0ll,L-mn-1);
			cost[i*2+1]+=max(0ll,L-mn-1);
			initd();
		}
		if(diss[T]==L)break;
	}
	if(diss[T]==L)out();
	else puts("NO");
	return 0;
}