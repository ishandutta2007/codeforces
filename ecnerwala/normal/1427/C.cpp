#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int R, N; cin >> R >> N;
	struct celeb {
		int T, X, Y;
	};

	vector<celeb> pts(N+1);
	vector<int> dp(N+1, -1);
	vector<int> pref(N+1, 0);
	pts[0] = {0, 1, 1};
	dp[0] = 0, pref[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> pts[i].T >> pts[i].X >> pts[i].Y;
		for (int j = i-1; j >= 0; j--) {
			if (pts[i].T - pts[j].T >= 2 * R) {
				dp[i] = max(dp[i], pref[j] + 1);
				break;
			}
			if (dp[j] != -1 && pts[i].T - pts[j].T >= abs(pts[i].X - pts[j].X) + abs(pts[i].Y - pts[j].Y)) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		pref[i] = max(pref[i-1], dp[i]);
	}
	cout << pref[N] << '\n';

	return 0;
}