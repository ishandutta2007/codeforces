#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int N = 202'202;
vector<pair<int, int>> a[N];
vector<pair<int, int>> g[N];

void solve() {
	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		a[i].clear();
		g[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		int w = nxt();
		a[u].push_back({v, w});
		a[v].push_back({u, w});
		if (~w) {
			g[u].push_back({v, __builtin_parity(w)});
			g[v].push_back({u, __builtin_parity(w)});
		}
	}
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, p = nxt();
		g[u].push_back({v, p});
		g[v].push_back({u, p});
	}

	vector<int> color(n, -1);
	for (int i = 0; i < n; ++i) {
		if (~color[i]) {
			continue;
		}
		color[i] = 0;
		vector<int> st = {i};
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			for (auto [x, p] : g[v]) {
				if (~color[x]) {
					if (color[x] != (color[v] ^ p)) {
						cout << "NO\n";
						return;
					}
				} else {
					color[x] = color[v] ^ p;
					st.push_back(x);
				}
			}
		}
	}
	cout << "YES\n";
	function<void(int, int)> rec = [&](int v, int p) {
		for (auto& [u, w] : a[v]) {
			if (u == p) {
				continue;
			}
			if (w == -1) {
				w = color[u] ^ color[v];
			}
			cout << v + 1 << " " << u + 1 << " " << w << "\n";
			rec(u, v);
		}
	};
	rec(0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}