#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 200020
typedef long long ll;
int n,f[N];
ll l[N],r[N];
vector<int> G[N];
int dp[N];
ll g[N];
void dfs(int u){
	dp[u]=0,g[u]=0;
	for(auto v:G[u]){
		dfs(v);
		dp[u]+=dp[v];
		g[u]+=g[v];
	}
	if(g[u]<l[u]){
		++dp[u],g[u]=r[u];
	}
	else{
		g[u]=min(g[u],r[u]);
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=2;i<=n;++i){
		cin>>f[i];
		G[f[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		cin>>l[i]>>r[i];
	}
	dfs(1);
	cout<<dp[1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}