#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 1;

int n, m, T;
vector <bool> ach, used;
vector <int> deg;
vector <pair <int, int>> e;
vector <vector <pair <int, int>>> g;
vector <vector <pair <int, int>>> ans;

void dfs_ach(int v) {
	ach[v] = true;
	for (auto u : g[v])
		if (!ach[u.first])
			dfs_ach(u.first);
}

void cnt_deg() {
	for (int i = 0; i < e.size(); i++)
		deg[e[i].second] += (ach[e[i].first]);
}

void dfs_ans(int v) {
	used[v] = true;
	for (auto now : g[v]) {
		int u = now.first;
		int w = now.second;
		for (int i = 1; i < n; i++)
			ans[u][i] = min(ans[u][i], { ans[v][i - 1].first + w, v });
		deg[u]--;
	}
	for (auto now : g[v]) {
		int u = now.first;
		if (!used[u] && deg[u] == 0)
			dfs_ans(u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> T;
	used.resize(n), ach.resize(n), deg.resize(n), g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		int w;
		cin >> u >> v >> w;
		u--, v--;
		e.push_back({ u, v });
		g[u].push_back({ v, w });
	}
	ans.resize(n, vector <pair <int, int>>(n, { INF, -1 }));
	dfs_ach(0);
	cnt_deg();
	ans[0][0] = { 0, -1 };
	dfs_ans(0);
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--)
		if (ans[n - 1][i].first <= T) {
			cnt = i;
			break;
		}
	cout << cnt + 1 << endl;
	int pos = n - 1;
	vector <int> write;
	while (cnt != -1) {
		write.push_back(pos + 1);
		pos = ans[pos][cnt].second;
		cnt--;
	}
	reverse(write.begin(), write.end());
	for (int i = 0; i < write.size(); i++)
		cout << write[i] << " ";
	return 0;
}