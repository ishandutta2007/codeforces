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

const int INF = (int)2e9;

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


const int N = 202;
int vid[N][N];
int hid[N][N];
int vsz = 0, hsz = 0;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(vid, -1, sizeof(vid));
	memset(hid, -1, sizeof(hid));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (a[i][j] == '#' && a[i][j + 1] == '#') {
				vid[i][j] = vsz++;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '#' && a[i + 1][j] == '#') {
				hid[i][j] = hsz++;
			}
		}
	}
	Dinic net(hsz + vsz + 2);
	for (int i = 0; i < hsz; ++i) {
		net.add_edge(0, i + 1, 1);
	}
	for (int i = 0; i < vsz; ++i) {
		net.add_edge(i + hsz + 1, vsz + hsz + 1, 1);
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (~vid[i][j] && ~hid[i][j]) {
				net.add_edge(1 + hid[i][j], 1 + hsz + vid[i][j], INF);
			}
			if (~vid[i][j] && ~hid[i][j + 1]) {
				net.add_edge(1 + hid[i][j + 1], 1 + hsz + vid[i][j], INF);
			}
			if (~vid[i + 1][j] && ~hid[i][j]) {
				net.add_edge(1 + hid[i][j], 1 + hsz + vid[i + 1][j], INF);
			}
			if (~vid[i + 1][j] && ~hid[i][j + 1]) {
				net.add_edge(1 + hid[i][j + 1], 1 + hsz + vid[i + 1][j], INF);
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cnt += (a[i][j] == '#');
		}
	}

	net.max_flow(0, hsz + vsz + 1);
	vector<char> used(hsz + vsz + 1);
	vector<int> st = {0};
	used[0] = 1;
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		for (int eid : net.g[v]) {
			if (net.edges[eid].cap == net.edges[eid].flow) {
				continue;
			}
			int to = net.edges[eid].to;
			if (!used[to]) {
				used[to] = 1;
				st.push_back(to);
			}
		}
	}
	for (int i = 1; i <= hsz; ++i) {
		if (used[i]) {
			--cnt;
		}
	}
	for (int i = hsz + 1; i <= hsz + vsz; ++i) {
		if (!used[i]) {
			--cnt;
		}
	}
	cout << cnt << "\n";

	return 0;
}