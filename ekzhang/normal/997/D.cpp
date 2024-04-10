#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 4003
#define MAXL 40
#define MOD 998244353
int N, K;
vector<int> adj[MAXN];
LL C1[MAXL], C2[MAXL];
LL* C;
LL dp[MAXN][MAXL];
LL dpp[MAXN][MAXL];
LL dp2[MAXN][MAXL];
LL temp[MAXN][MAXL];

void nap(LL* A, LL* B) {
	// knapsack
	B[0] = A[0];
	assert(B[0] == 1);
	for (int i = 1; i <= K; i++) {
		B[i] = 0;
		for (int j = 1; j <= i; j++)
			B[i] = (B[i] + A[j] * B[i - j]) % MOD;
	}
}

void dfs_down(int n, int p) {
	dp[n][0] = 1;
	for (int v : adj[n]) if (v != p) {
		dfs_down(v, n);
		for (int k = 1; k <= K; k++)
			dp[n][k] = (dp[n][k] + dpp[v][k - 1]) % MOD;
	}
	nap(dp[n], dpp[n]);
}

void dfs_up(int n, int p) {
	if (p != -1) {
		temp[n][0] = 1;
		for (int k = 1; k <= K; k++)
			temp[n][k] = (dp2[p][k] + dp[p][k] - dpp[n][k-1] + MOD) % MOD;
		nap(temp[n], dp2[n]);
		for (int k = K; k >= 0; k--)
			dp2[n][k] = k ? dp2[n][k - 1] : 0;
	}
	for (int v : adj[n]) if (v != p) {
		dfs_up(v, n);
	}
}

void solve() {
	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// calculate num cycles of each length
	memset(dp, 0, sizeof dp);
	dfs_down(0, -1);
	dfs_up(0, -1);
	for (int i = 0; i < N; i++) {
		for (int k = 0; k <= K; k++)
			dp[i][k] += dp2[i][k];
		nap(dp[i], dpp[i]);
		for (int k = 0; k <= K; k++)
			C[k] = (C[k] + dpp[i][k]) % MOD;
	}
}

inline LL mpow(LL a, LL b) {
	return b ? mpow((a*a)%MOD, b>>1) * (b % 2 ? a : 1) % MOD : 1;
}

inline LL minv(LL n) {
	return mpow(n, MOD - 2);
}

LL binom(int n, int k) {
	LL ret = 1;
	for (int i = 1; i <= k; i++) {
		ret = (ret * (n - i + 1)) % MOD;
		ret = (ret * minv(i)) % MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	int N1, N2;
	cin >> N1 >> N2 >> K;
	if (K % 2)
		return cout << 0 << endl, 0;
	K /= 2;

	N = N1, C = C1;
	solve();

	for (int i = 0; i < N; i++)
		adj[i].clear();

	N = N2, C = C2;
	solve();

	LL ans = 0;
	for (int i = 0; i <= K; i++) {
		LL cur = binom(2 * K, 2 * i);
		cur = (cur * C2[i]) % MOD;
		cur = (cur * C1[K - i]) % MOD;
		ans = (ans + cur) % MOD;
	}

	cout << ans << endl;
	return 0;
}