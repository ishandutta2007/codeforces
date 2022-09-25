#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m;
vector<pair<int,int> > G[N];
vector<int> p,H[N];
int dep[N],f[N],siz[N],top[N],son[N];
ll dt[N],dis[45][N];
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	siz[u]=1;
	for(auto [v,w]:G[u]){
		if(v==fa)continue;
		if(!dep[v]){
			dt[v]=dt[u]+w;
			dfs1(v,u);
			H[u].push_back(v);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])son[u]=v;
		}
		else if(dep[v]<dep[u]){
			p.push_back(v),p.push_back(u);
		}
	}	
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:H[u]){
		if(v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int u,int v){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=f[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;	
}
inline ll Dis(int u,int v){
	return dt[u]+dt[v]-(dt[LCA(u,v)]<<1);	
}
void Dijkstra(int S,ll *dis){
	static int vis[N];
	static priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	memset(dis,0x3f,sizeof(ll)*N);
	memset(vis,0,sizeof(vis));
	dis[S]=0;
	q.push(make_pair(0LL,S));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	dfs1(1,0);
	dfs2(1,1);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for(int i=0;i<(int)p.size();++i){
		Dijkstra(p[i],dis[i]);
	}
	int Q;
	cin>>Q;
	while(Q--){
		int u,v;
		cin>>u>>v;
		ll ans=Dis(u,v);
		for(int i=0;i<(int)p.size();++i){
			ans=min(ans,dis[i][u]+dis[i][v]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}