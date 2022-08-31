#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		auto should_take = [&](int i, int j) -> bool {
			if ((i^j)&1) {
				i = N-1-i;
			}
			if ((i+j) & 2) return false;
			if (i+j < N-1) {
				return (i & 1) == 0;
			} else {
				return ((N-1-i) & 1) == 0;
			}
		};
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int v; cin >> v;
				if (should_take(i, j)) ans ^= v;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}

// .#*#.#
// #.#.#*
// *#.#.#
// #.#*#.
// .#.#.#
// #*#.#*