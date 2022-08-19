#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<array<int, 2>> segs; segs.reserve(N+1); segs.resize(N);
		for (auto& s : segs) { cin >> s[0] >> s[1]; s[1]++; }
		vector<int> coords; coords.reserve(2*N);
		for (const auto& s : segs) {
			coords.push_back(s[0]);
			coords.push_back(s[1]);
		}
		sort(coords.begin(), coords.end());
		coords.resize(unique(coords.begin(), coords.end()) - coords.begin());
		int M = int(coords.size());
		for (auto & s : segs) {
			for (auto& x : s) {
				x = int(lower_bound(coords.begin(), coords.end(), x) - coords.begin());
			}
		}

		// sort them in increasing order by length
		sort(segs.begin(), segs.end(), [&](const auto& a, const auto& b) { return a[1] - a[0] < b[1] - b[0]; });
		segs.push_back({0, M-1});
		vector<int> dp(N+1);
		vector<int> x_dp(M);
		for (int i = 0; i <= N; i++) {
			int nxt_x = 0;
			int pref_best = 0;
			fill(x_dp.begin(), x_dp.end(), 0);
			for (int j = 0; j < i; j++) {
				if (segs[i][0] <= segs[j][0] && segs[j][1] <= segs[i][1]) {
					while (nxt_x <= segs[j][0]) {
						pref_best = max(pref_best, x_dp[nxt_x++]);
					}
					x_dp[segs[j][1]] = max(x_dp[segs[j][1]], pref_best + dp[j]);
				}
			}
			while (nxt_x <= segs[i][1]) {
				pref_best = max(pref_best, x_dp[nxt_x++]);
			}
			dp[i] = 1 + pref_best;

			if (i == N) {
				break;
			}
			// insertion sort yourself in
			for (int j = i-1; j >= 0 && segs[j+1] < segs[j]; j--) {
				swap(segs[j+1], segs[j]);
				swap(dp[j+1], dp[j]);
			}
		}
		cout << dp[N]-1 << '\n';
	}

	return 0;
}