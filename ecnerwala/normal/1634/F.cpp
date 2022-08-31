#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q, MOD; cin >> N >> Q >> MOD;

	// First, let A = A-B
	// we'll just maintain A[i] - A[i-1] - A[i-2]
	// (set A[-2] = A[-1] = 0)
	std::vector<int> cur(N);
	for (auto& v : cur) {
		int a; cin >> a;
		v = a;
	}
	for (auto& v : cur) {
		int b; cin >> b;
		v -= b;
		v = (v < 0) ? v + MOD : v;
	}

	for (int i = N-1; i >= 0; i--) {
		if (i >= 1) {
			cur[i] -= cur[i-1];
			cur[i] = (cur[i] < 0) ? cur[i] + MOD : cur[i];
			if (i >= 2) {
				cur[i] -= cur[i-2];
				cur[i] = (cur[i] < 0) ? cur[i] + MOD : cur[i];
			}
		}
	}

	std::vector<int> fibs(N+2);
	fibs[0] = MOD == 1 ? 0 : 1;
	fibs[1] = MOD == 1 ? 0 : 1;
	for (int i = 2; i < int(fibs.size()); i++) {
		fibs[i] = fibs[i-1] + fibs[i-2];
		fibs[i] = (fibs[i] >= MOD) ? fibs[i] - MOD : fibs[i];
	}

	int num_nonzero = 0;
	for (int i = 0; i < N; i++) {
		num_nonzero += cur[i] != 0;
	}

	while (Q--) {
		char c; cin >> c;
		int l, r; cin >> l >> r; l--;
		int w = (c == 'A') ? 1 : -1;

		num_nonzero -= cur[l] != 0;
		cur[l] += w;
		if (cur[l] < 0) cur[l] += MOD;
		if (cur[l] >= MOD) cur[l] -= MOD;
		num_nonzero += cur[l] != 0;
		if (r < N) {
			num_nonzero -= cur[r] != 0;
			cur[r] -= w * fibs[r-l];
			if (cur[r] < 0) cur[r] += MOD;
			if (cur[r] >= MOD) cur[r] -= MOD;
			num_nonzero += cur[r] != 0;
			if (r+1 < N) {
				num_nonzero -= cur[r+1] != 0;
				cur[r+1] -= w * fibs[r-l-1];
				if (cur[r+1] < 0) cur[r+1] += MOD;
				if (cur[r+1] >= MOD) cur[r+1] -= MOD;
				num_nonzero += cur[r+1] != 0;
			}
		}
		cout << (num_nonzero == 0 ? "YES" : "NO") << '\n';
	}

	return 0;
}