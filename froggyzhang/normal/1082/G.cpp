#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m,a[N];
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N];
	struct Edge{
		int nxt,to;
		ll val;
	}edge[N<<3];
	void add(int a,int b,ll c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,ll c){
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
	ll dfs(int u,ll limit){
		if(u==T)return limit;
		ll flow=0;
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
		if(!flow)dep[u]=-1;
		return flow;
	}
	ll Dinic(){
		ll maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
		}
		return maxflow;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	Maxflow::init(n+m+1,n+m+2);
	ll sum=0;
	for(int i=1;i<=n;++i){
		Maxflow::adde(m+i,Maxflow::T,a[i]);
	}
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		Maxflow::adde(Maxflow::S,i,w);
		Maxflow::adde(i,u+m,inf);
		Maxflow::adde(i,v+m,inf);
		sum+=w;
	}
	cout<<sum-Maxflow::Dinic()<<'\n';
	return 0;
}