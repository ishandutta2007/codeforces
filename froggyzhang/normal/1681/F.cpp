#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,g[N],siz[N],ff[N];
vector<pair<int,int> > G[N];
vector<int> A[N];
ll ans;
void dfs(int u,int fa){
	siz[u]=1;
	for(auto [v,w]:G[u]){
		if(v==fa)continue;
		ff[v]=A[w].back();
		A[w].push_back(v);
		dfs(v,u);
		siz[u]+=siz[v];
		g[v]+=siz[v];
		g[ff[v]]-=siz[v];
		A[w].pop_back();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	for(int i=1;i<=n;++i){
		A[i].push_back(n+i);
		g[n+i]=n;
	}
	dfs(1,0);
	for(int i=2;i<=n;++i){
		ans+=1LL*g[i]*g[ff[i]];
	}
	cout<<ans<<'\n';
	return 0;
}