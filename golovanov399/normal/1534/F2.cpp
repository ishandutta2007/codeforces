#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

enum GraphType {
	Undirected,
	Directed
};

enum EdgeType {
	Unit,
	Weighted
};

using EdgeInt = long long;

template <EdgeType etype>
struct Edge;

template <>
struct Edge<Unit> {
	int from, to;
};

template <>
struct Edge<Weighted> {
	int from, to;
	EdgeInt w;
};

template <EdgeType etype>
inline int other_end(const Edge<etype>& e, int v) {
	return e.from == v ? e.to : e.from;
}

template <GraphType gtype = Undirected, EdgeType etype = Unit>
class Graph {
public:
	Graph() {}
	explicit Graph(int _n): n(_n), a(_n) {}

	void read_edges(int edge_cnt, int start_index = 1) {
		for (int i = 0; i < edge_cnt; ++i) {
			int u = nxt() - start_index, v = nxt() - start_index;
			Edge<etype> e;
			e.from = u, e.to = v;
			if constexpr (etype == Weighted) {
				e.w = nxt();
			}
			a[e.from].push_back(edges.size());
			if constexpr (gtype == Undirected) {
				a[e.to].push_back(edges.size());
			}
			edges.push_back(e);
		}
	}

	void add_edge(int u, int v) {
		static_assert(etype == Unit);
		a[u].push_back(edges.size());
		if constexpr (gtype == Undirected) {
			a[v].push_back(edges.size());
		}
		edges.push_back({u, v});
	}

	void add_edge(int u, int v, EdgeInt w) {
		static_assert(etype == Weighted);
		a[u].push_back(edges.size());
		if constexpr (gtype == Undirected) {
			a[v].push_back(edges.size());
		}
		edges.push_back({u, v, w});
	}

	void set_n(int _n) {
		n = _n;
		a.resize(n);
	}

	int size() const {
		return n;
	}

	int edges_count() const {
		return edges.size();
	}

	vector<Edge<etype>> get_edges() const {
		return edges;
	}

	vector<Edge<etype>> operator [](int v) const {
		vector<Edge<etype>> eds;
		for (int i : a[v]) {
			eds.push_back(edges[i]);
			if (eds.back().from != v) {
				swap(eds.back().from, eds.back().to);
			}
		}
		return eds;
	}

