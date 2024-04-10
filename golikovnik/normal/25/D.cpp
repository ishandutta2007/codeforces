#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

struct DSU {
	vector<int> p, r;

	DSU (int n) {
		p.resize(n);
		r.resize(n);
		for (int i = 0; i < n; ++i) p[i] = i;
	}
	
	int get(int v) {
		if (v == p[v]) return v;
		return p[v] = get(p[v]);
	}

	void unite(int u, int v) {
		u = get(u); v = get(v);
		if (u == v) return;
		if (r[u] == r[v]) ++r[v];
		if (r[u] < r[v]) swap(u, v);
		p[v] = u;
	}

};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	DSU dsu(n);
	vector<pair<int, int>> del;
	vector<pair<int, int>> add;
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		if (dsu.get(u) == dsu.get(v)) {
			del.push_back(make_pair(u + 1, v + 1));
		} else {
			dsu.unite(u, v);
		}
	}
	for (int i = 1; i < n; ++i) {
		if (dsu.get(i) != dsu.get(0)) {
			dsu.unite(0, i);
			add.push_back(make_pair(1, i+1));
		}
	}
	cout << del.size() << endl;
	for (int i = 0; i < del.size(); ++i) {
		cout << del[i].first << " " << del[i].second << " " << add[i].first << " " << add[i].second << endl;
	}
	return 0;
}