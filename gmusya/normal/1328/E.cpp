#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int timer = 0;
vector <bool> used;
vector <int> tin, tout, d, p;
vector <vector <int>> g;

void dfs(int v) {
	used[v] = true;
	tin[v] = timer++;
	for (int u : g[v])
		if (!used[u]) {
			p[u] = v;
			d[u] = d[v] + 1;
			dfs(u);
		}
	tout[v] = timer++;
}

bool cmp(int u, int v) {
	return d[u] < d[v];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	used.resize(n), tin.resize(n), tout.resize(n), d.resize(n), p.resize(n); g.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(0);
	while (q--) {
		int sz;
		cin >> sz;
		vector <int> a(sz);
		for (int i = 0; i < sz; i++) {
			cin >> a[i];
			a[i]--;
			a[i] = p[a[i]];
		}
		sort(a.begin(), a.end(), cmp);
		bool tf = true;
		for (int i = 0; i < sz - 1; i++) {
			int v = a[i], u = a[i + 1];
			if (tin[v] > tin[u] || tout[v] < tout[u])
				tf = false;
		}
		if (tf) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}