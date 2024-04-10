#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t A, B, C, D; cin >> A >> B >> C >> D;
		cout << [&]() -> int64_t {
			if (B * C < A) {
				return -1;
			}
			// We'll cast the spell at
			// 0, D, 2D, 3D, 4D
			// The time before the i-1th and the ith cast will deal
			// -A + B*sum_{j=0}^{i-1} min(D, max(C - j * D, 0))
			// Find max k so that (D * k) * B - A < 0
			// D * k * B < A
			int64_t k = (A-1) / D / B;
			assert(D * k <= C);
			// We will take time D*k as our end
			return A * (k+1) - B * D * (k * (k+1)) / 2;
		}() << '\n';
	}

	return 0;
}