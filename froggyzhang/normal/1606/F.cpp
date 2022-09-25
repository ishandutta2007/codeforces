#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef pair<int,int> pii;
int n,m,ans[N],sons[N],f[N];
vector<int> G[N],dp[N];
vector<pii> q[N];
void dfs(int u){
	dp[u].resize(sons[u]);
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs(v);
		dp[u].resize(max(dp[u].size(),dp[v].size()));
		for(int i=0;i<(int)dp[v].size();++i){
			dp[u][i]+=dp[v][i]-1;
		}
	}
	for(auto [k,id]:q[u]){
		if(k<dp[u].size()){
			ans[id]+=dp[u][k];
		}
	}
	for(int i=0;i<(int)dp[u].size();++i){
		dp[u][i]+=sons[u]-i;
	}
	while(!dp[u].empty()&&dp[u].back()<=0)dp[u].pop_back();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		sons[i]=G[i].size()-(i!=1);
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		int v,k;
		cin>>v>>k;
		q[v].emplace_back(k,i);
		ans[i]+=sons[v];
	}
	dfs(1);
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<'\n';	
	}
	return 0;
}