#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	vector<vector<int>> d(n, vector<int>(k));
	for (int which = 0; which < k; ++which) {
		queue<int> q;
		vector<bool> used(n);
		for (int i = 0; i < n; ++i) {
			if (a[i] == which) {
				q.push(i);	
				used[i] = 1;
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v: graph[u]) {
				if (!used[v]) {
					d[v][which] = d[u][which] + 1;
					used[v] = 1;
					q.push(v);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		nth_element(d[i].begin(), d[i].begin() + (s - 1), d[i].end());
		cout << accumulate(d[i].begin(), d[i].begin() + s, 0) << " ";
	}
	return 0;
}