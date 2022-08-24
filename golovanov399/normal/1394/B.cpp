#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

unsigned long long big_rand() {
	return (rand() << 32) | rand();
}

void solve() {
	int n = nxt(), m = nxt(), k = nxt();
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt() - 1;
		edges[w] = {u, v};
	}
	vector<vector<int>> a(n);
	for (auto [u, v] : edges) {
		a[u].push_back(v);
	}
	vector<unsigned long long> huice(n);
	generate(all(huice), big_rand);
	vector<vector<unsigned long long>> hashes(k + 1);
	for (int i = 0; i <= k; ++i) {
		hashes[i].assign(i, 0);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			hashes[a[i].size()][j] += huice[a[i][j]];
		}
	}
	unsigned long long need = accumulate(all(huice), 0ull);
	vector<int> c(k + 1);
	int ans = 0;
	while (!c[0]) {
		unsigned long long cur = 0;
		for (int i = 1; i <= k; ++i) {
			cur += hashes[i][c[i]];
		}
		if (cur == need) {
			++ans;
		}
		c[k] += 1;
		for (int i = k; i > 0 && c[i] == i; --i) {
			c[i] = 0;
			c[i - 1] += 1;
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}