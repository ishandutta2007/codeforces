#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 5050
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
namespace MCMF{
	int head[N];
	int ecnt,S,T;
	struct Edge{
		int nxt,to,val,cost;
	}edge[N<<4];
	void add(int a,int b,int c,int d){
		edge[++ecnt]={head[a],b,c,d};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c,int d){
		add(a,b,c,d);
		add(b,a,0,-d);
	}
	void init(int _S,int _T){
		memset(head,0,sizeof(head));
		ecnt=1;
		S=_S,T=_T;
	}
	int vis[N],dis[N],mincost;
	queue<int> q;
	bool SPFA(){
		memset(dis,0x3f,sizeof(dis));
		q.push(S);
		dis[S]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].val&&dis[v]>dis[u]+edge[i].cost){
					dis[v]=dis[u]+edge[i].cost;
					if(!vis[v]){
						q.push(v),vis[v]=1;
					}
				}
			}
		}
		return dis[T]<inf;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		vis[u]=1;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]==dis[u]+edge[i].cost&&!vis[v]&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
				mincost+=k*edge[i].cost;
			}
		}
		vis[u]=0;
		if(!flow)dis[u]=inf;
		return flow;	
	}
	pair<int,int> Dinic(){
		mincost=0;
		int maxflow=0;
		while(SPFA()){
			maxflow+=dfs(S,inf);
		}
		return make_pair(maxflow,mincost);
	}
}
int n,a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();		
	}
	MCMF::init(n+1,n+2);
	for(int i=1;i<n;++i){
		MCMF::adde(i,i+1,n,1);
		MCMF::adde(i+1,i,n,1);
	}
	for(int i=1;i<=n;++i){
		if(a[i])MCMF::adde(n+1,i,1,0);
		else MCMF::adde(i,n+2,1,0);	
	}
	auto [flow,cost]=MCMF::Dinic();
	printf("%d\n",cost);
	return 0;
}