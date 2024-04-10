#include <iostream>
#include <vector>

using namespace std;

struct graph {
	int cnt;
	int size;
	vector <bool> used;
	vector <vector <int>> list;

	graph(int n) {
		cnt = 0;
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
		cnt++;
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
	g.dfs(0);
	if (n == m && g.cnt == n) cout << "FHTAGN!";
	else cout << "NO";
	return 0;
}