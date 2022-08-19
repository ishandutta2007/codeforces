#include <bits/stdc++.h>

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }
template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);


	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		//cerr << "Start test" << ' ' << N << ' ' << M << '\n';

		std::vector<int> A(N);
		for (auto& a : A) cin >> a;

		std::vector<int> max_right(N);
		std::iota(max_right.begin(), max_right.end(), 0);
		for (int j = 0; j < M; j++) {
			int l, r; cin >> l >> r; l--, r--;
			setmax(max_right[l], r);
		}
		for (int i = 1; i < N; i++) {
			setmax(max_right[i], max_right[i - 1]);
		}

		int min_hi = -1;
		int max_lo = N;
		std::vector<int> constraints(N, -1);

		std::map<int, std::vector<int>> idx;
		for (int i = N-1; i >= 0; i--) {
			auto& it = idx[A[i]];
			int mi = -1, ma = int(it.size());
			while (ma - mi > 1) {
				int md = mi + (ma - mi) / 2;
				if (it[md] <= max_right[i]) ma = md;
				else mi = md;
			}
			// ma..int(it.size());
			if (ma < int(it.size())) {
				setmax(min_hi, i);
				setmin(max_lo, it.back());
				constraints[i] = it[ma];
			}
			it.push_back(i);
		}

		if (min_hi == -1) {
			cout << 0 << '\n';
			continue;
		}

		int ans = min_hi + 1;
		for (int l = 0; l <= max_lo; l++) {
			setmin(ans, std::max(min_hi - l + 1, 0));
			if (l < N && constraints[l] != -1) {
				setmax(min_hi, constraints[l]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}