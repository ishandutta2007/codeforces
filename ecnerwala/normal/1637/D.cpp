#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::vector<int> B(N);
		for (auto& b : B) cin >> b;
		int tot_sq = 0;
		for (auto a : A) tot_sq += a * a;
		for (auto b : B) tot_sq += b * b;

		using bs = std::bitset<20001>;
		bs cur; cur[0] = true;
		int64_t tot = 0;
		for (int i = 0; i < N; i++) {
			cur = (cur << A[i]) | (cur << B[i]);
			tot += A[i] + B[i];
		}
		int64_t ans = tot * tot;
		for (int i = 0; i < int(cur.size()); i++) {
			if (cur[i]) {
				ans = std::min(ans, (tot - i) * (tot - i) + int64_t(i) * int64_t(i));
			}
		}

		ans += int64_t(tot_sq) * int64_t(N-2);
		cout << ans << '\n';
	}

	return 0;
}