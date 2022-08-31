#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<string> G(N); for (auto& s : G) cin >> s;
	vector<vector<int>> dp(N, vector<int>(M));
	int64_t ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i >= 2 && j-1 >= 0 && j+1 < M && G[i][j] == G[i-1][j-1] && G[i][j] == G[i-1][j] && G[i][j] == G[i-1][j+1] && G[i][j] == G[i-2][j]) {
				dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j+1], dp[i-2][j]});
			} else {
				dp[i][j] = 1;
			}
			ans += dp[i][j];
		}
	}
	cout << ans << '\n';

	return 0;
}