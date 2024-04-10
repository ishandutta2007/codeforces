#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;

		int L = 0;
		for (int j = 0; j < M; j++) {
			int b; cin >> b;
			L = std::gcd(L, b);
		}

		std::array<int64_t, 2> ans{0, 0};
		for (int m = 0; m < L; m++) {
			std::array<int64_t, 2> dp{0, -int64_t(1e18)};
			for (int i = m; i < N; i += L) {
				dp = {std::max(dp[0] + A[i], dp[1] - A[i]), std::max(dp[0] - A[i], dp[1] + A[i])};
			}
			ans[0] += dp[0];
			ans[1] += dp[1];
		}
		cout << std::max(ans[0], ans[1]) << '\n';
	}

	return 0;
}