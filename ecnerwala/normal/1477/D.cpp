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
		int N, M; cin >> N >> M;
		vector<unordered_set<int>> can_compare(N);
		for (int e = 0; e < M; e++) {
			int u, v; cin >> u >> v; u--, v--;
			can_compare[u].insert(v);
			can_compare[v].insert(u);
		}
		vector<vector<int>> tree_adj(N);
		{
			std::set<int> unvis; for (int i = 0; i < N; i++) unvis.insert(i);
			auto dfs = std::y_combinator([&](auto self, int cur) -> void {
				assert(unvis.count(cur));
				unvis.erase(cur);
				std::vector<int> cur_ch;
				for (int i = 0; true; i++) {
					{
						auto it = unvis.lower_bound(i);
						if (it == unvis.end()) break;
						i = *it;
					}
					if (can_compare[cur].count(i)) continue;
					tree_adj[cur].push_back(i);
					tree_adj[i].push_back(cur);
					self(i);
				}
			});
			while (!unvis.empty()) {
				dfs(*unvis.begin());
			}
		}

		vector<int> P(N, -1), Q(N, -1);
		{
			int idx = 0;
			vector<int> deg(N);
			vector<bool> alive(N, true);
			vector<int> leaves; leaves.reserve(N);
			for (int i = 0; i < N; i++) {
				deg[i] = int(tree_adj[i].size());
				if (deg[i] == 0) {
					P[i] = Q[i] = idx++;
					alive[i] = false;
				} else if (deg[i] == 1) {
					leaves.push_back(i);
				}
			}
			for (int z = 0; z < int(leaves.size()); z++) {
				int cur = leaves[z];
				if (!alive[cur]) continue;
				for (int nxt : tree_adj[cur]) {
					if (!alive[nxt]) continue;
					cur = nxt;
					break;
				}

				alive[cur] = false;
				P[cur] = idx;
				for (int nxt : tree_adj[cur]) {
					if (!alive[nxt]) continue;
					if (deg[nxt] == 1) {
						alive[nxt] = false;
						Q[nxt] = idx;
						idx++;
						P[nxt] = idx;
					} else {
						if (--deg[nxt] == 1) {
							leaves.push_back(nxt);
						}
					}
				}
				Q[cur] = idx;
				idx++;
			}
		}

		for (int i = 0; i < N; i++) {
			cout << P[i]+1 << " \n"[i+1==N];
		}
		for (int i = 0; i < N; i++) {
			cout << Q[i]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}