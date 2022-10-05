#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

const int maxn=10007,maxm=100007,inf=0x3f3f3f3f3f3f3f3f;
int n,m,s,t,maxflow;
int dep[maxn],cur[maxn];
int tot=1,head[maxn];
struct edge{
	int to,nxt,w;
}e[maxm<<1];
inline void adde(int u,int v,int w){
	e[++tot]=(edge){v,head[u],w};
	head[u]=tot;
}
inline void add(int u,int v,int w){
	adde(u,v,w);
	adde(v,u,0);
}
bool bfs(int s,int t)
{
	queue<int>q;
	memcpy(cur,head,sizeof cur);
	memset(dep,63,sizeof dep);
	dep[s]=0;q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dep[v]==inf&&e[i].w){
				dep[v]=dep[u]+1;
                if(v==t)return 1;
				q.push(v);
			}
		}
	}return dep[t]<inf;
}
int dfs(int u,int t,int minn)
{
	if(!minn||u==t)return minn;
	int res=0;
	for(int i=cur[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		cur[u]=i;
		if(dep[v]!=dep[u]+1)continue;
		int flow=dfs(v,t,min(minn,e[i].w));
		if(!flow)continue;
		res+=flow,minn-=flow;
		e[i].w-=flow,e[i^1].w+=flow;
		if(!minn)break;
	}
    if(!res) dep[u]=0;
    return res;
}
inline int dinic(int s,int t)
{
	int maxflow=0,flow=0;
	while(bfs(s,t))while(flow=dfs(s,t,inf))maxflow+=flow;
	return maxflow;
}

int a[maxn],b[maxn],c[maxn],l[maxn],r[maxn];
inline int calc(int id,int x){return a[id]*x*x+b[id]*x+c[id];}
int mx=1000000000000,cnt=0;
int p[233][233];
signed main()
{
	n=read(),m=read();
	For(i,1,n)a[i]=read(),b[i]=read(),c[i]=read();
	For(i,1,n){
		l[i]=read(),r[i]=read();
		add(s,cnt+1,inf);
		For(j,l[i]+100,r[i]+101){
			p[i][j]=++cnt;
			if(j!=l[i]+100) add(p[i][j-1],p[i][j],mx-calc(i,j-1-100));
		}
	}
	t=++cnt;
	For(i,1,n)
		add(p[i][r[i]+101],t,inf);
	For(i,1,m){
		int u=read(),v=read(),d=read();
		For(j,l[u],r[u]+1)
			if(j-d>=l[v] && j-d<=r[v]+1)	
				add(p[u][j+100],p[v][j-d+100],inf);
	}
	int res=mx*n-dinic(s,t);
	cout<<res;
	return 0;
}