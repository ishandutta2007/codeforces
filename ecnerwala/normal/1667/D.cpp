#include <bits/stdc++.h>

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
		int N; cin >> N;
		std::vector<std::array<int, 2>> edges(N-1);
		std::vector<std::vector<std::pair<int, int>>> adj(N);
		for (int e = 0; e < N-1; e++) {
			int u, v; cin >> u >> v; u--, v--;
			edges[e] = {u, v};
			adj[u].push_back({e, v});
			adj[v].push_back({e, u});
		}

		std::vector<int> edge_type(N-1);

		std::vector<int> inDeg(N-1);
		std::vector<vector<int>> outEdges(N-1);

		std::vector<int> tmp0; tmp0.reserve(N-1);
		std::vector<int> tmp1; tmp1.reserve(N-1);
		if (!std::y_combinator([&](auto self, int cur, int prvE) -> bool {
			std::array<int, 2> cnt{0,0};
			for (auto [e, nxt] : adj[cur]) {
				if (e == prvE) continue;
				if (!self(nxt, e)) return false;
				cnt[edge_type[e]]++;
			}
			if (prvE != -1) {
				edge_type[prvE] = cnt[0] > cnt[1];
				cnt[edge_type[prvE]]++;
			}
			if (cnt[0] - cnt[1] > 1 || cnt[0] - cnt[1] < 0) return false;
			for (auto [e, _] : adj[cur]) {
				if (edge_type[e] == 0) tmp0.push_back(e);
				else tmp1.push_back(e);
			}
			int prv = -1;
			for (int z = int(adj[cur].size())-1; z >= 0; z--) {
				int cur = ((z & 1) ? tmp1 : tmp0).back();
				((z & 1) ? tmp1 : tmp0).pop_back();
				if (prv != -1) {
					inDeg[cur]++;
					outEdges[prv].push_back(cur);
				}
				prv = cur;
			}
			return true;
		})(0, -1)) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		std::vector<int> q; q.reserve(N-1);
		for (int i = 0; i < N-1; i++) {
			if (inDeg[i] == 0) q.push_back(i);
		}
		for (int z = 0; z < N-1; z++) {
			int cur = q[z];
			cout << edges[cur][0]+1 << ' ' << edges[cur][1]+1 << '\n';
			for (int nxt : outEdges[cur]) {
				if ((--inDeg[nxt]) == 0) q.push_back(nxt);
			}
		}
	}

	return 0;
}