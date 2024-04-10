#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <vector <int>> g(n);
	for (int i = 0; i < n; i++) {
		int u = i;
		int v1 = i - a[i];
		int v2 = i + a[i];
		if (v1 >= 0) g[v1].push_back(u);
		if (v2 < n) g[v2].push_back(u);
	}
	vector <int> ans(n, -1);
	{
		queue <int> q;
		vector <int> d(n, INF);
		for (int i = 0; i < n; i++)
			if (a[i] % 2) {
				q.push(i);
				d[i] = 0;
			}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int u : g[v])
				if (d[v] + 1 < d[u]) {
					d[u] = d[v] + 1;
					q.push(u);
				}
		}
		for (int i = 0; i < n; i++) {
			if (!d[i]) continue;
			if (d[i] == INF) ans[i] = -1;
			else ans[i] = d[i];
		}
	}
	{
		queue <int> q;
		vector <int> d(n, INF);
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 0) {
				q.push(i);
				d[i] = 0;
			}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int u : g[v])
				if (d[v] + 1 < d[u]) {
					d[u] = d[v] + 1;
					q.push(u);
				}
		}
		for (int i = 0; i < n; i++) {
			if (!d[i]) continue;
			if (d[i] == INF) ans[i] = -1;
			else ans[i] = d[i];
		}
	}
	for (auto &now : ans)
		cout << now << ' ';
	return 0;
}