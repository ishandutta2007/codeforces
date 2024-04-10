#include<bits/stdc++.h>

// #include "yc.hpp"
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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	assert(N >= 3);

	vector<int> depth(N);
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			depth[nxt] = depth[cur] ^ 1;
			self(nxt, cur);
		}
	})(0, -1);

	int maxF = N-1;
	vector<bool> hasLeaf(N);

	bool leafParity[2] = {false, false};

	for (int i = 0; i < N; i++) {
		if (int(adj[i].size()) == 1) {
			leafParity[depth[i]] = true;
			int j = adj[i].front();
			assert(adj[j].size() != 1);
			if (!hasLeaf[j]) {
				hasLeaf[j] = true;
			} else {
				maxF--;
			}
		}
	}

	int minF = (leafParity[0] && leafParity[1] ? 3 : 1);
	cout << minF << ' ' << maxF << '\n';

	return 0;
}