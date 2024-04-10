#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define endl '\n'

using namespace std;

const int INF = 1e9;

void count_dis(int v, int p, vector <int> &d, vector <vector <int>> &g) {
	for (int u : g[v]) 
		if (u != p) {
			d[u] = d[v] + 1;
			count_dis(u, v, d, g);
		}
}
void build_rmq(int v, int p, vector <int> &d, vector <int> &tin, vector <pair <int, int>> &rmq, vector <vector <int>> &g) {
	tin[v] = rmq.size();
	rmq.push_back({ d[v], v });
	for (int u : g[v])
		if (u != p)
			build_rmq(u, v, d, tin, rmq, g);
	rmq.push_back({ d[p], p });
}
void build_sparse_table(vector <int> &log, vector <pair <int, int>> &rmq, vector <vector <pair <int, int>>> &st) {
	for (int i = 0; i < rmq.size(); i++)
		st[i][0] = rmq[i];
	for (int p = 1; p <= log[rmq.size() - 1]; p++)
		for (int j = 0; j < rmq.size(); j++) {
			st[j][p] = st[j][p - 1];
			if (j + (1 << (p - 1)) < rmq.size())
				st[j][p] = min(st[j][p], st[j + (1 << (p - 1))][p - 1]);
		}
}
int get_lca(int u, int v, vector <int> &log, vector <int> &tin, vector <pair <int, int>> &rmq, vector <vector <pair <int, int>>> &st) {
	u = tin[u];
	v = tin[v];
	if (u > v) swap(u, v);
	int k = (v - u + 1);
	int val = min(st[u][log[k]], st[v - (1 << log[k]) + 1][log[k]]).first;
	return val;
}
int get_distance(int u, int v, vector <int> &log, vector <int> &tin, vector <int> &dis, vector <pair <int, int>> &rmq, vector <vector <pair <int, int>>> &st) {
	return (dis[u] + dis[v] - 2 * get_lca(u, v, log, tin, rmq, st));
}
int get_centroid(int v, int p, int n, int &c, vector <int> &d, vector <vector <int>> &g) {
	int sz = 1;
	for (int u : g[v])
		if (u != p && d[u] == -1)
			sz += get_centroid(u, v, n, c, d, g);
	if (c == -1 && 2 * sz >= n) c = v;
	return sz;
}
void build_centroid(int v, int par, int dep, int n, vector <int> &d, vector <int> &p, vector <vector <int>> &g) {
	int c = -1;
	get_centroid(v, par, n, c, d, g);
	if (c == -1) c = v;
	d[c] = dep + 1;
	p[c] = par;
	for (int u : g[c])
		if (d[u] == -1)
			build_centroid(u, c, dep + 1, n / 2, d, p, g);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector <int> d(n, -1), p(n, -1);
	vector <vector <int>> g(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	build_centroid(0, -1, -1, n, d, p, g);
	vector <int> dis(n), tin(n);
	vector <pair <int, int>> rmq;
	count_dis(0, 0, dis, g);
	build_rmq(0, 0, dis, tin, rmq, g);
	vector <int> log(rmq.size());
	for (int i = 2; i < log.size(); i++)
		log[i] = log[i / 2] + 1;
	vector <vector <pair <int, int>>> st(rmq.size(), vector <pair <int, int>>(log[rmq.size() - 1] + 1));
	build_sparse_table(log, rmq, st);
	vector <int> ms(n, INF);
	vector <int> color(n);
	int v = 0;
	int s = v;
	while (v != -1) {
		int dist = get_distance(s, v, log, tin, dis, rmq, st);
		ms[v] = min(ms[v], dist);
		v = p[v];
	}
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int v;
			cin >> v;
			v--;
			color[v] = 1;
			int s = v;
			while (v != -1) {
				int dist = get_distance(s, v, log, tin, dis, rmq, st);
				ms[v] = min(ms[v], dist);
				v = p[v];
			}
			continue;
		}
		int v;
		cin >> v;
		v--;
		int ans = INF;
		int s = v;
		while (v != -1) {
			int dist = get_distance(s, v, log, tin, dis, rmq, st);
			ans = min(ans, dist + ms[v]);
			v = p[v];
		}
		if (ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}