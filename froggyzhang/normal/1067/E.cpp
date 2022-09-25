#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const int mod=998244353;
const int inv2=(mod+1)/2;
int n,ans,dp[N];
vector<int> G[N];
void dfs(int u,int fa){
	dp[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		dp[u]=1LL*dp[u]*(inv2+1LL*inv2*dp[v]%mod)%mod;	
	}
	dp[u]=(mod+1-dp[u])%mod;
	ans=(ans+dp[u])%mod;
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
	dfs(1,0);
	for(int i=1;i<=n;++i)(ans<<=1)%=mod;
	cout<<ans;
	return 0;
}