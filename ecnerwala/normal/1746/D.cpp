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
		int N, K; cin >> N >> K;
		std::vector<int> P(N);
		P[0] = -1;
		for (int i = 1; i < N; i++) { cin >> P[i]; P[i]--; }

		std::vector<int> S(N);
		for (auto& s : S) cin >> s;

		std::vector<std::vector<int>> ch(N);
		for (int i = 1; i < N; i++) ch[P[i]].push_back(i);

		cout << std::y_combinator([&](auto self, int cur, int cnt) -> std::array<int64_t, 2> {
			std::array<int64_t, 2> ans{int64_t(cnt) * int64_t(S[cur]), int64_t(cnt+1) * int64_t(S[cur])};

			int L = int(ch[cur].size());
			if (L == 0) return ans;

			std::vector<int64_t> diffs(L);
			for (int z = 0; z < L; z++) {
				int nxt = ch[cur][z];
				auto [v0, v1] = self(nxt, cnt / L);
				diffs[z] = v1 - v0;
				ans[0] += v0;
				ans[1] += v0;
			}

			std::nth_element(diffs.begin(), diffs.begin() + (cnt % L), diffs.end(), std::greater<>());
			int64_t e0 = std::accumulate(diffs.begin(), diffs.begin() + (cnt % L), int64_t(0));
			ans[0] += e0;
			int64_t e1 = e0 + diffs[cnt % L];
			ans[1] += e1;
			return ans;
		})(0, K)[0] << '\n';
	}

	return 0;
}