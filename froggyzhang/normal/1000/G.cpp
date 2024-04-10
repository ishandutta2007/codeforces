#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,Q,a[N];
vector<pair<int,int> > G[N];
int dep[N],f[N],son[N],top[N],siz[N];
ll dis[N],sw[N],dp[N],D[N],g[N],U[N],sdp[N],sD[N];
void dfs1(int u){
	siz[u]=1;
	sw[u]=sw[f[u]]+a[u];
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dis[v]=dis[u]+w;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}	
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto [v,w]:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
void dfs3(int u){
	dp[u]=a[u];
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		dfs3(v);
		dp[u]+=D[v]=max(0LL,dp[v]-2*w);
	}
}
void dfs4(int u){
	sdp[u]=sdp[f[u]]+dp[u];
	sD[u]=sD[f[u]]+D[u];
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		g[v]=dp[v]+(U[v]=max(0LL,g[u]-D[v]-2*w));
		dfs4(v);
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	dfs1(1);
	dfs2(1,1);
	dfs3(1);
	g[1]=dp[1];
	dfs4(1);
	while(Q--){
		int u,v;
		cin>>u>>v;
		int z=LCA(u,v);
		ll ans=sdp[u]+sdp[v]-sdp[z]-sdp[f[z]];
		ans-=sD[u]+sD[v]-(sD[z]<<1);
		ans-=dis[u]+dis[v]-(dis[z]<<1);
		ans+=U[z];
		cout<<ans<<'\n';
	}
	return 0;
}