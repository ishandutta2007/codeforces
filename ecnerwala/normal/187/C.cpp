#include<bits/stdc++.h>

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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M, K; cin >> N >> M >> K;

	vector<int> volunteers(K);
	for (auto& a : volunteers) cin >> a, a--;

	vector<array<int, 2>> edges(M);
	vector<vector<int>> adj(N);
	for (int e = 0; e < M; e++) {
		int u, v; cin >> u >> v; u--, v--;
		edges[e] = {u, v};
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int S, T; cin >> S >> T; S--, T--;

	vector<int> dist(N, -1);
	{
		vector<int> q; q.reserve(N);
		for (int v : volunteers) {
			dist[v] = 0;
			q.push_back(v);
		}
		if (dist[T] == -1) {
			dist[T] = 0;
			q.push_back(T);
		}
		for (int z = 0; z < int(q.size()); z++) {
			int cur = q[z];
			for (int nxt : adj[cur]) {
				if (dist[nxt] == -1) {
					dist[nxt] = dist[cur] + 1;
					q.push_back(nxt);
				}
			}
		}
	}

	vector<int> par(N, -1);
	auto get_par = std::y_combinator([&](auto self, int a) -> int {
		if (par[a] < 0) return a;
		return par[a] = self(par[a]);
	});

	auto merge = [&](int a, int b) -> bool {
		a = get_par(a);
		b = get_par(b);
		if (a == b) return false;
		if (par[a] > par[b]) swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	};

	vector<vector<array<int, 2>>> q_edges(2*N+3);
	for (auto e : edges) {
		if (dist[e[0]] == -1 || dist[e[1]] == -1) continue;
		q_edges[dist[e[0]] + dist[e[1]] + 1].push_back(e);
	}

	for (int q = 0; q < int(q_edges.size()); q++) {
		for (auto e : q_edges[q]) {
			merge(e[0], e[1]);
		}
		if (get_par(S) == get_par(T)) {
			cout << q << '\n';
			exit(0);
		}
	}
	cout << -1 << '\n';

	return 0;
}