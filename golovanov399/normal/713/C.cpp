#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int inf = 1e9;

struct MinCostFlow {
	struct Edge {
		int from, to;
		int cap, flow;
		int cost;
	};
	
	int n;
	vector<Edge> edges;
	vector<vector<int>> a;

	explicit MinCostFlow(int _n): n(_n), a(_n) {}

	void add_edge(int u, int v, int cap, int cost) {
		a[u].push_back(edges.size());
		edges.push_back({u, v, cap, 0, cost});
		a[v].push_back(edges.size());
		edges.push_back({v, u, 0, 0, -cost});
	}

	vector<int> eid;
	vector<long long> dist;

	void ford_bellman(int s) {
		dist.assign(n, 1e18);
		dist[s] = 0;
		while (true) {
			bool changed = false;
			for (int i = 0; i < (int)edges.size(); ++i) {
				const auto& e = edges[i];
				if (e.flow == e.cap) {
					continue;
				}
				if (dist[e.to] > dist[e.from] + e.cost) {
					dist[e.to] = dist[e.from] + e.cost;
					changed = true;
				}
			}
			if (!changed) {
				break;
			}
		}
	}

	bool build_path(int s, int t) {
		eid.assign(n, -1);
		vector<long long> d(n, 1e18);
		d[s] = 0;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
		pq.push({0, s});
		while (!pq.empty()) {
			auto [dst, v] = pq.top();
			pq.pop();
			if (d[v] != dst) {
				continue;
			}
			for (int i : a[v]) {
				const auto& e = edges[i];
				if (e.cap == e.flow) {
					continue;
				}
				if (d[e.to] - dist[e.to] > dst - dist[v] + e.cost) {
					d[e.to] = dst - dist[v] + e.cost + dist[e.to];
					eid[e.to] = i;
					pq.push({d[e.to], e.to});
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			dist[i] -= d[i];
		}
		return eid[t] > -1;
	}

	long long min_cost_k_flow(int s, int t, int flow) {
		ford_bellman(s);
		long long ans = 0;
		while (flow > 0 && build_path(s, t)) {
			int cost = 0;
			int cur_flow = flow;
			for (int x = t; x != s; x = edges[eid[x]].from) {
				const int id = eid[x];
				cost += edges[id].cost;
				cur_flow = min(cur_flow, edges[id].cap - edges[id].flow);
			}
			flow -= cur_flow;
			ans += 1ll * cur_flow * cost;
			for (int x = t; x != s; x = edges[eid[x]].from) {
				const int id = eid[x];
				edges[id].flow += cur_flow;
				edges[id ^ 1].flow -= cur_flow;
			}
		}
		if (flow > 0) {
			return inf;
		}
		return ans;
	}

	pair<int, long long> min_cost_max_flow(int s, int t) {
		ford_bellman(s);
		int total_flow = 0;
		long long total_cost = 0;
		while (build_path(s, t)) {
			int cost = 0;
			int cur_flow = inf;
			for (int x = t; x != s; x = edges[eid[x]].from) {
				const int id = eid[x];
				cost += edges[id].cost;
				cur_flow = min(cur_flow, edges[id].cap - edges[id].flow);
			}
			if (cur_flow == 0) {
				break;
			}
			total_flow += cur_flow;
			total_cost += 1ll * cur_flow * cost;
			for (int x = t; x != s; x = edges[eid[x]].from) {
				const int id = eid[x];
				edges[id].flow += cur_flow;
				edges[id ^ 1].flow -= cur_flow;
			}
		}
		return {total_flow, total_cost};
	}

	pair<int, long long> min_cost_any_flow(int s, int t) {
		ford_bellman(s);
		int total_flow = 0;
		long long total_cost = 0;
		while (build_path(s, t)) {
			int cost = 0;
			int cur_flow = inf;
			for (int x = t; x != s; x = edges[eid[x]].from) {
				const int id = eid[x];
				cost += edges[id].cost;
				cur_flow = min(cur_flow, edges[id].cap - edges[id].flow);
			}
			if (cur_flow == 0) {
				break;
			}
			if (cost > 0) {
				break;
			}
			total_flow += cur_flow;
			total_cost += 1ll * cur_flow * cost;
			for (int x = t; x != s; x = edges[eid[x]].from) {
				const int id = eid[x];
				edges[id].flow += cur_flow;
				edges[id ^ 1].flow -= cur_flow;
			}
		}
		return {total_flow, total_cost};
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt();
	vector<int> ar(n + 2);
	ar[0] = -n - 10;
	ar[n + 1] = (int)1e9 + 10;
	for (int i = 0; i < n; ++i) {
		ar[i + 1] = nxt() - i;
	}
	vector<int> d(n + 1);
	for (int i = 0; i < n + 1; ++i) {
		d[i] = ar[i + 1] - ar[i];
	}
	MinCostFlow mcf(n + 3);
	for (int i = 0; i < n; ++i) {
		mcf.add_edge(1 + i, 2 + i, inf, 1);
		mcf.add_edge(2 + i, 1 + i, inf, 1);
	}
	for (int i = 0; i < n + 1; ++i) {
		if (d[i] > 0) {
			mcf.add_edge(0, i + 1, d[i], 0);
		}
		if (d[i] < 0) {
			mcf.add_edge(i + 1, n + 2, -d[i], 0);
		}
	}
	cout << mcf.min_cost_max_flow(0, n + 2).second << "\n";

	return 0;
}