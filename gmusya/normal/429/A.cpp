#include <iostream>
#include <vector>

using namespace std;

vector <bool> used;
vector <int> a, b, ans;
vector <vector <int>> g, gg;

void dfs1(int v, int p) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u]) {
			if (p != -1) gg[p].push_back(u);
			dfs1(u, v);
		}
}

void dfs2(int v, int val) {
	a[v] ^= val;
	if (a[v] != b[v]) {
		ans.push_back(v + 1);
		a[v] ^= 1;
		val ^= 1;
	}
	for (int u : gg[v]) 
		dfs2(u, val);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	used.resize(n), a.resize(n), b.resize(n), g.resize(n), gg.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs1(0, -1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	dfs2(0, 0);
	for (int u : g[0])
		dfs2(u, 0);
	cout << ans.size() << endl;
	for (auto x : ans)
		cout << x << endl;
	return 0;
}