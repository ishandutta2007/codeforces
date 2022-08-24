#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

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
	int from, to;
	long long cap, flow;
};

const int INF = (int)2e9;

struct Dinic {
	int n;
	int s, t;
	vector<Edge> edges;
	vector<vector<int>> g;

	Dinic(int n, int s, int t) : n(n), s(s), t(t) {
		g.resize(n);
	}

	void add_edge(int from, int to, long long cap) {
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

	long long dfs(int v, int t, long long flow_add) {
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
			long long pushed = dfs(to, t, min(flow_add, edges[id].cap - edges[id].flow));
			if (pushed) {
				edges[id].flow += pushed;
				edges[id ^ 1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	long long get_flow() {
		long long flow = 0;
		while (bfs(s, t)) {
			pointer.assign(n, 0);
			while (long long pushed = dfs(s, t, INF)) {
				flow += pushed;
			}
		}
		return flow;
	}
};

using Network = Dinic;

/*
struct Network {
	struct Edge {
		int from, to;
		long long cap, flow;

		Edge(int fr, int to, long long cap, long long fl = 0):
			from(fr),to(to),cap(cap),flow(fl){}
	};

	int n;
	int s, t;
	vector<Edge> edges;
	vector<vector<int>> a;
	vector<int> ptr;

	Network(int n, int s, int t): n(n), s(s), t(t) {
		a.resize(n);
		ptr.resize(n);
	}

	void add_edge(int from, int to, long long cap) {
		int num = edges.size();
		edges.push_back(Edge(from, to, cap));
		edges.push_back(Edge(to, from, 0));
		a[from].push_back(num);
		a[to].push_back(num + 1);
	}

	long long push(int v, long long limit) {
		if (v == t)
			return limit;
		if (limit == 0)
			return 0;
		long long res = 0;
		while (ptr[v] < (int)a[v].size() && limit > 0){
			int pos = a[v][ptr[v]];
			int to = edges[pos].to;
			long long lm = min(limit, edges[pos].cap - edges[pos].flow);
			ptr[v]++;
			long long flow = push(to, lm);
			limit -= flow;
			res += flow;
			edges[pos].flow += flow;
			edges[pos ^ 1].flow -= flow;
		}
		return res;
	}

	long long get_flow() {
		long long res = 0;
		while (true){
			for (int i = 0; i < n; i++)
				ptr[i] = 0;
			long long flow = push(s, LLONG_MAX / 10);
			if (flow == 0)
				break;
			res += flow;
		}
		return res;
	}

	void show_flow() const {
		vector<vector<int>> out(n);
		for (int i = 0; i < (int)edges.size(); i += 2){
			if (edges[i].flow == 0)
				continue;
			int j = i;
			if (edges[i].flow < 0)
				j++;
			out[edges[j].from].push_back(j);
		}
		for (int i = 0; i < n; i++){
			for (int j : out[i]){
				cerr << i << " -> " << edges[j].to << " (" << edges[j].flow << "/" << edges[j].cap << ")\n";
			}
		}
	}
};
*/
int main() {
	int n = nxt();
	int m = nxt();
	vector<array<int, 6>> ed(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 6; ++j) {
			ed[i][j] = nxt();
		}
	}

	const long long many = 10000000;
	auto get = [&](long long t) {
		Network net(n + 2, 0, n + 1);
		for (auto e : ed) {
			net.add_edge(0, e[1], e[2] * t + e[3] * many);
			net.add_edge(e[0], n + 1, e[2] * t + e[3] * many);
			net.add_edge(e[0], e[1], e[4] * t + e[5] * many - (e[2] * t + e[3] * many));
		}

		// double res = 0;
		// for (int i = 0; i < m; ++i) {
		// 	res += net.edges[6 * i].flow - ed[i][2] * t - ed[i][3];
		// 	res += net.edges[6 * i + 2].flow - ed[i][2] * t - ed[i][3];
		// }

		long long res = net.get_flow();
		for (auto e : ed) {
			res -= e[2] * t + e[3] * many;
		}

		return res;
	};

	int l = 0, r = many;
	while (r > l + 2) {
		int m1 = (2 * l + r) / 3;
		int m2 = (l + 2 * r) / 3;

		if (get(m1) > get(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	int mid = l;
	for (int i = l + 1; i <= r; ++i) {
		if (get(i) > get(mid)) {
			mid = i;
		}
	}

	if (get(mid) < 0) {
		puts("0");
		return 0;
	}

	l = mid, r = many + 1;
	while (r > l + 1) {
		int m = (l + r) / 2;
		if (get(m) == 0) {
			l = m;
		} else {
			r = m;
		}
	}
	int ans = l;

	l = -1, r = mid;
	while (r > l + 1) {
		int m = (l + r) / 2;
		if (get(m) == 0) {
			r = m;
		} else {
			l = m;
		}
	}
	ans -= r;

	cout << setprecision(10) << fixed;
	cout << 1.0 * ans / many << "\n";

	return 0;
}