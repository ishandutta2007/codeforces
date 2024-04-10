#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = ll(1e9) + 7;

const int MAXN = 2e5;
int N;
ll M;

vector<int> adj[MAXN];

const int MAXX = 21;
ll K;
int X;

ll dp[MAXN][3][MAXX];

void dfs(int cur, int prv) {
	memset(dp[cur], 0, sizeof(dp[cur]));
	dp[cur][0][0] = (K-1) % MOD;
	dp[cur][1][1] = 1;
	dp[cur][2][0] = (M-K) % MOD;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);

		ll ndp[3][MAXX];
		memset(ndp, 0, sizeof(ndp));
		for (int i = X; i >= 0; i--) {
			for (int j = X-i; j >= 0; j--) {
				ndp[0][i+j] += dp[cur][0][i] * (dp[nxt][0][j] + dp[nxt][1][j] + dp[nxt][2][j]) % MOD;
				ndp[1][i+j] += dp[cur][1][i] * (dp[nxt][0][j]) % MOD;
				ndp[2][i+j] += dp[cur][2][i] * (dp[nxt][0][j] + dp[nxt][2][j]) % MOD;
			}
		}
		for (int i = X; i >= 0; i--) {
			dp[cur][0][i] = ndp[0][i] % MOD;
			dp[cur][1][i] = ndp[1][i] % MOD;
			dp[cur][2][i] = ndp[2][i] % MOD;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> K >> X;

	dfs(0, -1);
	ll res = 0;
	for (int i = 0; i <= X; i++) {
		res += dp[0][0][i];
		res += dp[0][1][i];
		res += dp[0][2][i];
		res %= MOD;
	}
	cout << res % MOD << '\n';
	return 0;
}