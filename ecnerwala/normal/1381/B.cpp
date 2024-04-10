#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> P(2*N+1);
		for (int i = 0; i < 2*N; i++) {
			cin >> P[i];
		}
		P[2*N] = 2*N+1;
		int cur_max = P[0];
		int max_ind = 0;
		vector<bool> dp(N+1);
		dp[0] = true;
		for (int i = 1; i <= 2*N; i++) {
			if (P[i] > cur_max) {
				int len = i - max_ind;
				cur_max = P[i];
				max_ind = i;
				for (int j = N; j >= len; --j) {
					if (dp[j-len]) dp[j] = true;
				}
			}
		}
		cout << (dp[N] ? "YES" : "NO") << '\n';
	}

	return 0;
}