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

	while (true) {
		int N, NPATHS; cin >> N >> NPATHS;
		if (N == 0) break;

		vector<vector<int>> cactus_adj(N);

		for (int z = 0; z < NPATHS; z++) {
			int s; cin >> s;
			int prv; cin >> prv; prv--;
			for (int i = 1; i < s; i++) {
				int nxt; cin >> nxt; nxt--;
				cactus_adj[prv].push_back(nxt);
				cactus_adj[nxt].push_back(prv);
				prv = nxt;
			}
		}

		vector<int> deg(N);
		for (int i = 0; i < N; i++) {
			deg[i] = int(cactus_adj[i].size()) & 1;
		}

		vector<array<int, 2>> paths; paths.reserve(N);

		vector<vector<int>> tree_adj(N);
		{
			vector<int> depth(N, -1);
			depth[0] = 0;
			std::y_combinator([&](auto self, int cur, int prv) -> pair<int, int> {
				int res = depth[cur];
				int cur_path = -1;
				for (int nxt : cactus_adj[cur]) {
					if (nxt == prv) continue;
					if (depth[nxt] == -1) {
						depth[nxt] = depth[cur] + 1;
						auto [chloval, chpath] = self(nxt, cur);
						res = min(res, chloval);
						if (chpath != -1) {
							if (cur_path != -1) {
								paths.push_back({chpath, cur_path});
								cur_path = -1;
							} else {
								cur_path = chpath;
							}
						}
					} else if (depth[nxt] < depth[cur]) {
						res = min(res, depth[nxt]);
					}
				}
				if (res == depth[cur] && prv != -1) {
					if (deg[cur] && deg[prv]) {
						deg[cur]--;
						deg[prv]--;
					} else {
						if (cur_path == -1) {
							cur_path = cur;
						}
					}
				} else {
					if (cur_path != -1) {
						paths.push_back({cur_path, cur});
						cur_path = -1;
					}
				}
				return {res, cur_path};
			})(0, -1);
		}



		cout << paths.size() << '\n';
		for (auto it : paths) {
			cout << it[0]+1 << ' ' << it[1]+1 << '\n';
		}

	}

	return 0;
}