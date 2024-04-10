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
	int N; cin >> N;

	struct edge_t {
		array<int, 2> v;
		int t;
	};
	vector<edge_t> edges(N-1);
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v, t; cin >> u >> v >> t; u--, v--;
		edges[e] = {{u, v}, t};
		adj[u].push_back(e);
		adj[v].push_back(e);
	}

	auto get_furthest = std::y_combinator([&](auto self, int cur, int prvE = -1) -> pair<int, int> {
		pair<int, int> res(0, cur);
		for (int e : adj[cur]) {
			if (e == prvE) continue;
			int nxt = edges[e].v[0] ^ edges[e].v[1] ^ cur;
			auto ch = self(nxt, e);
			ch.first++;
			res = max(res, ch);
		}
		return res;
	});

	array<int, 2> ROOTS;
	ROOTS[0] = get_furthest(0).second;
	ROOTS[1] = get_furthest(ROOTS[0]).second;

	struct rooted_solver {
		struct seg_node {
			array<int, 2> val;
			bool lazy;
		};
		vector<seg_node> seg;
		vector<array<int, 2>> bounds;
	};
	auto build = [&](int root) -> rooted_solver {
		rooted_solver r;
		r.seg.resize(2*N);
		r.bounds.resize(N-1);

		int idx = 0;
		std::y_combinator([&](auto self, int cur, int prvE = -1, int depth = 0, bool flip = false) -> void {
			r.seg[N+idx].val = {0, 0};
			r.seg[N+idx].val[flip] = depth;
			r.seg[N+idx].lazy = false;
			idx++;
			for (int e : adj[cur]) {
				if (e == prvE) continue;
				int nxt = edges[e].v[0] ^ edges[e].v[1] ^ cur;
				r.bounds[e][0] = idx;
				self(nxt, e, depth+1, flip ^ edges[e].t);
				r.bounds[e][1] = idx;
			}
		})(root);
		assert(idx == N);
		for (int a = N-1; a; a--) {
			r.seg[a].val[0] = max(r.seg[2*a].val[0], r.seg[2*a+1].val[0]);
			r.seg[a].val[1] = max(r.seg[2*a].val[1], r.seg[2*a+1].val[1]);
			r.seg[a].lazy = false;
		}

		return r;
	};
	auto update_all = [&](rooted_solver& r, int a) {
		a += N;
		a >>= __builtin_ctz(a);
		for (a >>= 1; a > 0; a >>= 1) {
			r.seg[a].val[0] = max(r.seg[2*a].val[0], r.seg[2*a+1].val[0]);
			r.seg[a].val[1] = max(r.seg[2*a].val[1], r.seg[2*a+1].val[1]);
			if (r.seg[a].lazy) {
				swap(r.seg[a].val[0], r.seg[a].val[1]);
			}
		}
	};
	auto flip_edge = [&](rooted_solver& s, int e) {
		auto [l, r] = s.bounds[e];
		for (int a = N+l, b = N+r; a < b; a >>= 1, b >>= 1) {
			if (a & 1) {
				s.seg[a].lazy ^= 1;
				swap(s.seg[a].val[0], s.seg[a].val[1]);
				a++;
			}
			if (b & 1) {
				--b;
				s.seg[b].lazy ^= 1;
				swap(s.seg[b].val[0], s.seg[b].val[1]);
			}
		}
		update_all(s, l);
		update_all(s, r);
	};
	auto query = [&](const rooted_solver& s) {
		return s.seg[1].val[0];
	};

	array<rooted_solver, 2> solvers{build(ROOTS[0]), build(ROOTS[1])};

	int Q; cin >> Q;
	while (Q--) {
		int e; cin >> e; e--;
		flip_edge(solvers[0], e);
		flip_edge(solvers[1], e);
		cout << max(query(solvers[0]), query(solvers[1])) << '\n';
	}

	return 0;
}