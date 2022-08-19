#include<bits/stdc++.h>

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		// We need all runs to have length <= 2
		// RRR means that center guy is attacked by exactly 1, but is attacking the wrong guy
		// we have 4 states: 1L, 2L, 1R, 2R
		const int INF = int(1e9);
		int ans = INF;
		for (int st = 0; st < 4; st++) {
			array<int, 4> dp{INF,INF,INF,INF};
			dp[st] = 0;
			for (int i = 0; i < N; i++) {
				array<int, 4> ndp{INF,INF,INF,INF};
				{ // take L
					setmin(ndp[1], dp[0] + (S[i] != 'L'));
					setmin(ndp[0], dp[2] + (S[i] != 'L'));
					setmin(ndp[0], dp[3] + (S[i] != 'L'));
				}
				{ // take R
					setmin(ndp[3], dp[2] + (S[i] != 'R'));
					setmin(ndp[2], dp[0] + (S[i] != 'R'));
					setmin(ndp[2], dp[1] + (S[i] != 'R'));
				}
				dp = ndp;
			}
			setmin(ans, dp[st]);
		}
		cout << ans << '\n';
	}

	return 0;
}