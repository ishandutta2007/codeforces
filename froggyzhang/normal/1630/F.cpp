#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class F>
class Maxflow{
	const F inf=numeric_limits<F>::max();
	struct Edge{
		int u,v;
		F w;
	};
	int n,S,T;
	vector<Edge> edge;
	vector<vector<int> > G;
	vector<int> dep;
	vector<int> iter;
	bool bfs(){
		fill(dep.begin(),dep.end(),-1);
		queue<int> q;
		q.push(S);
		dep[S]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto id:G[u]){
				int v=edge[id].v;
				if(edge[id].w>0&&dep[v]==-1){
					dep[v]=dep[u]+1;
					q.push(v);
					if(v==T)return true;
				}
			}
		}
		return false;
	}
	F dfs(int u,F limit){
		if(u==T||!limit)return limit;
		F flow=0;
		for(int &i=iter[u];i<(int)G[u].size();++i){
			int id=G[u][i];
			int v=edge[id].v;
			F w=edge[id].w;
			if(dep[v]==dep[u]+1){
				F tmp=dfs(v,min(limit,w));
				if(tmp>0){
					edge[id].w-=tmp,edge[id^1].w+=tmp;
					flow+=tmp,limit-=tmp;
					if(limit==0)break;	
				}
			}
		}
		if(flow==0)dep[u]=-1;
		return flow;
	}
public:
	Maxflow(int _n):n(_n){
		dep.resize(n+1),iter.resize(n+1),G.resize(n+1);
	}
	void adde(int u,int v,F w){
		G[u].push_back(edge.size()),edge.push_back({u,v,w});
		G[v].push_back(edge.size()),edge.push_back({v,u,0});	
	}
	F Dinic(int _S,int _T){
		S=_S,T=_T;
		F ans=0;
		while(bfs()){
			fill(iter.begin(),iter.end(),0);
			ans+=dfs(S,inf);
		}
		return ans;
	}
};
const int N=50050;
int n,p[N],a[N];
inline int ID(int x,int y){
	return (x-1)*4+y;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[a[i]]=i;
	}
	Maxflow<int> G(n*4+5);
	int S=4*n+1,T=4*n+2;
	for(int i=1;i<=n;++i){
		G.adde(S,ID(i,1),1);
		G.adde(ID(i,2),ID(i,3),1);
		G.adde(ID(i,4),T,1);
	}
	for(int i=1;i<=n;++i){
		for(int j=a[i]+a[i];j<N;j+=a[i]){
			if(p[j]){
				G.adde(ID(i,1),ID(p[j],2),1);
				G.adde(ID(i,3),ID(p[j],4),1);
			}
		}
	}
	cout<<G.Dinic(S,T)<<'\n';
	for(int i=1;i<=n;++i)p[a[i]]=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}