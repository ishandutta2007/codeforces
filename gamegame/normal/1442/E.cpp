#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e5+1;
int n;
vector<int>adj[N];
int dp[N][2];
int a[N];
int ans=0;
void dfs(int id,int p){
	int mx[2];
	mx[0]=0,mx[1]=0;
	if(a[id]!=0) dp[id][a[id]-1]=1;
	for(auto c:adj[id]){
		if(c==p) continue;
		dfs(c,id);
		
		dp[id][0]=max(dp[id][0],dp[c][0]);
		dp[id][1]=max(dp[id][1],dp[c][1]);
		if(a[id]!=0) dp[id][a[id]-1]=max(dp[id][a[id]-1],dp[c][2-a[id]]+1);
		ans=max(ans,mx[0]+dp[c][1]);
		ans=max(ans,mx[1]+dp[c][0]);
		if(a[id]!=0) ans=max(ans,mx[2-a[id]]+dp[c][2-a[id]]+1);
		mx[0]=max(mx[0],dp[c][0]);
		mx[1]=max(mx[1],dp[c][1]);
	}
	//cout << id << ' ' << dp[id][0] << ' ' << dp[id][1] << endl;
}
void solve(){
	cin >> n;ans=1;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		adj[i].clear();adj[i].shrink_to_fit();
		dp[i][0]=dp[i][1]=0;
	}
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	cout << (ans+2)/2 << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}