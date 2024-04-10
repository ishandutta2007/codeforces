#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int n, k;

void dfs(int v, vector <bool> &used, vector <ll> &k0, vector <ll> &k1, vector <vector <pair <int, ll>>> &g) {
	used[v] = true;
	vector <pair <ll, int>> tmp;
	for (auto now : g[v]) {
		int u = now.first;
		ll w = now.second;
		if (used[u]) continue;
		dfs(u, used, k0, k1, g);
		k1[v] += k0[u];
		k0[v] += k0[u];
		tmp.push_back({ k1[u] + w - k0[u], u });
	}
	sort(tmp.rbegin(), tmp.rend());
	for (int i = 0; i < k; i++) {
		if (i >= tmp.size()) break;
		if (tmp[i].first <= 0) continue;
		k0[v] += tmp[i].first;
		if (i < k - 1) k1[v] += tmp[i].first;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		vector <bool> used(n);
		vector <ll> k0(n), k1(n);
		vector <vector <pair <int, ll>>> g(n);
		for (int i = 1; i < n; i++) {
			int u, v;
			ll w;
			cin >> u >> v >> w;
			u--, v--;
			g[u].push_back({ v, w });
			g[v].push_back({ u, w });
		}
		dfs(0, used, k0, k1, g);
		cout << k0[0] << '\n';
	}
	return 0;
}