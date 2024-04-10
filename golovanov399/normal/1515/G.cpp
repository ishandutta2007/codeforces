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

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<pair<int, long long>>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		a[u].push_back({v, w});
	}

	vector<char> used(n, false);
	vector<vector<int>> comps;
	vector<int> h(n);
	vector<long long> ph(n);
	vector<long long> gcds(n);
	vector<int> st;
	int curh = 0;
	vector<int> color(n);
	int curcol = 0;
	vector<long long> gs;
	function<int(int)> dfs = [&](int v) {
		used[v] = 1;
		st.push_back(v);
		int res = h[v];
		for (auto [to, w] : a[v]) {
			if (!used[to]) {
				h[to] = curh++;
				ph[to] = ph[v] + w;
				res = min(res, dfs(to));
			} else if (used[to] == 1) {
				gcds[to] = gcd(gcds[to], ph[v] - ph[to] + w);
				res = min(res, h[to]);
			}
		}
		if (res == h[v]) {
			long long g = 0;
			while (true) {
				int u = st.back();
				st.pop_back();
				color[u] = curcol;
				if (gcds[u]) {
					g = gcd(g, gcds[u]);
				}
				used[u] = 2;
				if (u == v) {
					break;
				}
			}
			curcol += 1;
			gs.push_back(g);
		}
		return res;
	};
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			h[i] = curh++;
			dfs(i);
		}
	}

	int q = nxt();
	while (q--) {
		int v = nxt() - 1;
		long long s = nxt(), t = nxt();
		if (gs[color[v]] == 0) {
			cout << (s ? "NO" : "YES") << "\n";
		} else {
			cout << (s % gcd(gs[color[v]], t) ? "NO" : "YES") << "\n";
		}
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}