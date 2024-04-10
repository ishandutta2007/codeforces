#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int INF = 1e9;

vector <int> bfs(int s, vector <vector <int>> &g) {
	int n = g.size();
	queue <int> q;
	vector <int> d(n, INF);
	d[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v])
			if (d[v] + 1 < d[u]) {
				d[u] = d[v] + 1;
				q.push(u);
			}
	}
	return d;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		a--, b--, c--;
		vector <ll> p(m);
		for (int i = 0; i < m; i++)
			cin >> p[i];
		sort(p.begin(), p.end());
		vector <ll> pre(m);
		pre[0] = p[0];
		for (int i = 1; i < m; i++)
			pre[i] = pre[i - 1] + p[i];
		vector <vector <int>> g(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ll ans = 1e18;
		vector <int> da = bfs(a, g), db = bfs(b, g), dc = bfs(c, g);
		for (int i = 0; i < n; i++) {
			ll cur_ans = 0;
			if (da[i] + db[i] + dc[i] > m) continue;
			cur_ans += (db[i] ? pre[db[i] - 1] : 0);
			cur_ans += (da[i] + db[i] + dc[i] ? pre[da[i] + db[i] + dc[i] - 1] : 0);
			ans = min(ans, cur_ans);
		}
		cout << ans << '\n';
	}
	return 0;
}