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
	int N, M, K; cin >> N >> M >> K;
	vector<vector<pair<int, int>>> outEdges(N);
	for (int e = 0; e < M; e++) {
		int u, v, w; cin >> u >> v >> w; u--, v--, w--;
		outEdges[u].emplace_back(w, v);
	}
	vector<vector<int>> inEdges(N);
	for (int i = 0; i < N; i++) {
		sort(outEdges[i].begin(), outEdges[i].end());
		int k = int(outEdges[i].size());
		for (int j = 0; j < k; j++) {
			inEdges[outEdges[i][j].second].push_back(k * (k-1) / 2 + j);
		}
	}
	uint64_t incompat[45];
	memset(incompat, 0, sizeof(incompat));
	for (int i = 0; i < N; i++) {
		sort(inEdges[i].begin(), inEdges[i].end());
		for (int j = 0; j+1 < int(inEdges[i].size()); j++) {
			// Handle equal
			if (inEdges[i][j] == inEdges[i][j+1]) {
				incompat[inEdges[i][j]] |= (uint64_t(1) << inEdges[i][j+1]);
			}
		}
		inEdges[i].erase(unique(inEdges[i].begin(), inEdges[i].end()), inEdges[i].end());
		for (int j = 0; j < int(inEdges[i].size()); j++) {
			for (int k = j+1; k < int(inEdges[i].size()); k++) {
				incompat[inEdges[i][j]] |= (uint64_t(1) << inEdges[i][k]);
				incompat[inEdges[i][k]] |= (uint64_t(1) << inEdges[i][j]);
			}
		}
	}

	int ans = 0;
	std::y_combinator([&](auto self, int i, uint64_t msk) -> void {
		if (i == K) {
			ans++;
			return;
		}
		i++;
		for (int x = 0; x < i; x++) {
			int ind = i * (i-1) / 2 + x;
			uint64_t nmsk = msk | (uint64_t(1) << ind);
			if (nmsk & incompat[ind]) continue;
			self(i, nmsk);
		}
	})(0, 0);

	cout << ans << '\n';

	return 0;
}

// Just need all indegree < 2