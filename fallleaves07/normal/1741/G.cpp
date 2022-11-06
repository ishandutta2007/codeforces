#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct Graph {
	vector<vector<int>> e;
	vector<int> tag, h;
	int f, k, n;
	Graph(int n, int m) {
		this->n = n;
		e.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int u, v;
			cin >> u >> v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		cin >> f;
		h.resize(f);
		for (int i = 0; i < f; i++) {
			cin >> h[i];
		}
		cin >> k;
		tag.resize(n + 1);
		for (int i = 0; i < k; i++) {
			int d;
			cin >> d;
			tag[h[d - 1]] |= 1 << i;
			h[d - 1] = 0;
		}
	}
	void solve() {
		queue<int> que;
		vector vis(n + 1, vector<bool>(1 << k));
		vector dis(n + 1, n + 1);
		que.push(1), vis[1][0] = true, dis[1] = 0;
		while (!que.empty()) {
			int v = que.front();
			que.pop();
			for (auto u : e[v]) {
				if (dis[u] >= dis[v] + 1) {
					if (dis[u] > dis[v] + 1) {
						que.push(u), dis[u] = dis[v] + 1;
					}
					for (int j = 0; j < (1 << k); j++) {
						if (vis[v][j]) {
							vis[u][j | tag[u]] = true;
						}
					}
				}
			}
		}
		vector<bool> now(1 << k), nxt;
		now[0] = 1;
		for (int i = 0; i < f; i++) {
			if (h[i]) {
				nxt.assign(1 << k, false);
				for (int x = 0; x < (1 << k); x++) {
					for (int y = 0; y < (1 << k); y++) {
						nxt[x | y] = (nxt[x | y] | (now[x] & vis[h[i]][y]));
					}
				}
				swap(nxt, now);
			}
		}
		int ans = k;
		for (int x = 0; x < (1 << k); x++) {
			int cnt = k;
			for (int y = x; y; y >>= 1) {
				cnt -= (y & 1);
			}
			if (now[x]) {
				ans = min(ans, cnt);
			}
		}
		printf("%d\n", ans);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	Graph g(n, m);
	g.solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}