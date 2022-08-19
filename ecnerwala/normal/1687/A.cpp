#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; int64_t K; cin >> N >> K;
		std::vector<int64_t> A(N); for (auto& a : A) cin >> a;
		int64_t ans = 0;
		if (K < N) {
			int64_t v = 0;
			for (int i = 0; i < K; i++) {
				v += A[i];
			}
			ans = v;
			for (int i = K; i < N; i++) {
				v -= A[i-K];
				v += A[i];
				ans = std::max(ans, v);
			}
			ans += K * int64_t(K-1) / 2;
		} else {
			ans += std::accumulate(A.begin(), A.end(), int64_t(0));
			ans += N * int64_t(K-1 + K-N) / 2;
		}
		cout << ans << '\n';
	}

	return 0;
}