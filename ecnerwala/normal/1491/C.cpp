#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int64_t> S(N); for (auto& s : S) cin >> s;
		int64_t ans = 0;
		vector<int64_t> cur_in(N);
		for (int i = 0; i < N; i++) {
			if (cur_in[i] < S[i]-1) {
				ans += S[i]-1 - cur_in[i];
				cur_in[i] = S[i] - 1;
			}
			assert(cur_in[i] >= S[i]-1);
			if (i+1 < N) {
				cur_in[i+1] += cur_in[i] - (S[i] - 1);
			}
			for (int j = i+2; j < N && j-i <= S[i]; j++) {
				cur_in[j]++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}