#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

vector <int> dsu, sz;
int ans;

pair <int, int> get(int v) {
	if (dsu[v] == v) return { dsu[v], sz[v] };
	auto tmp = get(dsu[v]);
	dsu[v] = tmp.first, sz[v] = tmp.second;
	return { dsu[v], sz[v] };
}

void merge(int u, int v) {
	u = get(u).first;
	v = get(v).first;
	if (sz[u] > sz[v]) swap(u, v);
	dsu[u] = v, sz[v] = sz[v] + sz[u];
	ans--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	ans = n - 1;
	vector <vector <int>> g(n);
	dsu.resize(n), sz.resize(n, 1);
	iota(dsu.begin(), dsu.end(), 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[v].push_back(u), g[u].push_back(v);
	}
	set <int> s;
	vector <int> cnt(n);
	for (int i = 0; i < n; i++)
		s.insert(i);
	for (int v = 0; v < n; v++) {
		for (int u : g[v]) {
			if (u > v) continue;
			cnt[get(u).first]++;
		}
		vector <int> tomerge;
		for (int u : s) {
			if (u >= v) break;
			if (cnt[u] != sz[u]) tomerge.push_back(u);
		}
		for (int u : g[v])
			cnt[get(u).first] = 0;
		for (int u : tomerge) 
			merge(u, v);
		for (int u : tomerge)
			s.erase(u);
		s.erase(v);
		s.insert(get(v).first);
	}
	cout << ans;
	return 0;
}