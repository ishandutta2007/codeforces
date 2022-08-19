#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;

	const int LEVELS = 9;
	std::array<std::vector<int>, LEVELS+1> B;

	B[0].resize(N);
	for (int i = 0; i < N; i++) {
		cin >> B[0][i];
	}
	auto update = [&](int l, int lo) -> void {
		assert(1 <= l && l <= LEVELS);
		assert(0 <= lo && lo < N);
		int md = min(N, lo + (1 << (l-1)));
		int hi = min(N, lo + (1 << l));
		// merge lo..md and md..hi
		const auto& prv = B[l-1];
		auto& cur = B[l];
		int cur_diff = 0;
		for (int i = lo, j = md, k = lo; k < hi; k++) {
			if (i == md || (j < hi && prv[j] - cur_diff <= prv[i])) {
				cur[k] = prv[j] - cur_diff;
				j++;
			} else {
				cur[k] = prv[i];
				i++;
				cur_diff++;
			}
		}
	};
	for (int l = 1; l <= LEVELS; l++) {
		B[l].resize(N);
		for (int lo = 0; lo < N; lo += (1 << l)) {
			update(l, lo);
		}
	}

	int Q; cin >> Q;
	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int i, x; cin >> i >> x; i--;
			B[0][i] = x;
			for (int l = 1; l <= LEVELS; l++) update(l, i >> l << l);
		} else if (op == 2) {
			int i; cin >> i; i--;
			int v = B[0][i];
			i++;
			while (i < N) {
				int l = min(LEVELS, __builtin_ctz(i));
				const auto& dp = B[l];
				auto lo = dp.begin() + i;
				auto hi = dp.begin() + min(N, i + (1 << l));
				v += int(upper_bound(lo, hi, v) - lo);
				i = min(N, i + (1 << l));
			}
			cout << N-v << '\n';
		} else assert(false);
	}

	return 0;
}