#include<bits/stdc++.h>
using namespace std;

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
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<pair<int, int>> ops;
	std::y_combinator([&](auto self, int cur, int prv, int t) -> int {
		ops.emplace_back(cur, t);
		int d = int(adj[cur].size());
		bool subtracted = false;
		if (!subtracted && t >= d) {
			t -= d;
			ops.emplace_back(cur, t);
			subtracted = true;
		}
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			t = self(nxt, cur, t+1);
			ops.emplace_back(cur, t);
			if (!subtracted && t >= d) {
				t -= d;
				ops.emplace_back(cur, t);
				subtracted = true;
			}
		}
		return t+1;
	})(0, -1, 0);

	ops.pop_back();

	cout << ops.size() << '\n';
	for (auto it : ops) {
		cout << it.first+1 << ' ' << it.second << '\n';
	}

	return 0;
}