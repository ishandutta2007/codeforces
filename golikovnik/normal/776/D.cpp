#include <bits/stdc++.h>

// #define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<int> used;
vector<vector<pair<int, int>>> graph;
vector<int> color;

bool dfs(int u, int c = 0) {
	used[u] = 1;
	color[u] = c;
	bool ok = 1;
	for (auto &vv: graph[u]) {
		int v = vv.first;
		int state = vv.second;
		int need_color = c ^ state;
		if (used[v]) {
			ok &= color[v] == need_color;
		} else {
			ok &= dfs(v, need_color);
		}
	}
	return ok;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	graph.resize(m);
	used.resize(m);
	color.resize(m);
	vector<int> r(n);
	for (int &x: r) cin >> x;
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int x, room;
		cin >> x;
		while (x--) {
			cin >> room;
			a[room - 1].push_back(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		int x = a[i][0];
		int y = a[i][1];
		r[i] ^= 1;
		graph[x].emplace_back(y, r[i]);
		graph[y].emplace_back(x, r[i]);
	}
	bool ok = 1;
	for (int i = 0; i < m; ++i) {
		if (!used[i]) {
			ok &= dfs(i);
		}
	}
	cout << (ok ? "YES" : "NO");
	return 0;	
}