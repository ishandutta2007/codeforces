#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		string S; cin >> S;
		auto ans = [&]() -> int {
			int cur_score = 0;
			vector<int> runs(N+1);
			int last_win = -1;
			for (int i = 0; i < N; i++) {
				if (S[i] == 'W') {
					if (last_win != -1 && last_win == i-1) {
						cur_score += 2;
					} else {
						cur_score += 1;
					}

					if (last_win != -1 && last_win != i-1) {
						runs[i - last_win - 1]++;
					}
					last_win = i;
				}
			}

			if (last_win == -1) {
				return max(0, 2*K-1);
			}

			cur_score += 2 * K;
			int rem = K;
			for (int l = 1; l <= N; l++) {
				while (rem >= l && runs[l]) {
					runs[l]--;
					rem -= l;
					cur_score++;
				}
			}

			return min(cur_score, 2 * N - 1);
		}();
		cout << ans << '\n';
	}

	return 0;
}