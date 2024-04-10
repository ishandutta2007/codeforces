#include <iostream>
#include <vector>

using namespace std;

int n, m, col;
vector <int> used(n);
vector <vector <vector <int>>> g;
	
void dfs(int u) {
	used[u] = true;
	if (g[col][u].size() > 0)
		for (auto to : g[col][u])
			if (!used[to])
				dfs(to);
}

int main() {
	cin >> n >> m;
	g.resize(m);
	for (int i = 0; i < m; i++)
		g[i].resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		c--;
		g[c][a].push_back(b);
		g[c][b].push_back(a);
	}
	vector <int> ans;
	int t;
	cin >> t;
	while (t--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		int cnt = 0;
		for (col = 0; col < m; col++) {
			used.resize(0);
			used.resize(n);
			dfs(u);
			cnt += used[v];
		}
		ans.push_back(cnt);
	}
	for (auto now : ans)
		cout << now << '\n';
	return 0;
}