	vector<vector<int>> get_connected_components() {
		static_assert(gtype == Undirected);
		used.assign(n, false);
		vector<vector<int>> comps;
		auto add = [&](int v) {
			comps.back().push_back(v);
		};
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				comps.push_back({});
				dfs(i, -1, {}, add, {});
			}
		}
		return comps;
	}

	vector<int> topsort() {
		// returns garbage if there is a cycle
		static_assert(gtype == Directed);
		used.assign(n, false);
		vector<int> res;
		function<void(int)> dfs = [&](int v) {
			used[v] = 1;
			for (int eid : a[v]) {
				int to = other_end(edges[eid], v);
				if (used[to]) {
					continue;
				}
				dfs(to);
			}
			res.push_back(v);
		};
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				dfs(i);
			}
		}
		return res;
	}

	vector<Edge<etype>> euler_cycle() {
		// returns {} if there is no cycle
		int v = 0;
		while (v < n && a[v].empty()) {
			++v;
		}
		if (v == n) {
			return {};
		}
		vector<Edge<etype>> res;
		vector<char> used_edge(edges.size());
		vector<int> ptr(n, 0);
		function<void(int)> rec = [&](int v) {
			while (ptr[v] < (int)a[v].size() && used_edge[a[v][ptr[v]]]) {
				++ptr[v];
			}
			if (ptr[v] == (int)a[v].size()) {
				return;
			}
			auto e = edges[a[v][ptr[v]]];
			if (e.from != v) {
				swap(e.from, e.to);
			}
			used_edge[a[v][ptr[v]]] = 1;
			rec(e.to);
			res.push_back(e);
			rec(v);
		};
		rec(v);
		reverse(all(res));
		for (int i = 1; i < (int)res.size(); ++i) {
			if (res[i].from != res[i - 1].to) {
				return {};
			}
		}
		if (res.size() != edges.size() || res[0].from != res.back().to) {
			return {};
		}
		return res;
	}

	vector<Edge<etype>> euler_path(int start, int finish) {
		// returns {} if there is no path
		vector<Edge<etype>> res;
		vector<char> used_edge(edges.size());
		vector<int> ptr(n, 0);
		function<void(int)> rec = [&](int v) {
			while (ptr[v] < (int)a[v].size() && used_edge[a[v][ptr[v]]]) {
				++ptr[v];
			}
			if (ptr[v] == (int)a[v].size()) {
				return;
			}
			auto e = edges[a[v][ptr[v]]];
			if (e.from != v) {
				swap(e.from, e.to);
			}
			used_edge[a[v][ptr[v]]] = 1;
			rec(e.to);
			res.push_back(e);
			rec(v);
		};
		rec(start);
		int sz = res.size();
		rec(finish);
		rotate(res.begin(), sz + all(res));
		reverse(all(res));
		for (int i = 1; i < (int)res.size(); ++i) {
			if (res[i].from != res[i - 1].to) {
				return {};
			}
		}
		if (res.empty()) {
			return res;
		}
		if (res.size() != edges.size() || res[0].from != start || res.back().to != finish) {
			return {};
		}
		return res;
	}

	vector<vector<int>> get_sccs() {
		static_assert(gtype == Directed);
		used.assign(n, false);
		// seem to need custom dfs :/
		vector<vector<int>> comps;
		vector<int> h(n);
		vector<int> st;
		int curh = 0;
		function<int(int)> dfs = [&](int v) {
			used[v] = 1;
			st.push_back(v);
			int res = h[v];
			for (int eid : a[v]) {
				int to = edges[eid].to;
				if (!used[to]) {
					h[to] = curh++;
					res = min(res, dfs(to));
				} else if (used[to] == 1) {
					res = min(res, h[to]);
				}
			}
			if (res == h[v]) {
				comps.push_back({});
				while (true) {
					int u = st.back();
					st.pop_back();
					comps.back().push_back(u);
					used[u] = 2;
					if (u == v) {
						break;
					}
				}
			}
			return res;
		};
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				h[i] = curh++;
				dfs(i);
			}
		}
		return comps;
	}

	vector<int> get_distances(int v) {
		static_assert(etype == Unit);
		vector<int> d, par;
		bfs(v, d, par);
		return d;
	}

	pair<vector<int>, vector<int>> get_distances_with_parents(int v) {
		static_assert(etype == Unit);
		vector<int> d, par;
		bfs(v, d, par);
		return {d, par};
	}

	vector<int> two_coloring() {
		static_assert(gtype == Undirected);
		used.assign(n, false);
		vector<int> color(n, 0);
		auto func = [&](int to, int from) {
			color[to] = color[from] ^ 1;
		};
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				dfs(i, -1, func, {}, {});
			}
		}
		for (const auto& e : edges) {
			if (color[e.from] == color[e.to]) {
				return {};
			}
		}
		return color;
	}

	vector<vector<EdgeInt>> get_all_weighted_distances() {
		static_assert(etype == Weighted);
		constexpr EdgeInt inf = numeric_limits<EdgeInt>::max();
		vector<vector<EdgeInt>> d(n, vector<EdgeInt>(n, inf));
		for (int i = 0; i < n; ++i) {
			d[i][i] = 0;
			for (int eid : a[i]) {
				int j = other_end(edges[eid], i);
				d[i][j] = min(d[i][j], edges[eid].w);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					if (d[j][i] != inf && d[i][k] != inf) {
						d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
					}
				}
			}
		}
		return d;
	}

	vector<int> find_negative_cycle() {
		static_assert(etype == Weighted);
		static_assert(gtype == Directed);
		vector<int> order(n);
		iota(all(order), 0);
		vector<EdgeInt> dist(n, 0);
		vector<int> par(n, -1);
		for (int iter = 0; iter < n; ++iter) {
			bool changed = false;
			for (int v = 0; v < n; ++v) {
				for (int eid : a[v]) {
					int to = other_end(edges[eid], v);
					if (dist[to] - edges[eid].w > dist[v]) {
						changed = true;
						par[to] = v;
						dist[to] = dist[v] + edges[eid].w;
					}
				}
			}
			if (!changed) {
				return {};
			}
		}
		used.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			int v = i;
			while (v > -1 && !used[v]) {
				used[v] = 1;
				v = par[v];
			}
			if (v > -1 && used[v] == 1) {
				vector<int> cycle;
				while (used[v] == 1) {
					cycle.push_back(v);
					used[v] = 2;
					v = par[v];
				}
				reverse(all(cycle));
				return cycle;
			} else {
				for (v = i; v > -1 && used[v] != 2; v = par[v]) {
					used[v] = 2;
				}
			}
		}
		assert(false);
	}

	vector<pair<int, int>> matching() {	// better copypaste from https://judge.yosupo.jp/submission/31741
		static_assert(gtype == Undirected);
		vector<int> match(n, -1);

		vector<int> p(n, -1);
		vector<int> prt(n, -1);

		auto augment = [&](int v, int u) {
			while (true) {
				int nx = match[p[v]];
				match[v] = p[v];
				match[p[v]] = v;
				if (p[v] == u) {
					break;
				}
				v = nx;
			}
		};

		{
			vector<int> perm(n);
			iota(all(perm), 0);
			random_shuffle(all(perm));
			for (int v : perm) {
				if (match[v] > -1) {
					continue;
				}
				for (int eid : a[v]) {
					int to = other_end(edges[eid], v);
					if (match[to] == -1) {
						match[v] = to;
						match[to] = v;
						break;
					}
				}
			}
		}

		vector<int> root(n, -1);
		vector<int> last(n, 0);
		int timer = 0;

		auto lca = [&](int u, int v) {
			++timer;
			while (true) {
				if (v > -1) {
					if (last[v] == timer) {
						return v;
					}
					last[v] = timer;
					if (match[v] == -1) {
						v = -1;
					} else {
						v = root[p[match[v]]];
					}
				}
				swap(u, v);
			}
		};

		auto bfs = [&](int from) {
			fill(all(p), -1);
			fill(all(prt), -1);
			iota(all(root), 0);
			queue<int> q;
			q.push(from);
			prt[from] = 0;

			auto blossom = [&](int v, int u, int rt) {
				while (root[v] != rt) {
					p[v] = u;
					u = match[v];
					if (prt[u] == 1) {
						q.push(u);
						prt[u] = 0;
					}
					root[v] = root[u] = rt;
					v = p[u];
				}
			};

			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int eid : a[v]) {
					int to = other_end(edges[eid], v);
					if (prt[to] == -1) {
						p[to] = v;
						if (int nx = match[to]; nx == -1) {
							augment(to, from);
							return;
						} else {
							prt[to] = 1;
							q.push(match[to]);
							prt[match[to]] = 0;
						}
					} else if (prt[to] == 0 && root[v] != root[to]) {
						int rt = lca(root[v], root[to]);
						blossom(to, v, rt);
						blossom(v, to, rt);
					}
				}
			}
		};

		for (int i = 0; i < n; ++i) {
			if (match[i] > -1) {
				continue;
			}
			bfs(i);
		}

		vector<pair<int, int>> res;
		for (int i = 0; i < n; ++i) {
			if (i < match[i]) {
				res.push_back({i, match[i]});
			}
		}
		return res;
	}

	void reverse() {
		static_assert(gtype == Directed);
		for (int i = 0; i < n; ++i) {
			a[i].clear();
		}
		for (int i = 0; i < (int)edges.size(); ++i) {
			auto& e = edges[i];
			swap(e.from, e.to);
			a[e.from].push_back(i);
		}
	}

	Graph reversed() const {
		auto res = *this;
		res.reverse();
		return res;
	}

	vector<int> get_last_order() const {
		return order;
	}

	vector<EdgeInt> k_shortest(int k, int from, int to) const;

