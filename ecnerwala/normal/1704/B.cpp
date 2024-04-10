#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, X; cin >> N >> X; X *= 2;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		int ans = 0;
		int cur_lo = A[0], cur_hi = A[0];
		for (int i = 1; i < N; i++) {
			cur_lo = std::min(cur_lo, A[i]);
			cur_hi = std::max(cur_hi, A[i]);
			if (cur_hi - cur_lo > X) {
				ans++;
				cur_lo = cur_hi = A[i];
			}
		}
		cout << ans << '\n';
	}

	return 0;
}