#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <bool> used;
vector <int> d, answer;
vector <vector <pair <int, int>>> g;

void dfs(int u) {
	used[u] = true;
	for (auto v : g[u]) {
		if (!used[v.first]) {
			dfs(v.first);
			if (v.second == 2) {
				d[u] += max(d[v.first], 1);
				if (d[v.first] == 0)
					answer.push_back(v.first);
			}
			else
				d[u] += d[v.first];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	g.resize(n), d.resize(n), used.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		u--;
		v--;
		g[u].push_back({ v, t });
		g[v].push_back({ u, t });
	}
	dfs(0);
	cout << d[0] << endl;
	for (auto now : answer)
		cout << now + 1 << " ";
	return 0;
}