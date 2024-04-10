#include<bits/stdc++.h>
using namespace std;
#define N 300010
typedef long long ll;
int n,w[N],ans,dp[N];
vector<int> G[N];
void dfs(int u,int fa){
	dp[u]=w[u];
	ans=max(ans,dp[u]);
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		ans=max(ans,dp[u]+dp[v]);
		dp[u]=max(dp[u],dp[v]+w[u]);
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);	
	}
	for(int i=1;i<=n;++i){
		w[i]=(int)G[i].size()-1;
	}
	ans=0;
	dfs(1,0);
	printf("%d\n",ans+2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}