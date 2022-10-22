#include <iostream>

using namespace std;

int dp[2][1005];
int s[2][1005];

const int mod = 1000000007;

int main() {
	int N, M, K; cin >> N >> M >> K;
	for (int i = 3; i <= max(N, M); ++i) {
		dp[1][i] = dp[1][i - 1] + (i - 2);
		if (dp[1][i] >= mod)
			dp[1][i] -= mod;
		s[1][i] = s[1][i - 1] + dp[1][i];
		if (s[1][i] >= mod)
			s[1][i] -= mod;
	}

	for (int i = 2; i <= K; ++i)
		for (int j = 3; j <= max(N, M); ++j) {
			dp[i & 1][j] = dp[i & 1][j - 1] + s[i - 1 & 1][j - 2];
			if (dp[i & 1][j] >= mod)
				dp[i & 1][j] -= mod;
			s[i & 1][j] = s[i & 1][j - 1] + dp[i & 1][j];
			if (s[i & 1][j] >= mod)
				s[i & 1][j] -= mod;
		}
	cout << (1LL * dp[K & 1][N] * dp[K & 1][M]) % mod;
}