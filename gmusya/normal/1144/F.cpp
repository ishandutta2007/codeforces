#include <iostream>
#include <vector>

using namespace std;

bool tf = true;
vector <int> color;
vector <vector <int>> g;

void dfs(int v) {
	for (int u : g[v]) {
		if (color[u] == color[v])
			tf = false;
		if (color[u] == -1) {
			color[u] = 1 - color[v];
			dfs(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	color.resize(n, -1), g.resize(n);
	vector <pair <int, int>> b;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
		b.push_back({ u, v });
	}
	for (int i = 0; i < n; i++)
		if (color[i] == -1) {
			color[i] = 0;
			dfs(i);
		}
	if (!tf) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < m; i++)
		cout << color[b[i].first];
	return 0;
}