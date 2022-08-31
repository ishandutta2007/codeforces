#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, K; cin >> N >> K; K++;
	vector<int64_t> C(N); for (auto& c : C) cin >> c;
	sort(C.begin(), C.end());

	int64_t cur = 0;
	for (int i = 0; i < N; i++) {
		cur += C[i] * (i / K);
	}
	int64_t ans = cur;
	int64_t stacked_sum = 0;
	for (int i = N-1; i >= 0; i--) {
		stacked_sum += C[i];
		if (i % K == 0) {
			// can't actually stack higher
		} else {
			cur += stacked_sum;
		}
		ans = max(ans, cur);
	}

	cout << ans << '\n';

	return 0;
}