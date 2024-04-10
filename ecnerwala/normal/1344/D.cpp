#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N; i64 K; cin >> N >> K;
	vector<i64> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	auto solve_1 = [](i64 a, i64 d) -> i64 {
		// min b so that a - (3b^2 + 3b + 1) <= d
		// 3b^2 + 3b >= a - d - 1
		// b^2 + b >= ceil((a - d - 1) / 3);
		i64 cut = a - d - 1;
		cut = (cut + 2) / 3;
		if (cut <= 0) {
			return 0;
		}
		if (a * (a+1) < cut) return a; // upper bound

		assert(cut >= 1);
		i64 v = i64(sqrt(cut));
		while (v * (v+1) < cut) {
			v++;
		}
		while (v * (v-1) >= cut) {
			--v;
		}
		return min(v, a);
	};

	vector<i64> sol(N);
	auto try_cutoff = [&](i64 d) -> i64 {
		i64 tot = 0;
		for (int i = 0; i < N; i++) {
			sol[i] = solve_1(A[i], d);
			tot += sol[i];
		}
		return tot;
	};

	i64 mi = i64(1.1e9), ma = i64(-3.1e18);
	assert(try_cutoff(mi) == 0);
	assert(try_cutoff(ma) == accumulate(A.begin(), A.end(), i64(0)));
	while (mi - ma > 1) {
		i64 md = mi + (ma - mi) / 2;
		if (try_cutoff(md) >= K) {
			ma = md;
		} else {
			mi = md;
		}
	}
	try_cutoff(mi);
	vector<i64> sol_lo = sol; assert(accumulate(sol_lo.begin(), sol_lo.end(), i64(0)) < K);
	try_cutoff(ma);
	vector<i64> sol_hi = sol; assert(accumulate(sol_hi.begin(), sol_hi.end(), i64(0)) >= K);

	K -= accumulate(sol_lo.begin(), sol_lo.end(), i64(0));
	for (int i = 0; i < N; i++) {
		while (K && sol_hi[i] > sol_lo[i]) {
			sol_lo[i]++;
			K--;
		}
	}

	assert(K == 0);
	for (int i = 0; i < N; i++) {
		cout << sol_lo[i] << ' ';
	}
	cout << '\n';

	return 0;
}

// the step is a - (3b^2 + 3b + 1)