#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;

		int64_t INF = 1e18;

		int64_t lo = INF, hi = -INF, both_cost = INF, lo_cost = INF, hi_cost = INF;

		for (int i = 0; i < N; i++) {
			int64_t l, r, cost; cin >> l >> r >> cost;
			if (l < lo) {
				lo = l;
				lo_cost = both_cost = INF;
			}
			if (r > hi) {
				hi = r;
				hi_cost = both_cost = INF;
			}
			if (l == lo) {
				lo_cost = std::min(lo_cost, cost);
			}
			if (r == hi) {
				hi_cost = std::min(hi_cost, cost);
			}
			if (l == lo && r == hi) {
				both_cost = std::min(both_cost, cost);
			}
			cout << std::min(both_cost, lo_cost + hi_cost) << '\n';
		}
	}

	return 0;
}