private:
	int n;
	vector<vector<int>> a;
	vector<Edge<etype>> edges;

	vector<char> used;
	vector<int> order;

	void dfs(int v, int pid, const optional<function<void(int, int)>>& pre, const optional<function<void(int)>>& in, const optional<function<void(int, int)>>& post) {
		used[v] = 1;
		if (in) {
			(*in)(v);
		}
		for (int eid : a[v]) {
			if (eid == pid) {
				continue;
			}
			int to = other_end(edges[eid], v);
			if (used[to]) {
				continue;
			}
			if (pre) {
				(*pre)(to, v);
			}
			dfs(to, eid, pre, in, post);
			if (post) {
				(*post)(to, v);
			}
		}
	}

	void bfs(int start, vector<int>& d, vector<int>& par) {
		order.clear();
		d.assign(n, -1);
		par.assign(n, -1);
		d[start] = 0;
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			auto v = q.front();
			order.push_back(v);
			q.pop();
			for (int eid : a[v]) {
				int u = other_end(edges[eid], v);
				if (d[u] == -1) {
					d[u] = d[v] + 1;
					par[u] = v;
					q.push(u);
				}
			}
		}
	}

	void dijkstra_pq(int start, vector<EdgeInt>& d, vector<int>& par) {
		order.clear();
		d.assign(n, numeric_limits<EdgeInt>::max());
		par.assign(n, -1);
		d[start] = 0;
		priority_queue<pair<EdgeInt, int>, vector<pair<EdgeInt, int>>, greater<pair<EdgeInt, int>>> pq;
		pq.push({0, start});
		while (!pq.empty()) {
			auto [val, v] = pq.top();
			pq.pop();
			if (d[v] != val) {
				continue;
			}
			order.push_back(v);
			for (int eid : a[v]) {
				assert(edges[eid].w >= 0);
				auto to = other_end(edges[eid], v);
				if (d[to] - edges[eid].w > val) {
					d[to] = val + edges[eid].w;
					par[to] = v;
					pq.push({d[to], to});
				}
			}
		}
	}

	void dijkstra_set(int start, vector<EdgeInt>& d, vector<int>& par) {
		order.clear();
		d.assign(n, numeric_limits<EdgeInt>::max());
		par.assign(n, -1);
		d[start] = 0;
		set<pair<EdgeInt, int>> S;
		S.insert({0, start});
		while (!S.empty()) {
			auto [val, v] = *S.begin();
			S.erase(S.begin());
			order.push_back(v);
			for (int eid : a[v]) {
				assert(edges[eid].w >= 0);
				auto to = other_end(edges[eid], v);
				if (d[to] - edges[eid].w > val) {
					S.erase({d[to], to});
					d[to] = val + edges[eid].w;
					par[to] = v;
					S.insert({d[to], to});
				}
			}
		}
	}

	void ford_bellman(int start, vector<EdgeInt>& dist, vector<int>& par) {
		vector<int> order(n);
		iota(all(order), 0);
		{
			vector<int> d, p;
			bfs(start, d, p);
			sort(all(order), [&](int i, int j) {
				return d[i] < d[j];
			});
		}
		dist.assign(n, numeric_limits<EdgeInt>::max());
		par.assign(n, -1);
		dist[start] = 0;
		for (int iter = 0; iter < n; ++iter) {
			bool changed = false;
			for (int v : order) {
				for (int eid : a[v]) {
					int to = other_end(edges[eid], v);
					if (dist[to] - edges[eid].w > dist[v]) {
						changed = true;
						par[to] = v;
						dist[to] = dist[v] + edges[eid].w;
					}
				}
			}
			if (!changed) {
				return;
			}
		}
		throw logic_error("can't ford bellman when there is a negative cycle");
	}

	void ford_bellman_bfs(int start, vector<EdgeInt>& dist, vector<int>& par) {
		/* This doesn't detect negative cycles
		*/
		vector<char> in_queue(n);
		dist.assign(n, numeric_limits<EdgeInt>::max());
		par.assign(n, -1);
		dist[start] = 0;
		queue<int> q;
		q.push(start);
		in_queue[start] = true;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			in_queue[v] = false;
			for (int eid : a[v]) {
				int to = other_end(edges[eid], v);
				if (dist[to] - edges[eid].w > dist[v]) {
					dist[to] = dist[v] + edges[eid].w;
					par[to] = v;
					if (!in_queue[to]) {
						q.push(to);
						in_queue[to] = true;
					}
				}
			}
		}
	}
};


