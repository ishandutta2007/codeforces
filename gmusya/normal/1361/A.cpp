#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	vector <int> c(n);
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		c[i] = a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	set <int> s;
	for (int i = 1; i <= n; i++)
		s.insert(i);
	vector <bool> used(n + 1);
	vector <bool> mex(n + 1);
	for (int i = 0; i < n; i++) {
		int v = a[i].second;
		used[v] = true;
		for (int u : g[v]) {
			if (!used[u]) continue;
			if (!mex[c[u]]) s.erase(c[u]);
			mex[c[u]] = true;
		}
		if (*s.begin() != c[v]) {
			cout << -1;
			return 0;
		}
		for (int u : g[v])
			if (used[u]) {
				s.insert(c[u]);
				mex[c[u]] = false;
			}
	}
	for (int i = 0; i < n; i++)
		cout << a[i].second + 1 << ' ';
	return 0;
}