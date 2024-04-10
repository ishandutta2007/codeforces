#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; int64_t K; cin >> N >> K;
		vector<int64_t> X(N); for (auto& x : X) cin >> x;

		int64_t g = 0;
		for (auto x : X) g = std::gcd(g, x - X[0]);
		if ((K - X[0]) % g != 0) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}
	}

	return 0;
}