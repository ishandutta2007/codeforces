#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL lnf = 1e18;

struct Graph {
	int n;
	vector<vector<pair<int, int>>> e;
	Graph(int _n) : n(_n), e(_n + 1) {}
	void addedge(int u, int v, int w) {
		e[u].emplace_back(v, w);
	}
	vector<LL> dis;
	void dij(const vector<int> &st) {
		dis.assign(n + 1, lnf);
		struct D {
			LL dis;
			int id;
			bool operator<(const D &b) const {
				return dis > b.dis;
			}
		};
		priority_queue<D> que;
		for (auto v : st) {
			dis[v] = 0, que.push({dis[v], v});
		}
		while (!que.empty()) {
			auto [d, v] = que.top();
			que.pop();
			if (dis[v] != d) {
				continue;
			}
			for (auto [u, w] : e[v]) {
				if (dis[u] > dis[v] + w) {
					dis[u] = dis[v] + w;
					que.push({dis[u], u});
				}
			}
		}
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	vector<string> mp(n);
	for (int i = 0; i < n; i++) {
		cin >> mp[i];
	}
	vector pid(n, vector<int>(m));
	int pcnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pid[i][j] = ++pcnt;
		}
	}
	Graph g(pcnt);
	auto add = [&](int x, int y, int z, int w, int len) {
		if (x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < n && w >= 0 && w < m) {
			g.addedge(pid[x][y], pid[z][w], len);
		}
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 'L') {
				add(i - 1, j, i, j + 1, p);
				add(i + 1, j, i, j + 1, p);
				add(i, j - 1, i, j + 1, q);
			} else if (mp[i][j] == 'R') {
				add(i - 1, j, i, j - 1, p);
				add(i + 1, j, i, j - 1, p);
				add(i, j + 1, i, j - 1, q);
			} else if (mp[i][j] == 'U') {
				add(i, j - 1, i + 1, j, p);
				add(i, j + 1, i + 1, j, p);
				add(i - 1, j, i + 1, j, q);
			} else if (mp[i][j] == 'D') {
				add(i, j - 1, i - 1, j, p);
				add(i, j + 1, i - 1, j, p);
				add(i + 1, j, i - 1, j, q);
			}
		}
	}
	vector<int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == '.') {
				st.emplace_back(pid[i][j]);
			}
		}
	}
	g.dij(st);
	LL ans = lnf;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n) {
				ans = min(ans, g.dis[pid[i][j]] + g.dis[pid[i + 1][j]]);
			}
			if (j + 1 < m) {
				ans = min(ans, g.dis[pid[i][j]] + g.dis[pid[i][j + 1]]);
			}
		}
	}
	if (ans >= lnf) {
		puts("-1");
	} else {
		printf("%lld\n", ans);
	}
    return 0;
}