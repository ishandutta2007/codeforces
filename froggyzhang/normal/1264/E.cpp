#include<bits/stdc++.h>
using namespace std;
#define N 2333
const int inf=0x3f3f3f3f;
typedef long long ll;
namespace MCMF{
	int head[N];
	int ecnt,S,T;
	struct Edge{
		int nxt,to,val,cost;
	}edge[N<<6];
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
int n,m,d[N],mp[N][N],ans;
pair<int,int> jb[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		mp[u][v]=1;
		++d[u];
	}
	MCMF::init(n+n*(n-1)/2+1,n+n*(n-1)/2+2);
	for(int i=1;i<=n;++i){
		for(int j=d[i];j<n;++j){
			MCMF::adde(i,MCMF::T,1,j);	
		}	
	}
	int cnt=n;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(i==j||mp[i][j]||mp[j][i])continue;
			++cnt;
			jb[cnt]=make_pair(i,j);
			MCMF::adde(MCMF::S,cnt,1,0);
			MCMF::adde(cnt,i,1,0);
			MCMF::adde(cnt,j,1,0);
		}
	}
	MCMF::Dinic();
	for(int u=n+1;u<=cnt;++u){
		for(int i=MCMF::head[u];i;i=MCMF::edge[i].nxt){
			int v=MCMF::edge[i].to;
			if(v>=1&&v<=n&&!MCMF::edge[i].val){
				mp[v][jb[u].first==v?jb[u].second:jb[u].first]=1;	
			}	
		}	
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<mp[i][j];
		}
		cout<<'\n';
	}
	return 0;
}