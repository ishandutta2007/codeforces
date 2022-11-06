#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct Tree {
	int n, k;
	vector<vector<int>> sons;
	vector<int> s;
	vector<map<int, LL>> f;
	Tree(int _n, int _k) : n(_n), k(_k), sons(n + 1), s(n + 1), f(n + 1) {
		for (int i = 2; i <= n; i++) {
			int p;
			cin >> p;
			sons[p].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}
	}
	LL solve() {
		solve(1, k, k);
		return f[1][k];
	}
	void solve(int v, int l, int r) {
		int sz = sons[v].size();
		if (sz) {
			int nl = l / sz, nr = (r + sz - 1ll) / sz;
			for (auto u : sons[v]) {
				solve(u, nl, nr);
			}
			for (int i = l; i <= r; i++) {
				int xl = i / sz, xr = (i + sz - 1ll) / sz;
				if (xl == xr) {
					LL sum = 0;
					for (auto u : sons[v]) {
						sum += f[u][xl];
					}
					f[v][i] = sum + 1ll * i * s[v];
				} else {
					vector<LL> now;
					now.reserve(sz);
					LL sum = 0;
					for (auto u : sons[v]) {
						sum += f[u][xl];
						now.push_back(f[u][xr] - f[u][xl]);
					}
					sort(now.begin(), now.end(), greater<LL>());
					for (int j = 0; j < i % sz; j++) {
						sum += now[j];
					}
					f[v][i] = sum + 1ll * i * s[v];
				}
			}
		} else {
			for (int i = l; i <= r; i++) {
				f[v][i] = 1ll * i * s[v];
			}
		}
	}
};

void solve() {
	int n, k;
	cin >> n >> k;
	Tree t(n, k);
	printf("%lld\n", t.solve());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}