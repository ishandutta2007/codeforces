#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	auto wins = [&](int n) {
		if (n == 1) return false;
		if (n == 2) return true;
		if ((n & (n-1)) == 0) return false;
		if (n % 4 == 2) {
			n /= 2;
			for (int v = 3; v * v <= n; v++) {
				if (n % v == 0) return true;
			}
			// 2 * prime
			return false;
		}

		return true;
	};
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		cout << (wins(N) ? "Ashishgup" : "FastestFinger") << '\n';
	}

	return 0;
}