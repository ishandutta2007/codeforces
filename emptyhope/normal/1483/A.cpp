#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
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
#define maxn 200005
#define maxm 1000005
#define inf 0x3f3f3f3f

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
//	memcpy(cur,head,sizeof cur);
//	memset(dep,63,sizeof dep);
	For(i,0,t) cur[i]=head[i],dep[i]=inf;
	dep[s]=0;q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dep[v]==inf&&e[i].w){
				dep[v]=dep[u]+1;
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
    return res;
}
inline int dinic(int s,int t)
{
	int maxflow=0;
	while(bfs(s,t))maxflow+=dfs(s,t,inf);
	return maxflow;
}

int res[maxn];

void work()
{
	tot=1; 
	n=read(),m=read();
	int mx=(m/2)+(m&1);
	t=n+m+1,s=0;
	For(i,0,n+m+1)head[i]=0;
	For(i,1,n)add(s,i,mx);
	For(i,1,m)add(i+n,t,1);
	For(i,1,m){
		int k=read();
		while(k--){
			int x=read();
			add(x,i+n,1);
		}
	}
	int mxf=dinic(s,t);
	if(mxf<m) puts("NO");
	else {
		puts("YES");
		For(i,1,m)
			for(int j=head[i+n];j;j=e[j].nxt){
				if(e[j].w){
					cout<<e[j].to<<' ';
				}
			}
		puts("");
	}
}

signed main()
{
	int T=read();
	while(T--)work();
    return 0;
}