#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t N; cin >> N;
		int v = __builtin_ctzll(2*N);
		int64_t a = int64_t(1) << v;
		int64_t b = (2*N) >> v;
		if (b == 1) {
			cout << -1 << '\n';
		} else {
			cout << std::min(a, b) << '\n';
		}
	}

	return 0;
}