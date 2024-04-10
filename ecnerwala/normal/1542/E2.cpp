#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, MOD; cin >> N >> MOD;

	auto add = [&](int& a, int b) -> void {
		a += b;
		a = (a >= MOD ? a - MOD : a);
	};
	auto sub = [&](int& a, int b) -> void {
		a -= b;
		a = (a < 0 ? a + MOD : a);
	};

	vector<int> dp; dp.reserve(N * (N-1) + 1);
	dp.push_back(0);
	vector<int> ndp; ndp.reserve(N * (N-1) + 1);

	int eq_ways = 1;
	for (int w = N; w >= 1; w--) {
		for (int z = 0; z < 2; z++) {
			ndp.resize(dp.size() + w - 1);
			int cur = 0;
			for (int i = 0; i < int(dp.size()); i++) {
				add(cur, dp[i]);
				if (i >= w) sub(cur, dp[i-w]);
				ndp[i] = cur;
			}
			std::swap(dp, ndp);
		}
		assert(int(dp.size()) & 1);
		int md = int(dp.size()) >> 1;
		for (int v = 1; v < w; v++) {
			add(dp[md - v], int(int64_t(eq_ways) * int64_t(w - v) % MOD));
		}
		eq_ways = int(int64_t(eq_ways) * int64_t(w) % MOD);
	}

	int ans = 0;
	assert(int(dp.size()) & 1);
	int md = int(dp.size()) >> 1;
	for (int i = md+1; i < int(dp.size()); i++) {
		add(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}

// We can write a permutation as a sequence [a_0, a_1, a_2, ...]
// where a_i is # of inversions (i, *)
// This is a bijection to all sequences with 
//   0 <= a_i < N-i
// and # of inversion is sum a_i
// and the lex comparison still holds.
//
// So, we can now do this as a DP