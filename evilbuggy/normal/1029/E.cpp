#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;

int dp[maxN][2][2];
vector<int> g[maxN];

void dfs(int v, int p){
	dp[v][0][0] = 0;
	dp[v][0][1] = 1;
	dp[v][1][0] = 0;
	dp[v][1][1] = 1;
	vector<int> vec;
	for(int u : g[v]){
		if(u != p){
			dfs(u, v);
			dp[v][0][0] += dp[u][0][1];
			vec.emplace_back(dp[u][0][0] - dp[u][0][1]);
			dp[v][1][0] += min(dp[u][0][0], dp[u][0][1]);
			dp[v][1][1] += min(dp[u][1][0], dp[u][1][1]);
			dp[v][0][1] += min(dp[u][1][0], dp[u][1][1]);			
		}
	}
	if(vec.empty()){
		dp[v][0][0] = (int)1e9;
		return;
	}
	
	sort(vec.begin(), vec.end());
	vec.pop_back();

	for(auto x : vec){
		if(x < 0){
			dp[v][0][0] += x;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 1);
	int ans = 0;
	for(int u : g[1]){
		ans += dp[u][0][1] - 1;
	}
	cout << ans << '\n';

	return 0;
}