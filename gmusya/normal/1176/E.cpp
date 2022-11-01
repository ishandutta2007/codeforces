#include <iostream>
#include <vector>

using namespace std;

vector <bool> used;
vector <int> red, blue, d;
vector <vector <int>> g;

void dfs(int v) {
	used[v] = true;
	for (int u : g[v]) 
		if (!used[u]) {
			d[u] = d[v] + 1;
			dfs(u);
		}
	if (d[v] % 2)
		red.push_back(v);
	else
		blue.push_back(v);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		g.assign(n, {});
		used.assign(n, false);
		d.assign(n, 0);
		red.resize(0), blue.resize(0);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0);
		if (red.size() < blue.size()) {
			cout << red.size() << endl;
			for (int v : red)
				cout << v + 1 << " ";
			cout << endl;
		}
		else {
			cout << blue.size() << endl;
			for (int v : blue)
				cout << v + 1 << " ";
			cout << endl;
		}
	}
	return 0;
}