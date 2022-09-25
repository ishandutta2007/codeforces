#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
vector<pair<int,int> > G[N];
ll dis[N];
int S,n,m;
void Dijkstra(int S){
	static bool vis[N];
	memset(vis,false,sizeof(vis));
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	q.emplace(0LL,S);
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.emplace(dis[v],v);
			}
		}
	}
}
vector<int> H[N];
int f[N],ff[N][19],dep[N];
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=18;i>=0;--i){
		if(dep[ff[u][i]]>=dep[v])u=ff[u][i];	
	}
	if(u==v)return u;
	for(int i=18;i>=0;--i){
		if(ff[u][i]^ff[v][i])u=ff[u][i],v=ff[v][i];
	}
	return f[u];
}
int siz[N],ans;
void dfs(int u){
	siz[u]=1;
	for(auto v:H[u]){
		dfs(v);
		siz[u]+=siz[v];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>S;
	for(int i=1;i<=m;++i){
		int u,v,w; 
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	Dijkstra(S);
	queue<int> q;
	static int d[N];
	for(int u=1;u<=n;++u){
		for(auto [v,w]:G[u]){
			if(dis[v]==dis[u]+w)++d[v];
		}	
	}
	q.push(S);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		H[f[u]].push_back(u);
		dep[u]=dep[f[u]]+1;
		ff[u][0]=f[u];
		for(int j=1;j<=18;++j){
			ff[u][j]=ff[ff[u][j-1]][j-1];
		}
		for(auto [v,w]:G[u]){
			if(dis[v]==dis[u]+w){
				f[v]=!f[v]?u:LCA(f[v],u);
				if(!--d[v])q.push(v);
			}	
		}
	}
	dfs(S);
	for(int i=1;i<=n;++i){
		if(i==S)continue;
		ans=max(ans,siz[i]);	
	}
	cout<<ans<<'\n';
	return 0;
}