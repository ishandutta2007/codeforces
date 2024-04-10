#include<bits/stdc++.h>
using namespace std;
#define N 1001000
typedef long long ll;
int n,m,dep[N],vis[N],c[N],f[N],col[N];
int g[N];
vector<int> G[N];
vector<pair<int,int> > E;
void dfs1(int u){
	vis[u]=1;
	for(auto v:G[u]){
		if(vis[v]){
			if(dep[v]>dep[u]){
				E.emplace_back(u,v);
			}
			continue;
		}
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs1(v);
	}
}
void dfs2(int u){
	vis[u]=2;
	for(auto v:G[u]){
		if(vis[v]==2)continue;
		dfs2(v);
		c[u]+=c[v];
		g[u]+=g[v];
	}
}
pair<int,int> ban;
void dfs(int u){
	for(auto v:G[u]){
		if(make_pair(u,v)==ban||make_pair(v,u)==ban)continue;
		if(!~col[v]){
			col[v]=col[u]^1;
			dfs(v);
		}
	}
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)G[i].clear(),c[i]=f[i]=vis[i]=g[i]=0,col[i]=-1;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	E.clear();
	dfs1(1);
	int odd=0;
	for(auto [u,v]:E){
		if((dep[u]&1)^(dep[v]&1)){
			++g[v],--g[u];
		}
		else{
			++odd;
			++c[v],--c[u];
			ban=make_pair(v,u);
		}
	}
	dfs2(1);
	if(odd^1){
		ban=make_pair(-1,-1);
	}
	for(int i=1;i<=n;++i){
		if(c[i]==odd&&!g[i]){
			ban=make_pair(i,f[i]);
			break;
		}
	}
	if(!~ban.first){
		cout<<"NO\n";
		return;
	}
	col[ban.first]=1;
	dfs(ban.first);
	for(int i=1;i<=n;++i){
		if(!~col[i]){
			col[i]=0;
			dfs(i);
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;++i){
		cout<<col[i];
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}