#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
int n,m;
vector<pair<ll,int> >adj[100001];
vector<int>c[100001];
int par[100001][17];
ll dis[100001];
int d[100001];
bool vis[100001];
int ptr=0;
int spc[23];
ll dist[23][100001];
bool vist[23][100001];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
void dfs(int id){
	vis[id]=true;
	for(auto cur:adj[id]){
		if(cur.se==par[id][0]) continue;
		if(vis[cur.se] && d[cur.se]<d[id]){
			spc[++ptr]=id;
			continue;
		}
		if(vis[cur.se]) continue;
		d[cur.se]=d[id]+1;
		dis[cur.se]=dis[id]+cur.fi;
		par[cur.se][0]=id;
		for(int i=1; i<=16 ;i++) par[cur.se][i]=par[par[cur.se][i-1]][i-1];
		dfs(cur.se);
	}
}
int kth_anc(int id,int k){
	for(int i=16; i>=0 ;i--){
		if(k&(1<<i)) id=par[id][i];
	}
	return id;
}
int lca(int u,int v){
	if(d[u]>d[v]) swap(u,v);
	v=kth_anc(v,d[v]-d[u]);
	if(u==v) return u;
	for(int i=16; i>=0 ;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;
		ll w;
		cin >> u >> v >> w;
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	dfs(1);
	for(int i=1; i<=ptr ;i++){
		for(int j=1; j<=n ;j++) dist[i][j]=1e18;
		dist[i][spc[i]]=0;
		pq.push({0,spc[i]});
		while(!pq.empty()){
			while(!pq.empty() && vist[i][pq.top().se]) pq.pop();
			if(pq.empty()) break;
			int cur=pq.top().se;
			vist[i][cur]=true;
			pq.pop();
			for(auto newi:adj[cur]){
				if(dist[i][newi.se]>dist[i][cur]+newi.fi){
					dist[i][newi.se]=dist[i][cur]+newi.fi;
					pq.push({dist[i][newi.se],newi.se});
				}
			}
		}
	}
	
	int q;
	cin >> q;
	for(int i=1; i<=q ;i++){
		int u,v;
		cin >> u >> v;
		int z=lca(u,v);
		ll ans=dis[u]+dis[v]-dis[z]-dis[z];
		for(int j=1; j<=ptr ;j++) ans=min(ans,dist[j][u]+dist[j][v]);
		cout << ans << '\n';
	}
}