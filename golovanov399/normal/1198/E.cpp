#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
    int from, to, cap, flow;
};

const int INF = (int)2e9 + 200;

struct Dinic {
    int n;
    vector<Edge> edges;
    vector<vector<int>> g;

    Dinic(int n) : n(n) {
        g.resize(n);
    }

    void add_edge(int from, int to, int cap) {
        Edge e = {from, to, cap, 0};
        g[from].push_back(edges.size());
        edges.push_back(e);
        e = {to, from, 0, 0};
        g[to].push_back(edges.size());
        edges.push_back(e);
    }

    vector<int> d;

    bool bfs(int s, int t) {
        d.assign(n, INF);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto id : g[v]) {
                auto e = edges[id];
                if (e.cap > e.flow && d[e.to] == INF) {
                    d[e.to] = d[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return d[t] != INF;
    }

    vector<int> pointer;

    int dfs(int v, int t, int flow_add) {
        if (!flow_add) {
            return 0;
        }
        if (v == t) {
            return flow_add;
        }
        for (int& i = pointer[v]; i < (int)g[v].size(); ++i) {
            int id = g[v][i];
            int to = edges[id].to;
            if (d[to] != d[v] + 1) {
                continue;
            }
            int pushed = dfs(to, t, min(flow_add, edges[id].cap - edges[id].flow));
            if (pushed) {
                edges[id].flow += pushed;
                edges[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            pointer.assign(n, 0);
            while (int pushed = dfs(s, t, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

const int N = 111;
int cnt[N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<array<int, 4>> a(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 4; ++j) {
			a[i][j] = nxt();
		}
		a[i][0] -= 1;
		a[i][1] -= 1;
	}
	vector<int> xs = {0, n}, ys = {0, n};
	for (int i = 0; i < m; ++i) {
		xs.push_back(a[i][0]);
		ys.push_back(a[i][1]);
		xs.push_back(a[i][2]);
		ys.push_back(a[i][3]);
	}
	make_unique(xs);
	make_unique(ys);
	for (int i = 0; i < m; ++i) {
		int x1 = lower_bound(all(xs), a[i][0]) - xs.begin();
		int y1 = lower_bound(all(ys), a[i][1]) - ys.begin();
		int x2 = lower_bound(all(xs), a[i][2]) - xs.begin();
		int y2 = lower_bound(all(ys), a[i][3]) - ys.begin();
		cnt[x1][y1] += 1;
		cnt[x1][y2] -= 1;
		cnt[x2][y1] -= 1;
		cnt[x2][y2] += 1;
	}
	// for (int i = 0; i < (int)xs.size(); ++i) {
	// 	for (int j = 0; j < (int)ys.size(); ++j) {
	// 		cerr << cnt[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	for (int i = 0; i < (int)xs.size(); ++i) {
		for (int j = 0; j < (int)ys.size(); ++j) {
			if (i) {
				cnt[i][j] += cnt[i - 1][j];
			}
			if (j) {
				cnt[i][j] += cnt[i][j - 1];
			}
			if (i && j) {
				cnt[i][j] -= cnt[i - 1][j - 1];
			}
			// cerr << cnt[i][j] << " ";
		}
		// cerr << "\n";
	}

	Dinic net((int)xs.size() + (int)ys.size());
	for (int i = 0; i < (int)xs.size() - 1; ++i) {
		for (int j = 0; j < (int)ys.size() - 1; ++j) {
			if (cnt[i][j]/* - cnt[i][j + 1] - cnt[i + 1][j] + cnt[i][j]*/ > 0) {
				net.add_edge(i + 1, j + (int)xs.size(), INF);
				// cerr << "[" << xs[i] << ", " << xs[i + 1] << ")x[" << ys[j] << ", " << ys[j + 1] << ")\n";
			}
		}
	}
	for (int i = 0; i < (int)xs.size() - 1; ++i) {
		net.add_edge(0, i + 1, xs[i + 1] - xs[i]);
	}
	for (int i = 0; i < (int)ys.size() - 1; ++i) {
		net.add_edge(i + (int)xs.size(), (int)xs.size() + (int)ys.size() - 1, ys[i + 1] - ys[i]);
	}

	// for (int x : xs) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	// for (int y : ys) {
	// 	cerr << y << " ";
	// }
	// cerr << "\n";

	cout << net.max_flow(0, (int)xs.size() + (int)ys.size() - 1) << "\n";

	return 0;
}