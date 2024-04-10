#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, MOD; cin >> N >> MOD;
	std::vector<int64_t> dp(N+1);
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (i == 2) {
			dp[i] = 2;
		} else {
			dp[i] += 2 * dp[i-1];
			dp[i] ++;
			dp[i] %= MOD;
		}

		int64_t v = dp[i] - dp[i-1] + MOD;
		for (int j = i+i; j <= N; j += i) {
			dp[j] += v;
		}
	}
	cout << dp[N] << '\n';

	return 0;
}