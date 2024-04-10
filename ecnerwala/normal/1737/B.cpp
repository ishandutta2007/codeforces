#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	auto floor_sqrt = [&](int64_t a) -> int64_t {
		int64_t mi = 0, ma = 2e9;
		assert(mi * mi <= a);
		assert(a < ma * ma);
		while (ma - mi > 1) {
			int64_t md = mi + (ma - mi) / 2;
			if (md * md <= a) mi = md;
			else ma = md;
		}
		return mi;
	};

	auto get_cnt = [&](int64_t a) -> int64_t {
		int64_t rt = floor_sqrt(a);
		assert(rt * rt <= a);
		if (rt * (rt + 2) <= a) {
			return 3 * rt;
		} else if (rt * (rt + 1) <= a) {
			return 3 * rt - 1;
		} else if (rt * rt <= a) {
			return 3 * rt - 2;
		} else assert(false);
	};

	int T; cin >> T;
	while (T--) {
		int64_t L, R; cin >> L >> R;
		cout << get_cnt(R) - get_cnt(L-1) << '\n';
	}

	return 0;
}