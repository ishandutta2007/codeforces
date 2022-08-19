#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) { cin >> a; a--; }
		N = int(std::unique(A.begin(), A.end()) - A.begin());
		A.resize(N);

		std::vector<std::vector<std::pair<int, int>>> jumps(N);
		std::vector<int> dp(N);
		for (int i = 0; i <= N; i++) {
			std::fill(dp.begin(), dp.end(), 0);
			for (int j = i-1; j >= 0; j--) {
				if (i < N && A[j] == A[i]) {
					jumps[i].push_back({j, dp[j] + 1});
				} else {
					for (auto [k, v] : jumps[j]) {
						dp[k] = max(dp[k], dp[j] + v);
					}
				}
				if (j > 0) dp[j-1] = max(dp[j-1], dp[j]);
			}
			if (i == N) {
				cout << N-1-dp[0] << '\n';
			}
		}
	}

	return 0;
}