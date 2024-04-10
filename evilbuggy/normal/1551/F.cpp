#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int mod = 1000000007;

int dp[N][N], cnt[N];
vector<int> g[N];

void dfs(int v, int p, int d){
	cnt[d]++;
	for(int u : g[v]){
		if(u != p)dfs(u, v, d + 1);
	}
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		for(int i = 2; i <= n; i++){
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		if(k == 2){
			cout << n*(n - 1)/2 << '\n';
			continue;
		}
		int answer = 0;
		for(int root = 1; root <= n; root++){
			if(g[root].size() < k)continue;
			memset(dp, 0, sizeof(dp));
			for(int d = 1; d <= n; d++){
				dp[d][0] = 1;
			}
			for(int v : g[root]){
				memset(cnt, 0, sizeof(cnt));
				dfs(v, root, 1);
				for(int d = 1; d <= n; d++){
					for(int cur = k - 1; cur >= 0; cur--){
						add(dp[d][cur + 1], dp[d][cur]*1LL*cnt[d]%mod);
					}
				}
			}
			for(int d = 1; d <= n; d++){
				add(answer, dp[d][k]);
			}
		}
		cout << answer << '\n';
	}

	return 0;
}