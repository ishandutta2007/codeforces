#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, D, M; cin >> N >> D >> M;
	vector<int> A(N); for (auto& a : A) cin >> a;
	sort(A.begin(), A.end());

	vector<int64_t> pref(N+1);
	for (int i = 0; i < N; i++) pref[i+1] = pref[i] + A[i];

	int K = int(upper_bound(A.begin(), A.end(), M) - A.begin());
	assert(0 <= K && K <= N);

	int64_t ans = 0;
	for (int num_lo = 0; num_lo <= K; num_lo++) {
		int num_hi = (N - num_lo + D) / (D+1);
		if (num_hi <= N-K) {
			ans = max(ans, pref[N] - pref[N - num_hi] + pref[K] - pref[K - num_lo]);
		}
	}
	cout << ans << '\n';

	return 0;
}