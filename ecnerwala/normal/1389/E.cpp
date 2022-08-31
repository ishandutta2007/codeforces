#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t M, D, W; cin >> M >> D >> W;
		M = min(M, D);
		W /= gcd(W, D-1);
		cout << W * (M / W) * (M/W - 1) / 2 + (M%W) * (M/W) << '\n';
	}

	return 0;
}