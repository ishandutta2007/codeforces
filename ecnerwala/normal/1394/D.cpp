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
	vector<int> T(N); for (auto& v : T) cin >> v;
	vector<int> H(N); for (auto& v : H) cin >> v;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ROOT = 0;
	while (adj[ROOT].size() > 1) ROOT++;
	assert(N >= 2);
	assert(adj[ROOT].size() == 1);

	const int64_t INF = 1e12;
	auto root_ans = std::y_combinator([&](auto self, int cur, int prv) -> array<int64_t, 2> {
		vector<int64_t> cost; cost.reserve(adj[cur].size());
		cost.push_back(0);
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			auto ch = self(nxt, cur);
			swap(ch[0], ch[1]);
			cost[0] += ch[0];
			cost.push_back(ch[1] - ch[0]);
		}
		sort(cost.begin()+1, cost.end());
		for (int i = 1; i < int(cost.size()); i++) {
			cost[i] += cost[i-1];
		}
		array<int64_t, 2> resp{INF, INF};
		for (int z = 0; z < 2; z++) {
			for (int i = 0; i < int(cost.size()); i++) {
				int num[2] = {int(cost.size()) - 1 - i, i};
				num[z]++;
				resp[z] = min(resp[z], int64_t(T[cur]) * max(num[0], num[1]) + cost[i]);
			}
		}

		if (H[cur] > H[prv]) {
			resp[0] = INF;
		} else if (H[cur] < H[prv]) {
			resp[1] = INF;
		}

		return resp;
	})(adj[ROOT][0], ROOT);
;
	int64_t ans = min(root_ans[0], root_ans[1]) + T[ROOT];
	cout << ans << '\n';

	return 0;
}