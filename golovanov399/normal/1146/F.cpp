#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;

const int N = 222222;
vector<int> to[N];

long long dp[N][3];

void dfs(int v) {
	for (int x : to[v]) {
		dfs(x);
	}

	if (to[v].empty()) {
		dp[v][2] = 1;
		return;
	}

	dp[v][0] = 1;
	vector<long long> cnt;
	for (int x : to[v]) {
		cnt.push_back(dp[x][0] + dp[x][2]);
		dp[v][0] = dp[v][0] * cnt.back() % mod;
	}

	int sz = cnt.size();
	vector<long long> pref(sz + 1, 1), suf(sz + 1, 1);
	for (int i = 0; i < sz; ++i) {
		pref[i + 1] = pref[i] * cnt[i] % mod;
	}
	for (int i = sz - 1; i >= 0; --i) {
		suf[i] = suf[i + 1] * cnt[i] % mod;
	}

	for (int i = 0; i < sz; ++i) {
		dp[v][1] += (dp[to[v][i]][1] + dp[to[v][i]][2]) * pref[i] % mod * suf[i + 1] % mod;
	}
	dp[v][1] %= mod;

	dp[v][2] = 1;
	for (int x : to[v]) {
		long long tmp = (accumulate(dp[x], dp[x] + 3, 0ll) + dp[x][2]) % mod;
		dp[v][2] = dp[v][2] * tmp % mod;
	}
	dp[v][2] -= dp[v][1] + dp[v][0];
	dp[v][2] %= mod;
	if (dp[v][2] < 0) {
		dp[v][2] += mod;
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		to[nxt() - 1].push_back(i + 1);
	}

	dfs(0);
	cout << (dp[0][0] + dp[0][2]) % mod << "\n";

	return 0;
}