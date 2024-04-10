#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 233
#define M 5005
typedef long long ll;
namespace MCMF{
	int head[N];
	int ecnt,S,T;
	struct Edge{
		int nxt,to,val,cost;
	}edge[M<<2];
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
	vector<pair<int,int> > Dinic(){
		mincost=0;
		vector<pair<int,int> > tmp;
		while(SPFA()){
			tmp.emplace_back(dis[T],dfs(S,inf));
		}
		return tmp;
	}
}
int n,m,Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(8);
	cin>>n>>m;
	MCMF::init(1,n);
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		MCMF::adde(u,v,1,w);
	}
	auto vec=MCMF::Dinic();
	vector<pair<int,int> > jb;
	int F=0,C=0;
	for(auto [x,y]:vec){
		F+=y;
		C+=x*y;
		jb.emplace_back(F,C);
	}
	cin>>Q;
	while(Q--){
		int x;
		cin>>x;
		double ans=1e18;
		for(auto [F,C]:jb){
			ans=min(ans,(C+x)*1.0/F);
		}
		cout<<ans<<'\n';
	}
	return 0;
}