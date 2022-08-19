#include<bits/stdc++.h>

template <typename T> void setmax(T& a, const T& b) { if (b > a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, K, Z; cin >> N >> K >> Z;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		int ans = 0;
		vector<vector<int>> dp(N, vector<int>(Z+1));
		dp[0][0] = A[0];
		for (int i = 0; i < N; i++) {
			for (int z = 0; z <= Z; z++) {
				setmax(ans, dp[i][z]);
				if (i + 2*z >= K) continue;
				if (i < N-1) {
					setmax(dp[i+1][z], dp[i][z] + A[i+1]);
				}
				if (i >= 1 && z < Z) {
					setmax(ans, dp[i][z] + A[i-1]);
					if (i + 2*z + 2 <= K) {
						setmax(dp[i][z+1], dp[i][z] + A[i-1] + A[i]);
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}