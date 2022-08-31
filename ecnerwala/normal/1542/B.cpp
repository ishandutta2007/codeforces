#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, A, B; cin >> N >> A >> B;
		cout << ([&] () -> bool {
			if (A == 1) {
				return (N - 1) % B == 0;
			}
			for (int64_t v = 1; v <= N; v *= A) {
				if ((N - v) % B == 0) return true;
			}
			return false;
		}() ? "Yes" : "No") << '\n';
	}

	return 0;
}