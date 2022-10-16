#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
int n,dp[N][N],mod,C[N][N],ans[N];
vector<int> G[N];
void init(int n){
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
void dfs(int u,int fa){
	static int g[N],h[N],pr[N];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		g[v]=h[v]=0;
	}
	for(int k=0;k<n-1;++k){
		dp[u][k]=1;
		for(auto v:G[u]){
			if(v==fa)continue;
			g[v]=(g[v]+dp[v][k])%mod;
			pr[v]=dp[u][k];
			dp[u][k]=1LL*dp[u][k]*g[v]%mod;
		}
		if(fa>0){
			for(auto v:G[u]){
				if(v==fa)continue;
				dp[u][k]=(dp[u][k]+1LL*dp[v][k]*h[v])%mod;
			}
			int zz=1;
			for(int i=(int)G[u].size()-1;i>=0;--i){
				int v=G[u][i];
				if(v==fa)continue;
				h[v]=(h[v]+1LL*pr[v]*zz)%mod;
				zz=1LL*zz*g[v]%mod;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>mod;
	init(n);
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<n;++i){
		ans[i]=dp[1][i-1];
		for(int j=1;j<i;++j){
			ans[i]=(ans[i]+1LL*(mod-ans[j])*C[i][j])%mod;
		}
	}
	for(int i=1;i<n;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}