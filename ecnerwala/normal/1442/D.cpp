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
	int N, K; cin >> N >> K;
	int L = 0;
	vector<int64_t> Atot(N);
	vector<vector<int>> A(N);
	for (int i = 0; i < N; i++) {
		int t; cin >> t; L += t;
		A[i].resize(t);
		for (auto& a : A[i]) cin >> a, Atot[i] += a;
	}

	int64_t ans = 0;
	std::y_combinator([&](auto self, int lo, int hi, std::vector<int64_t> dp) -> void {
		if (hi - lo == 1) {
			int64_t pref = 0;
			for (int v = 0; v <= K; v++) {
				ans = max(ans, pref + dp[K-v]);
				if (v == int(A[lo].size())) break;
				pref += A[lo][v];
			}
			return;
		}
		int md = lo + (hi-lo)/2;
		{
			vector<int64_t> dp2 = dp;
			for (int i = lo; i < md; i++) {
				for (int k = K, l = K - int(A[i].size()); l >= 0; k--, l--) {
					dp2[k] = max(dp2[k], dp2[l] + Atot[i]);
				}
			}
			self(md, hi, dp2);
		}
		{
			for (int i = md; i < hi; i++) {
				for (int k = K, l = K - int(A[i].size()); l >= 0; k--, l--) {
					dp[k] = max(dp[k], dp[l] + Atot[i]);
				}
			}
			self(lo, md, dp);
		}
	})(0,N,vector<int64_t>(K+1,0));
	cout << ans << '\n';

	return 0;
}