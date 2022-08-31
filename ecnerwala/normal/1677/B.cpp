#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		string S; cin >> S;
		std::vector<int> pref(N*M+1);
		for (int i = 0; i < N*M; i++) {
			pref[i+1] = pref[i] + (S[i] - '0');
		}
		std::vector<int> row_cnt(N*M+1);
		for (int i = 1; i <= N*M; i++) {
			if (i < M) row_cnt[i] = (pref[i] > 0);
			else row_cnt[i] = row_cnt[i-M] + (pref[i] - pref[i-M] > 0);
		}
		std::vector<int> col_cnt(N*M+1);
		std::vector<bool> is_good(M);
		int cur = 0;
		for (int i = 0; i < N*M; i++) {
			if (S[i] == '1' && !is_good[i%M]) {
				is_good[i%M] = true, cur++;
			}
			col_cnt[i+1] = cur;
		}
		for (int i = 1; i <= N*M; i++) {
			cout << row_cnt[i] + col_cnt[i] << " \n"[i==N*M];
		}
	}

	return 0;
}