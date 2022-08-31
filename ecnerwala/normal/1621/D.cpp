#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int64_t ans = 0;
		int64_t corner = 1e18;
		for (int i = 0; i < 2*N; i++) {
			for (int j = 0; j < 2*N; j++) {
				int64_t v; cin >> v;
				if (i >= N && j >= N) {
					ans += v;
				} else if (i < N && j < N) {
					assert(v == 0);
				} else if ((i == 0 || i == N-1 || i == N || i == 2*N-1) && (j == 0 || j == N-1 || j == N || j == 2*N-1)) {
					corner = std::min(corner, v);
				}
			}
		}
		ans += corner;
		cout << ans << '\n';
	}

	return 0;
}