#include <iostream>
#include <vector>

using namespace std;

struct graph {
	int edges, vertices;
	int size;
	vector <bool> used;
	vector <vector <int>> list;

	graph(int n) {
		edges = vertices = 0;
		size = n;
		used.resize(n);
		list.resize(n);
	}

	void read(int m) {
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			list[u].push_back(v), list[v].push_back(u);
		}
	}

	void dfs(int v) {
		edges += list[v].size();
		vertices++;
		used[v] = true;
		for (int u : list[v])
			if (!used[u])
				dfs(u);
	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	graph g(n);
	g.read(m);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!g.used[i]) {
			g.vertices = g.edges = 0;
			g.dfs(i);
			g.edges /= 2;
			ans += (g.vertices == g.edges + 1);
		}
	}
	cout << ans;
	return 0;
}