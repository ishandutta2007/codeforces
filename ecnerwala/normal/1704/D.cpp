#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		int64_t min_tot = 0;
		int64_t max_tot = 0;
		int max_idx = 0;
		for (int i = 0; i < N; i++) {
			int64_t tot_loc = 0;
			for (int j = 0; j < M; j++) {
				int64_t c; cin >> c;
				tot_loc += j * c;
			}
			if (i == 0) {
				min_tot = max_tot = tot_loc;
				max_idx = 0;
			} else {
				if (tot_loc < min_tot) {
					min_tot = tot_loc;
				}
				if (tot_loc > max_tot) {
					max_tot = tot_loc;
					max_idx = i;
				}
			}
		}
		cout << max_idx+1 << ' ' << max_tot - min_tot << '\n';
	}

	return 0;
}