template <EdgeType etype = Unit>
using Ugraph = Graph<Undirected, etype>;

template <EdgeType etype = Unit>
using Digraph = Graph<Directed, etype>;

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<int>> idx(n, vector<int>(m, -1));
	vector<vector<int>> col(m);
	int cur = 0;
	vector<pair<int, int>> sands;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '#') {
				sands.push_back({i, j});
				idx[i][j] = cur++;
				col[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		reverse(all(col[i]));
	}
	vector<int> need;
	for (int i = 0; i < m; ++i) {
		int x = nxt();
		if (x) {
			need.push_back(idx[col[i][x - 1]][i]);
		}
	}
	
	Digraph<Unit> g(cur);
	vector<int> last(m, -1);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			if (idx[i][j] == -1) {
				continue;
			}
			if (last[j] > -1) {
				g.add_edge(idx[i][j], last[j]);
			}
			if (i > 0 && idx[i - 1][j] != -1) {
				g.add_edge(idx[i][j], idx[i - 1][j]);
			}
			if (j > 0 && last[j - 1] > -1) {
				g.add_edge(idx[i][j], last[j - 1]);
			}
			if (j < m - 1 && last[j + 1] > -1) {
				g.add_edge(idx[i][j], last[j + 1]);
			}
			if (j > 0 && idx[i][j - 1] > -1) {
				g.add_edge(idx[i][j], idx[i][j - 1]);
			}
			if (j < m - 1 && idx[i][j + 1] > -1) {
				g.add_edge(idx[i][j], idx[i][j + 1]);
			}
		}
		for (int j = 0; j < m; ++j) {
			if (idx[i][j] > -1) {
				last[j] = idx[i][j];
			}
		}
	}

	auto sccs = g.get_sccs();
	const int sz = sccs.size();
	vector<int> scc_by_id(cur);
	for (int i = 0; i < sz; ++i) {
		for (int x : sccs[i]) {
			scc_by_id[x] = i;
		}
	}
	vector<char> required(sz, false);
	for (int x : need) {
		required[scc_by_id[x]] = true;
	}
	auto edges = g.get_edges();
	vector<char> is_source(sz, true);
	vector<vector<int>> new_edges(sz);
	for (auto [u, v] : edges) {
		if (scc_by_id[u] != scc_by_id[v]) {
			is_source[scc_by_id[v]] = false;
			new_edges[scc_by_id[u]].push_back(scc_by_id[v]);
		}
	}
	
	vector<int> sources;
	for (int i = 0; i < sz; ++i) {
		if (is_source[i]) {
			sources.push_back(i);
		}
	}
	// for (int i = 0; i < sz; ++i) {
	// 	cerr << i << ": ";
	// 	for (int x : sccs[i]) {
	// 		cerr << x << " ";
	// 	}
	// 	cerr << "\n";
	// }
	sort(all(sources), [&](int i, int j) {
		return sands[sccs[i][0]].second < sands[sccs[j][0]].second;
	});

	Digraph<Unit> dag(sz);
	for (int i = 0; i < sz; ++i) {
		make_unique(new_edges[i]);
		for (int j : new_edges[i]) {
			dag.add_edge(i, j);
		}
	}
	auto ts = dag.topsort();
	vector<pair<int, int>> segs(sz, {-1, -1});
	vector<pair<int, int>> to_handle;

	for (int i = 0; i < (int)sources.size(); ++i) {
		segs[sources[i]] = {i, i + 1};
	}

	reverse(all(ts));
	for (int v : ts) {
		// cerr << v << " -- " << segs[v].first << " " << segs[v].second << "\n";
		for (int x : new_edges[v]) {
			if (segs[x].first == -1) {
				segs[x] = segs[v];
			} else {
				segs[x].first = min(segs[x].first, segs[v].first);
				segs[x].second = max(segs[x].second, segs[v].second);
			}
		}
		if (required[v]) {
			// cerr << v << ": " << segs[v].first << " " << segs[v].second << "\n";
			to_handle.push_back(segs[v]);
		}
	}

	int ans = 0;
	sort(all(to_handle));
	vector<int> mn(to_handle.size());
	for (int i = (int)to_handle.size() - 1; i >= 0; --i) {
		mn[i] = to_handle[i].second;
		if (i < (int)to_handle.size() - 1) {
			mn[i] = min(mn[i], mn[i + 1]);
		}
	}
	for (int i = 0; i < (int)to_handle.size();) {
		int nx = mn[i];
		while (i < (int)to_handle.size() && to_handle[i].first < nx) {
			++i;
		}
		ans += 1;
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}