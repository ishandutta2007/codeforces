#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <set <int>> g(n);
	vector <pair <int, int>> e;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e.push_back({ u, v });
		g[u].insert(v), g[v].insert(u);
	}
	int A = 0, B = -1, C = -1;
	for (int i = 0; i < n; i++) {
		if (g[A].find(i) != g[A].end()) {
			B = i;
			break;
		}
	}
	if (B == -1) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (g[A].find(i) != g[A].end() && g[B].find(i) != g[B].end()) {
			C = i;
			break;
		}
	}
	if (C == -1) {
		cout << -1;
		return 0;
	}
	vector <int> color(n);
	for (int i = 0; i < n; i++) {
		int cnt = (g[A].find(i) == g[A].end()) + (g[B].find(i) == g[B].end()) + (g[C].find(i) == g[C].end());
		if (cnt != 1) {
			cout << -1;
			return 0;
		}
		if (g[A].find(i) == g[A].end()) {
			color[i] = 1;
			if (g[A].size() < g[i].size()) {
				swap(g[A], g[i]);
				for (auto val : g[i])
					g[A].insert(val);
			}
			continue;
		}
		if (g[B].find(i) == g[B].end()) {
			if (g[B].size() < g[i].size()) {
				swap(g[B], g[i]);
				for (auto val : g[i])
					g[B].insert(val);
			}
			color[i] = 2;
			continue;
		}
		if (g[C].find(i) == g[C].end()) {
			if (g[C].size() < g[i].size()) {
				swap(g[C], g[i]);
				for (auto val : g[i])
					g[C].insert(val);
			}
			color[i] = 3;
			continue;
		}
	}
	for (auto now : e) {
		int u = now.first, v = now.second;
		if (color[u] == color[v]) {
			cout << -1;
			return 0;
		}
	}
	int cntA = 0, cntB = 0, cntC = 0;
	for (int i = 0; i < n; i++) {
		if (color[i] == 1) cntA++;
		if (color[i] == 2) cntB++;
		if (color[i] == 3) cntC++;
	}
	for (int i = 0; i < n; i++) {
		int sz1 = g[i].size();
		int sz2 = 0;
		if (color[i] == 1) sz2 = cntB + cntC;
		if (color[i] == 2) sz2 = cntA + cntC;
		if (color[i] == 3) sz2 = cntA + cntB;
		if (sz1 != sz2) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		cout << color[i] << " ";
	return 0;
}