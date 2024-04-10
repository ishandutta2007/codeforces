#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3fll;
#define N 666
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
int n,m,a[N],d[N];
int ans[N],g[N],tot;
namespace MCMF{
	int head[N];
	int ecnt,S,T;
	struct Edge{
		int nxt,to,val,cost;
	}edge[N*N<<1];
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
	void Find(int u,int id,int las){
		g[u]=las!=a[u];
		ans[u]=id;
		tot+=1+g[u];
		for(int i=head[u+n];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(v<=n&&!edge[i].val){
				Find(v,id,a[u]);
			}
		}
	}
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	int s=(n<<1)+1,t=s+2;
	MCMF::init(t+1,t+2);
	MCMF::adde(s,s+1,m,0);
	for(int i=1;i<=n;++i){
		MCMF::adde(s+1,i,1,__builtin_popcount(a[i]));
	//	MCMF::adde(i,i+n,[1,1],0);
		MCMF::adde(MCMF::S,i+n,1,0);
		MCMF::adde(i,MCMF::T,1,0);
		MCMF::adde(i+n,t,1,0);
	}
	for(int i=1;i<=n;++i){
		ans[i]=-1;
		for(int j=i+1;j<=n;++j){
			MCMF::adde(i+n,j,1,(a[i]==a[j]?0:__builtin_popcount(a[j])));
		}
	}
	MCMF::adde(t,s,inf,0);
	auto [flow,cost]=MCMF::Dinic();
	for(int i=MCMF::head[s+1],now=0;i;i=MCMF::edge[i].nxt){
		int v=MCMF::edge[i].to;
		if(v<=n&&!MCMF::edge[i].val){
			MCMF::Find(v,now++,0);
		}
	}
	printf("%d %d\n",tot,cost);
	for(int i=1;i<=n;++i){
		assert(ans[i]>=0);
		if(g[i])printf("%c=%d\n",ans[i]+'a',a[i]);
		printf("print(%c)\n",ans[i]+'a');
	}
	return 0;
}