#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int64_t N, K; cin >> N >> K;
		int64_t L1, R1, L2, R2; cin >> L1 >> R1 >> L2 >> R2;
		int64_t initial_len = (R1 - L1) + (R2 - L2);
		int64_t initial_union = max(R1, R2) - min(L1, L2);
		assert(initial_len <= initial_union * 2);
		int64_t ans;
		if (initial_len < initial_union) {
			if (K >= initial_union * N) {
				ans = 2 * K - initial_len * N;
			} else if (K <= initial_union) {
				ans = K + (initial_union - initial_len);
			} else {
				ans = K + (K / initial_union) * (initial_union - initial_len) + min(initial_union - initial_len, K % initial_union);
			}
		} else {
			K -= (initial_len - initial_union) * N;
			if (K < 0) K = 0;
			int64_t tot_free = (initial_union * 2 - initial_len) * N;
			ans = 2 * K - min(K, tot_free);
		}
		cout << ans << '\n';
	}

	return 0;
}