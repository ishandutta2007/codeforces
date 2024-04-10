#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int mod;

void add(int& x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

void sub(int& x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
}

int dif(int x, int y) {
	sub(x, y);
	return x;
}

void mul(int& x, int y) {
	x = 1ll * x * y % mod;
}

int prod(int x, int y) {
	mul(x, y);
	return x;
}

const int N = 2022;
vector<int> a[N];

int dp[N][N];

void dfs(int v, int p = -1) {
	vector<int> sons;
	for (int u : a[v]) {
		if (u == p) {
			continue;
		}
		sons.push_back(u);
		dfs(u, v);
	}
	const int sz = sons.size();
	vector<int> old(sz);
	vector<int> prefp(sz + 1), sufp(sz + 1);

	for (int c = 0; c < N; ++c) {
		int p = 1;
		for (int u : sons) {
			mul(p, dp[u][c]);
		}
		dp[v][c] = p;
		for (int i = 0; i < sz; ++i) {
			int u = sons[i];
			add(dp[v][c], prod(dif(dp[u][c], c ? dp[u][c - 1] : 0), old[i]));
		}
		prefp[0] = 1;
		for (int i = 0; i < sz; ++i) {
			prefp[i + 1] = prod(prefp[i], dp[sons[i]][c]);
		}
		sufp[sz] = 1;
		for (int i = sz - 1; i >= 0; --i) {
			sufp[i] = prod(sufp[i + 1], dp[sons[i]][c]);
		}
		for (int i = 0; i < sz; ++i) {
			add(old[i], prod(prefp[i], sufp[i + 1]));
		}
	}

	for (int i = 1; i < N; ++i) {
		add(dp[v][i], dp[v][i - 1]);
	}
}

int C[N][N];

void solve() {
	int n = nxt();
	mod = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0);
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		cerr << dp[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }

	vector<int> res(n - 1, 1);
	for (int x : a[0]) {
		for (int i = 0; i < (int)res.size(); ++i) {
			mul(res[i], dp[x][i]);
		}
	}
	for (int i = (int)res.size() - 1; i > 0; --i) {
		sub(res[i], res[i - 1]);
	}
	// for (int x : res) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";

	C[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j];
			add(C[i][j], C[i - 1][j - 1]);
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		int ans = 0;
		for (int j = 0; j <= i; ++j) {
			int tmp = (j % 2 ? -1 : 1) * res[i - j];
			if (tmp < 0) {
				tmp += mod;
			}
			add(ans, prod(tmp, C[i][j]));
		}
		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}