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
		struct node_data {
			int A, B;
		};
		std::vector<node_data> V(N);
		V[0].A = -1, V[0].B = 0;
		for (int i = 1; i < N; i++) cin >> V[i].A;
		for (int i = 1; i < N; i++) cin >> V[i].B;

		std::vector<std::vector<std::pair<int, int>>> adj(N);
		for (int e = 0; e < M; e++) {
			int u, v; cin >> u >> v; u--, v--;
			adj[u].push_back({v, e});
			adj[v].push_back({u, e});
		}

		auto is_good = [&](int64_t st) -> bool {
			std::vector<bool> vis(N);
			vis[0] = true;

			std::vector<int> par(N, -1);
			while (true) {
				int64_t rootVal = st;
				{
					bool done = true;
					for (int i = 0; i < N; i++) {
						if (!vis[i]) {
							done = false;
						} else {
							rootVal += V[i].B;
						}
					}
					if (done) return true;
				}

				std::fill(par.begin(), par.end(), -1);

				auto dfs = std::y_combinator([&](auto self, int cur, int prvE, int64_t curVal) -> bool {
					for (auto [nxt, e] : adj[cur]) {
						if (e == prvE) continue;
						if (vis[nxt]) {
							if (prvE == -1) continue;
							return true;
						}
						if (curVal <= V[nxt].A) continue;
						if (par[nxt] == -1) {
							par[nxt] = cur;
							if (self(nxt, e, curVal + V[nxt].B)) {
								vis[nxt] = true;
								return true;
							}
						} else {
							for (int a = nxt; a != -1; a = par[a]) vis[a] = true;
							return true;
						}
					}
					return false;
				});
				bool found = false;
				for (int i = 0; i < N; i++) {
					if (vis[i]) {
						if (dfs(i, -1, rootVal)) {
							found = true;
							break;
						}
					}
				}
				if (!found) return false;
			}
		};

		int mi = -1;
		int ma = 0;
		for (int i = 1; i < N; i++) ma = max(ma, V[i].A+1);

		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			if (is_good(md)) ma = md;
			else mi = md;
		}
		cout << ma << '\n';
	}

	return 0;
}