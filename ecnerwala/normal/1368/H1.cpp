#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M, Q; cin >> N >> M >> Q;
	array<string, 2> A; cin >> A[0] >> A[1];
	array<string, 2> B; cin >> B[0] >> B[1];
	int64_t ans = 2 * N + 2 * M;
	for (int flip_nm = 0; flip_nm < 2; flip_nm ++, swap(N, M), swap(A, B)) {
		int64_t dp[2] = {0,0};
		for (int i = 0; i < N; i++) {
			bool v = (A[0][i] == 'R');
			dp[!v]++;
		}
		dp[0] = min(dp[0], dp[1]+N);
		dp[1] = min(dp[1], dp[0]+N);
		for (int j = 0; j < M; j++) {
			bool x = (B[0][j] == 'R');
			bool y = (B[1][j] == 'R');
			dp[!x]++;
			dp[!y]++;
			dp[0] = min(dp[0], dp[1]+N);
			dp[1] = min(dp[1], dp[0]+N);
		}
		for (int i = 0; i < N; i++) {
			bool v = (A[1][i] == 'R');
			dp[!v]++;
		}
		ans = min(ans, min(dp[0], dp[1]));
	}
	cout << ans << '\n';

	return 0;
}