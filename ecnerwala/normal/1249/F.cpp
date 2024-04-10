#include<bits/stdc++.h>
using namespace std;

const int MAXN = 210;
int N, K;
int A[MAXN];
vector<int> adj[MAXN];
vector<int> dp[MAXN];

void dfs(int cur, int prv) {
	dp[cur] = vector<int>({A[cur]});
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);

		dp[nxt].insert(dp[nxt].begin(), 0);
		vector<int> ndp(max(dp[cur].size(), dp[nxt].size()));
		for (int i = 0; i < int(dp[cur].size()); i++) {
			ndp[i] = max(ndp[i], dp[cur][i]);
		}
		for (int j = 0; j < int(dp[nxt].size()); j++) {
			ndp[j] = max(ndp[j], dp[nxt][j]);
		}
		// merge the two
		for (int i = 0; i < int(dp[cur].size()); i++) {
			for (int j = 0; j < int(dp[nxt].size()); j++) {
				if (i + j <= K) {
					continue;
				}
				ndp[min(i,j)] = max(ndp[min(i,j)], dp[cur][i] + dp[nxt][j]);
			}
		}
		for (int i = int(ndp.size()) - 1; i >= 1; i--) {
			ndp[i-1] = max(ndp[i-1], ndp[i]);
		}
		dp[cur] = std::move(ndp);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, -1);
	cout << dp[0][0] << '\n';

	return 0;
}