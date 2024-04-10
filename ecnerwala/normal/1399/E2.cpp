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
	int T; cin >> T;
	while (T--) {
		int N; int64_t S; cin >> N >> S;
		struct edge {
			int dest;
			int64_t w;
			int c;
		};
		vector<vector<edge>> adj(N);
		for (int e = 0; e < N-1; e++) {
			int u, v; int64_t w; int c; cin >> u >> v >> w >> c; u--, v--;
			adj[u].push_back({v, w, c});
			adj[v].push_back({u, w, c});
		}
		array<priority_queue<tuple<int64_t, int64_t, int64_t>>, 2> pq;
		std::y_combinator([&](auto self, int cur, int prv) -> int {
			if (int(adj[cur].size()) - (prv != -1) == 0) {
				return 1;
			}

			int num_leaves = 0;
			for (const auto& e : adj[cur]) {
				if (e.dest == prv) continue;
				int ch = self(e.dest, cur);
				S -= ch * e.w;
				pq[e.c-1].emplace((e.w + 1) / 2 * ch, ch, e.w / 2);
				num_leaves += ch;
			}
			return num_leaves;
		})(0, -1);
		array<vector<int64_t>, 2> best_sum;
		for (int c = 0; c < 2; c++) {
			int64_t tot_val = 0;
			best_sum[c].push_back(tot_val);
			while (!pq[c].empty()) {
				auto cur = pq[c].top(); pq[c].pop();
				auto [v, ch, w] = cur;
				if (c) best_sum[c].push_back(tot_val);
				tot_val += v;
				best_sum[c].push_back(tot_val);
				if (w) {
					pq[c].emplace((w + 1) / 2 * ch, ch, w / 2);
				}
			}
		}
		int ans = 1e9;
		for (int i = int(best_sum[0].size()) - 1, j = 0; i >= 0 && j < int(best_sum[1].size()); ) {
			if (S + best_sum[0][i] + best_sum[1][j] >= 0) {
				ans = min(ans, i+j);
				i--;
			} else {
				j++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}