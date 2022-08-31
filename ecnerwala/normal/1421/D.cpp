#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t X, Y; cin >> X >> Y;
		array<int64_t, 6> C; for (auto& c : C) cin >> c;
		// Y * C1 + X * C5
		int64_t ans =
			(Y >= 0 ? C[1] * Y : C[4] * -Y)
			+ (X >= 0 ? C[5] * X : C[2] * -X);
		// (X-Y) * C5 + Y * C0
		ans = min(ans,
			((X-Y) >= 0 ? C[5] * (X-Y) : C[2] * -(X-Y))
			+ (Y >= 0 ? C[0] * Y : C[3] * -Y)
		);
		// X * C0 + (X-Y) * C4
		ans = min(ans,
			((X-Y) >= 0 ? C[4] * (X-Y) : C[1] * -(X-Y))
			+ (X >= 0 ? C[0] * X : C[3] * -X)
		);
		cout << ans << '\n';
	}

	return 0;
}