#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 3010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,k,S,T,cnt,las[N],vis[N],mincost,head[N],dis[N],a[N],c[N];
int dep[N];
struct Edge{
	int to,nxt,val,cost;
}edge[N<<4];
void add(int a,int b,int c,int d){
	edge[++cnt]={b,head[a],c,d};
	head[a]=cnt;
}
bool SPFA(){
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(S);
	dis[S]=0;
	vis[S]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].val&&dis[v]>dis[u]+edge[i].cost){
				dis[v]=dis[u]+edge[i].cost;
				if(!vis[v])q.push(v),vis[v]=1;
			}
		}
	}
	return dis[T]<inf;
}
int dfs(int u,int limit){
	if(u==T)return limit;
	int flow=0;
	vis[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(edge[i].val&&dis[v]==dis[u]+edge[i].cost&&!vis[v]){
			int k=dfs(v,min(limit,edge[i].val));
			edge[i].val-=k;
			edge[i^1].val+=k;
			limit-=k;
			flow+=k;
			mincost+=k*edge[i].cost;
		}
	}
	vis[u]=0;
	if(!flow)dis[u]=-inf;
	return flow;
}
int Dinic(){
	int maxflow=0;
	while(SPFA()){
		maxflow+=dfs(S,inf);
	}
	return maxflow;
}
int main(){
	n=read(),k=read(),S=(n<<1|1),T=S+1,cnt=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		c[i]=read();
	}
	for(int i=1;i<=n;++i){
		int x=c[a[i]];
		add(S,i,1,x),add(i,S,0,-x);
		add(i,i+n,1,0),add(i+n,i,0,0);
		if(las[a[i]]){
			add(i-1,las[a[i]]+n,1,-x);
			add(las[a[i]]+n,i-1,0,x);
		}
		las[a[i]]=i;
		add(i+n,T,1,0),add(T,i+n,0,0);
	}
	for(int i=1;i<n;++i){
		add(i,i+1,k-1,0),add(i+1,i,0,0);
	}
	Dinic();
	printf("%d\n",mincost);
	return 0;
}