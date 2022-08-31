#include <bits/stdc++.h>

int64_t solve(int64_t X, int64_t Y) {
	assert(X % 2 == 0);
	assert(Y % 2 == 0);
	if (X > Y) return X + Y;
	return Y - (Y%X/2);
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t X, Y; cin >> X >> Y;
		int64_t N = solve(X, Y);
		assert(N % X == Y % N);
		cout << N << '\n';
	}

	return 0;
}