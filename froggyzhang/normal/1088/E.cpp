#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
ll ans;
int n,cnt,a[N];
vector<int> G[N];
ll dp[N];
void dfs1(int u,int fa){
	dp[u]=a[u];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u);
		dp[u]+=max(0LL,dp[v]);	
	}
	ans=max(dp[u],ans);
}
void dfs2(int u,int fa){
	dp[u]=a[u];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs2(v,u);
		dp[u]+=max(0LL,dp[v]);	
	}
	if(dp[u]==ans)++cnt,dp[u]=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans=-1e18;
	dfs1(1,0);
	dfs2(1,0);
	cout<<ans*cnt<<' '<<cnt<<'\n';
	return 0;
}