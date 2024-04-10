#include <iostream>
#include <vector>

using namespace std;

int n, timer = 0;
vector <bool> used;
vector <int> d, p;
vector <vector <int>> g;

void dfs(int v) {
	used[v] = true;
	for (auto to : g[v])
		if (!used[to]) {
			d[to] = d[v] + 1;
			p[to] = v;
			dfs(to);
		}
}

int main() {
	cin >> n;
	g.resize(n), used.resize(n), d.resize(n), p.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector <int> a(n), pos(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++)
		pos[a[i]] = i;
	dfs(0);
	bool tf = true;
	for (int i = 0; i < n - 1; i++)
		if (d[a[i]] > d[a[i + 1]])
			tf = false;
	for (int i = 0; i < n; i++)
	used.assign(n, false);
	for (int i = 0; i < n - 1; i++)
		if (pos[p[a[i]]] > pos[p[a[i + 1]]])
			tf = false;
	if (tf)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}