#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,k;
ll dp[500001],dp2[500001];
vector<pair<ll,int> >adj[500001];
vector<ll>vk[500001];
void dfs(int id,int p){
	for(auto cur:adj[id]){
		if(cur.se==p) continue;
		dfs(cur.se,id);
		vk[id].push_back(max(0LL,dp2[cur.se]+cur.fi-dp[cur.se]));
		dp[id]+=dp[cur.se];
		dp2[id]+=dp[cur.se];
	}
	sort(vk[id].begin(),vk[id].end());
	reverse(vk[id].begin(),vk[id].end());
	for(int i=0; i<min(k-1,(int)vk[id].size()) ;i++){
		dp2[id]+=vk[id][i];
	}
	for(int i=0; i<min(k,(int)vk[id].size()) ;i++){
		dp[id]+=vk[id][i];
	}
}
void solve(){
	cin >> n >> k;
	for(int i=1; i<=n ;i++) adj[i].clear(),vk[i].clear();
	for(int i=1; i<n ;i++){
		int u,v;ll w;cin >> u >> v >> w;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
		dp[i]=dp2[i]=0;
	}
	dp[n]=dp2[n]=0;
	dfs(1,0);
	cout << dp[1] << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int q;cin >> q;while(q--) solve();
}