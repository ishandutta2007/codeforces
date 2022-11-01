#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector <bool> &used, vector <int> &p, vector <int> &d, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u]) {
			p[u] = v;
			d[u] = d[v] + 1;
			dfs(u, used, p, d, g);
		}
}

int dist(int u, int v, vector <int> &d, vector <vector <int>> &up) {
	int x = u, y = v;
	if (d[u] < d[v]) swap(u, v);
	for (int i = 0; i < up.size(); i++)
		if ((d[u] - d[v]) & (1 << i))
			u = up[i][u];
	if (u == v) return d[x] + d[y] - 2 * d[u];
	int ans = 0;
	for (int i = up.size() - 1; i >= 0; i--) {
		int _u = up[i][u];
		int _v = up[i][v];
		if (_u == _v) ans = _u;
		else u = _u, v = _v;
	}
	return d[x] + d[y] - 2 * d[ans];
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
	vector <int> p(n), d(n);
	dfs(0, used, p, d, g);
	vector <int> lg(n);
	for (int i = 2; i < n; i++)
		lg[i] = lg[(i >> 1)] + 1;
	vector <vector <int>> up(lg[n - 1] + 1, vector <int>(n));
	for (int i = 0; i < n; i++)
		up[0][i] = p[i];
	for (int pow = 1; pow <= lg[n - 1]; pow++)
		for (int i = 0; i < n; i++)
			up[pow][i] = up[pow - 1][up[pow - 1][i]];
	int q;
	cin >> q;
	while (q--) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		x--, y--, a--, b--;
		{
			int dis = dist(a, b, d, up);
			if (dis <= k && (dis - k) % 2 == 0) {
				cout << "YES\n";
				continue;
			}
		}
		{
			int dis = dist(a, x, d, up) + 1 + dist(b, y, d, up);
			if (dis <= k && (dis - k) % 2 == 0) {
				cout << "YES\n";
				continue;
			}
		}
		{
			int dis = dist(a, x, d, up) + 1 + dist(x, y, d, up) + dist(b, x, d, up);
			if (dis <= k && (dis - k) % 2 == 0) {
				cout << "YES\n";
				continue;
			}
		}
		swap(x, y);
		{
			int dis = dist(a, x, d, up) + 1 + dist(b, y, d, up);
			if (dis <= k && (dis - k) % 2 == 0) {
				cout << "YES\n";
				continue;
			}
		}
		{
			int dis = dist(a, x, d, up) + 1 + dist(x, y, d, up) + dist(b, x, d, up);
			if (dis <= k && (dis - k) % 2 == 0) {
				cout << "YES\n";
				continue;
			}
		}
		cout << "NO\n";
	}
	return 0;
}