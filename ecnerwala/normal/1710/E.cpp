#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	std::vector<int> A(N); for (auto& a : A) cin >> a;
	std::vector<int> B(M); for (auto& b : B) cin >> b;
	int A_init_val = A[0];
	int B_init_val = B[0];
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	int A_init = int(std::lower_bound(A.begin(), A.end(), A_init_val) - A.begin());
	int B_init = int(std::lower_bound(B.begin(), B.end(), B_init_val) - B.begin());

	auto alice_wins = [&](int v) -> bool {
		// can alice force sum <= v

		// We don't care about the actual value, just the offset from minimal
		int64_t cur_cut = 0;

		int x1 = 0, y1 = M;
		int x2 = N, y2 = 0;
		for (int z = 0; z < N+M; z++) {
			if (x1 < N && (y1 == 0 || A[x1] + B[y1-1] <= v)) {
				x1++;
			} else {
				y1--;
				cur_cut -= x1;
			}
			if (x2 > 0 && (y2 == M || A[x2-1] + B[y2] > v)) {
				x2--;
			} else {
				y2++;
				cur_cut += N - x2;
			}
			if (x1 + x2 == N) {
				assert(y1 + y2 == M);
				if (cur_cut < 0) {
					cur_cut = 0;
				}
				if (cur_cut == 0) {
					// now, check this location
					// is A_init, B_init within this cut
					if (A_init < x1 || B_init < y2) {
						return true;
					}
				}
			}
		}
		return false;
	};

	// Bob can force > mi
	int mi = -1;
	// Alice can force <= ma
	int ma = A_init_val + B_init_val;

	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (alice_wins(md)) {
			ma = md;
		} else {
			mi = md;
		}
	}

	cout << ma << '\n';

	return 0;
}