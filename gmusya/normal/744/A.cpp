#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <bool> used, cap;
vector <pair <vector <int>, bool>> comp;
vector <vector <int>> g;

void dfs(int v, int pos) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u])
			dfs(u, pos);
	comp[pos].first.push_back(v);
	if (cap[v])
		comp[pos].second = 1;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	used.resize(n), g.resize(n), cap.resize(n);
	for (int i = 0; i < k; i++) {
		int u;
		cin >> u;
		u--;
		cap[u] = true;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			comp.push_back({});
			dfs(i, comp.size() - 1);
		}
	vector <int> a;
	vector <int> b;
	for (int i = 0; i < comp.size(); i++) {
		if (comp[i].second == 1)
			a.push_back(comp[i].first.size());
		else
			b.push_back(comp[i].first.size());
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i < b.size(); i++)
		a[0] += b[i];
	for (int i = 0; i < a.size(); i++)
		ans += (a[i] - 1) * a[i] / 2;
	cout << ans - m;
	return 0;
}