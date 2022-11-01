#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

void dfs(int v, vector <bool> &used, vector <int> &d, vector <int> &p, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u]) {
			d[u] = d[v] + 1;
			p[u] = v;
			dfs(u, used, d, p, g);
		}
}

int main() {
	int n;
	cin >> n;
	vector <vector <int>> g(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector <bool> used(n);
	vector <int> d(n), p(n);
	dfs(0, used, d, p, g);
	int s = 0;
	for (int i = 1; i < n; i++)
		if (d[s] < d[i]) 
			s = i;
	d[s] = 0;
	used.assign(n, false);
	dfs(s, used, d, p, g);
	int f = 0;
	for (int i = 1; i < n; i++)
		if (d[f] < d[i])
			f = i;
	queue <int> q;
	int a = s, b = f;
	int ans = 0;
	ans += d[f];
	d.assign(n, INF);
	while (f != s) {
		q.push(f);
		d[f] = 0;
		f = p[f];
	}
	q.push(s);
	d[s] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v])
			if (d[v] + 1 < d[u]) {
				d[u] = d[v] + 1;
				q.push(u);
			}
	}
	int c = -1;
	for (int i = 0; i < n; i++) {
		if (i == a || i == b) continue;
		if (c == -1) c = i;
		if (d[c] < d[i]) c = i;
	}
	ans += d[c];
	cout << ans << '\n';
	cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
	return 0;
}