#include <bits/extc++.h>

#define hi_scott main

template <typename flow_t = int, typename cost_t = long long>
struct MCMF_SSPA {
	int N;
	std::vector<std::vector<int>> adj;
	struct edge_t {
		int dest;
		flow_t cap;
		cost_t cost;
	};
	std::vector<edge_t> edges;

	std::vector<char> seen;
	std::vector<cost_t> pi;
	std::vector<int> prv;

	explicit MCMF_SSPA(int N_) : N(N_), adj(N), pi(N, 0), prv(N) {}

	void addEdge(int from, int to, flow_t cap, cost_t cost) {
		assert(cap >= 0);
		assert(cost >= 0); // TODO: Remove this restriction
		int e = int(edges.size());
		edges.emplace_back(edge_t{to, cap, cost});
		edges.emplace_back(edge_t{from, 0, -cost});
		adj[from].push_back(e);
		adj[to].push_back(e+1);
	}

	const cost_t INF_COST = std::numeric_limits<cost_t>::max() / 4;
	const flow_t INF_FLOW = std::numeric_limits<flow_t>::max() / 4;
	std::vector<cost_t> dist;
	__gnu_pbds::priority_queue<std::pair<cost_t, int>> q;
	std::vector<typename decltype(q)::point_iterator> its;
	void path(int s) {
		dist.assign(N, INF_COST);
		dist[s] = 0;

		its.assign(N, q.end());
		its[s] = q.push({0, s});

		while (!q.empty()) {
			int i = q.top().second; q.pop();
			cost_t d = dist[i];
			for (int e : adj[i]) {
				if (edges[e].cap) {
					int j = edges[e].dest;
					cost_t nd = d + edges[e].cost;
					if (nd < dist[j]) {
						dist[j] = nd;
						prv[j] = e;
						if (its[j] == q.end()) {
							its[j] = q.push({-(dist[j] - pi[j]), j});
						} else {
							q.modify(its[j], {-(dist[j] - pi[j]), j});
						}
					}
				}
			}
		}

		swap(pi, dist);
	}

	std::pair<flow_t, cost_t> maxflow(int s, int t) {
		assert(s != t);
		flow_t totFlow = 0; cost_t totCost = 0;
		while (path(s), pi[t] < INF_COST) {
			flow_t curFlow = std::numeric_limits<flow_t>::max();
			for (int cur = t; cur != s; ) {
				int e = prv[cur];
				int nxt = edges[e^1].dest;
				curFlow = std::min(curFlow, edges[e].cap);
				cur = nxt;
			}
			totFlow += curFlow;
			totCost += pi[t] * curFlow;
			for (int cur = t; cur != s; ) {
				int e = prv[cur];
				int nxt = edges[e^1].dest;
				edges[e].cap -= curFlow;
				edges[e^1].cap += curFlow;
				cur = nxt;
			}
		}
		return {totFlow, totCost};
	}
};

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

int hi_scott() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int D, M; cin >> D >> M;

	const int INF = 1e9;

	MCMF_SSPA flow((1<<D)*2+2);
	int S = (1<<D)*2;
	int T = S+1;
	for (int m = 0; m < (1 << D); m++) {
		flow.addEdge(2*m, 2*m+1, INF, 0);
		flow.addEdge(2*m+1, 2*0, INF, 1);
		for (int i = 0; i < D; i++) {
			if (m & (1 << i)) continue;
			flow.addEdge(2*m+1, 2*(m+(1<<i)), INF, 1);
		}
	}
	for (int j = 0; j < M; j++) {
		string s; cin >> s;
		int m = 0;
		for (int i = 0; i < D; i++) m |= (s[i] - '0') << i;
		flow.addEdge(S, 2*m+1, 1, 0);
		flow.addEdge(2*m, T, 1, 0);
	}

	auto [f, c] = flow.maxflow(S, T);
	assert(f == M);
	vector<char> ops; ops.reserve(c);

	vector<vector<pair<int, char>>> adj(1<<D);
	for (int e = 0; e < int(flow.edges.size()); e += 2) {
		int u = flow.edges[e+1].dest;
		int v = flow.edges[e].dest;
		if (u == S || v == T) continue;
		if ((u ^ v) == 1) continue;
		assert(u & 1);
		assert(!(v & 1));
		u >>= 1;
		v >>= 1;
		assert(v == 0 || __builtin_popcount(u^v) == 1);
		char op = (v == 0) ? 'R' : char('0' + __builtin_ctz(u ^ v));
		for (int z = 0; z < flow.edges[e+1].cap; z++) {
			adj[v].push_back({u, op});
		}
	}

	std::y_combinator([&](auto self, int cur) -> void {
		while (!adj[cur].empty()) {
			auto [nxt, op] = adj[cur].back();
			adj[cur].pop_back();
			self(nxt);
			ops.push_back(op);
		}
	})(0);

	assert(ops.back() == 'R');
	ops.pop_back();
	cout << ops.size() << '\n';
	for (int z = 0; z < int(ops.size()); z++) {
		cout << ops[z] << " \n"[z+1==int(ops.size())];
	}

	return 0;
}