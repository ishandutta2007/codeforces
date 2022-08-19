#include <bits/stdc++.h>

const int64_t MOD = int(1e9)+7;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t N; cin >> N;

		int64_t ans = N % MOD;
		int64_t cur = 1;
		for (int v = 1; true; v++) {
			cur = std::lcm(cur, v);
			if (cur > N) break;
			ans += N / cur;
			ans %= MOD;
		}
		cout << ans << '\n';
	}


	return 0;
}