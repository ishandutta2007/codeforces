#include<bits/stdc++.h>
using namespace std;
#define N 1333
typedef long long ll;
const int inf=0x3f3f3f3f;
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N];
	struct Edge{
		int nxt,to,val;
	}edge[N<<3];
	void add(int a,int b,int c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c){
		add(a,b,c),add(b,a,0);
	}
	void init(int _S,int _T){
		ecnt=1;
		memset(head,0,sizeof(head));
		S=_S,T=_T;
	}
	queue<int> q;
	bool bfs(){
		memset(dep,0,sizeof(dep));
		q.push(S);
		dep[S]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].val&&!dep[v]){
					dep[v]=dep[u]+1;
					q.push(v);
				}
			}
		}
		return dep[T]>0;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
		}
		if(!flow)dep[u]=inf;
		return flow;
	}
	int Dinic(){
		int maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
		}
		return maxflow;
	}
}
int n,m,k,d[N],ans[N];
void Solve(){
	cin>>n>>m>>k;
	Maxflow::init(n+m+1,n+m+2);
	for(int i=1;i<=n;++i){
		d[i]=0;
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		++d[u],++d[v];
		Maxflow::adde(u,n+i,1);
		Maxflow::adde(v,n+i,1);	
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		if(d[i]>k)sum+=2*(d[i]-k),Maxflow::adde(Maxflow::S,i,2*(d[i]-k));	
	}
	for(int i=1;i<=m;++i){
		Maxflow::adde(n+i,Maxflow::T,1);
		ans[i]=0;
	}
	if(Maxflow::Dinic()^sum){
		for(int i=1;i<=m;++i){
			cout<<0<<' ';
		}
		cout<<'\n';
		return;
	}
	int col=0;
	for(int u=1;u<=n;++u){
		vector<int> V;
		for(int i=Maxflow::head[u];i;i=Maxflow::edge[i].nxt){
			int v=Maxflow::edge[i].to;
			if(!Maxflow::edge[i].val&&v>n&&v<=n+m){
				V.push_back(v-n);
			}
		}
		for(int i=0;i<(int)V.size();i+=2){
			ans[V[i]]=ans[V[i+1]]=++col;	
		}
	}
	for(int i=1;i<=m;++i){
		if(!ans[i])ans[i]=++col;
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}