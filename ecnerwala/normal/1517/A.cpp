#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int64_t N; cin >> N;
		if (N % 2050) {
			cout << -1 << '\n';
		} else {
			N /= 2050;
			int64_t res = 0;
			for (; N; N /= 10) res += N % 10;
			cout << res << '\n';
		}
	}

	return 0;
}