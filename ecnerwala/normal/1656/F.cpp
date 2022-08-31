#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int64_t> A(N);
		for (auto& a : A) cin >> a;

		std::sort(A.begin(), A.end());

		std::vector<int64_t> pref(N+1);
		for (int i = 0; i < N; i++) pref[i+1] = pref[i] + A[i];

		if (pref[N] + A[0] * (N-2) > 0) {
			cout << "INF" << '\n';
		} else if (pref[N] + A[N-1] * (N-2) < 0) {
			cout << "INF" << '\n';
		} else {
			int64_t ans = -8e18;
			if (N == 2) {
				ans = A[0] * A[N-1];
			}
			for (int i = 1; i+1 < N; i++) {
				int64_t cnd = -A[i] * A[i];
				cnd += pref[i] * (A[N-1] - A[i]) - i * A[i] * A[N-1];
				cnd += (pref[N] - pref[i+1]) * (A[0] - A[i]) - (N - (i+1)) * A[i] * A[0];
				cnd -= A[0] * A[N-1] - A[i] * (A[0] + A[N-1]);
				ans = std::max(ans, cnd);
			}
			cout << ans << '\n';
		}
	}

	return 0;
}