#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), m = nxt();
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = nxt();
	}
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int mn;
	long long ans = 0;
	vector<char> used(n);

	function<void(int)> dfs = [&](int v) {
		if (used[v]) {
			return;
		}
		used[v] = 1;
		mn = min(mn, c[v]);
		for (int x : a[v]) {
			dfs(x);
		}
	};

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			mn = 1e9 + 10;
			dfs(i);
			ans += mn;
		}
	}

	printf("%lld\n", ans);

	return 0;
}