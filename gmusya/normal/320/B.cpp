#include <iostream>
#include <vector>

using namespace std;

vector <bool> used(100);
vector <vector <int>> g(100);

void dfs(int u) {
	used[u] = true;
	for (int v : g[u])
		if (!used[v])
			dfs(v);
}

int main() {
	int q;
	cin >> q;
	vector <pair <int, int>> query;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, v;
			cin >> u >> v;
			query.push_back({ u, v });
			for (int j = 0; j < query.size() - 1; j++) {
				if ((query[j].first < u && u < query[j].second) || (query[j].first < v && v < query[j].second))
					g[query.size() - 1].push_back(j);
				if ((u < query[j].first  && query[j].first < v) || (u < query[j].second && query[j].second < v))
					g[j].push_back(query.size() - 1);
			}
		}
		if (t == 2) {
			used.assign(100, false);
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			dfs(a);
			if (used[b])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}