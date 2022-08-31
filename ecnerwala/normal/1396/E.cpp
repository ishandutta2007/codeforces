#include<bits/stdc++.h>
#include <numeric>

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

	int N; int64_t K; cin >> N >> K;
	assert(N % 2 == 0);
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> sz(N);
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		sz[cur] = 1;
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur);
			sz[cur] += sz[nxt];
		}
	})(0, -1);

	vector<int> edges(N);
	for (int i = 1; i < N; i++) {
		edges[i] = min(sz[i], N - sz[i]);
	}

	int64_t min_K = 0;
	int64_t max_K = 0;
	for (auto e : edges) {
		min_K += e & 1;
		max_K += e;
	}

	if (!(min_K <= K && K <= max_K && (K & 1) == (min_K & 1))) {
		cout << "NO" << '\n';
		exit(0);
	}
	cout << "YES" << '\n';

	auto capped_K = [&](int cap) -> int64_t {
		int64_t res = 0;
		for (auto e : edges) {
			if (e <= cap) {
				res += e;
			} else {
				res += cap - ((e ^ cap) & 1);
			}
		}
		return res;
	};

	assert(min_K == capped_K(1));
	assert(max_K == capped_K(N-1));

	int mi = 0, ma = N-1;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (capped_K(md) >= K) {
			ma = md;
		} else {
			mi = md;
		}
	}

	int cap = ma;
	int64_t extra = capped_K(cap) - K;
	assert(extra % 2 == 0);
	assert(extra >= 0);
	for (auto& e : edges) {
		if (e > cap) {
			e = cap - ((e ^ cap) & 1);
		}
		if (extra && e == cap) {
			e -= 2;
			extra -= 2;
		}
	}
	assert(extra == 0);
	assert(std::accumulate(edges.begin(), edges.end(), int64_t(0)) == K);

	std::y_combinator([&](auto self, int cur, int prv) -> std::list<int> {
		std::list<int> res;
		res.push_back(cur);
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			res.splice(res.end(), self(nxt, cur));
		}
		int num_output = (int(res.size()) - edges[cur]) / 2;
		vector<int> lo(num_output);
		for (int i = 0; i < num_output; i++) {
			lo[i] = res.front(); res.pop_front();
		}
		vector<int> hi(num_output);
		for (int i = 0; i < num_output; i++) {
			hi[i] = res.back(); res.pop_back();
		}
		reverse(hi.begin(), hi.end());
		for (int i = 0; i < num_output; i++) {
			cout << lo[i]+1 << ' ' << hi[i]+1 << '\n';
		}
		return res;
	})(0, -1);

	return 0;
}