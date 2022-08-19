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
		};
		vector<vector<edge>> adj(N);
		for (int e = 0; e < N-1; e++) {
			int u, v; int64_t w; cin >> u >> v >> w; u--, v--;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		priority_queue<tuple<int64_t, int64_t, int64_t>> pq;
		std::y_combinator([&](auto self, int cur, int prv) -> int {
			if (int(adj[cur].size()) - (prv != -1) == 0) {
				return 1;
			}

			int num_leaves = 0;
			for (const auto& e : adj[cur]) {
				if (e.dest == prv) continue;
				int ch = self(e.dest, cur);
				S -= ch * e.w;
				pq.emplace((e.w + 1) / 2 * ch, ch, e.w / 2);
				num_leaves += ch;
			}
			return num_leaves;
		})(0, -1);
		int ans = 0;
		while (S < 0) {
			ans++;
			auto cur = pq.top(); pq.pop();
			auto [v, ch, w] = cur;
			S += v;
			pq.emplace((w + 1) / 2 * ch, ch, w / 2);
		}
		cout << ans << '\n';
	}

	return 0;
}