#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> P(N);
		P[0] = -1;
		for (int i = 1; i < N; i++) {
			cin >> P[i]; P[i]--;
		}
		std::vector<std::array<int, 2>> bounds(N);
		for (auto& [lo, hi] : bounds) cin >> lo >> hi;

		int ans = 0;

		std::vector<int64_t> val(N, 0);
		for (int i = N-1; i >= 0; i--) {
			if (val[i] < bounds[i][0]) {
				val[i] = bounds[i][1];
				ans++;
			} else if (val[i] > bounds[i][1]) {
				val[i] = bounds[i][1];
			}
			if (i) {
				val[P[i]] += val[i];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}