#include <iostream>
#include <vector>

using namespace std;

int cnt = 0, siz = 0;
vector <int> comp_siz, comp_pr;
vector <bool> used;
vector <vector <int>> g;

void dfs(int u) {
	used[u] = true;
	comp_pr[u] = cnt;
	siz++;
	for (auto to : g[u])
		if (!used[to])
			dfs(to);
}

int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	used.resize(n + 1);
	comp_pr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		if (k == 0)
			continue;
		int u;
		cin >> u;
		for (int j = 0; j < k - 1; j++) {
			int v;
			cin >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	for (int i = 1; i <= n; i++) 
		if (!used[i]) {
			siz = 0;
			dfs(i);
			comp_siz.push_back(siz);
			cnt++;
		}
	for (int i = 1; i <= n; i++)
		cout << comp_siz[comp_pr[i]] << " ";
		return 0;
}