#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	--s, --t;
	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u][v] = graph[v][u] = 1;
	}
	vector<bool> used(n);
	vector<int> ds(n);
	queue<int> q;
	q.push(s);
	used[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < n; ++i) {
			if (graph[u][i] && !used[i]) {
				q.push(i);
				ds[i] = ds[u] + 1;
				used[i] = 1;
			}
		}
	}
	fill(used.begin(), used.end(), 0);
	vector<int> dt(n);
	q.push(t);
	used[t] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < n; ++i) {
			if (graph[u][i] && !used[i]) {
				q.push(i);
				dt[i] = dt[u] + 1;
				used[i] = 1;
			}
		}
	}
	int dst = ds[t];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (graph[i][j]) continue;
			if (min(ds[j] + dt[i], ds[i] + dt[j]) + 1 < dst) continue;
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}