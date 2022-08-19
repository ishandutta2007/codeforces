#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	string S; cin >> S;

	int64_t ans = 0;

	vector<int> cnt(N+1);
	int64_t cur_tot = 0;
	int cur_ones = 0;

	for (char c : S) {
		if (c == '1') {
			cur_ones++;
			cur_tot += cnt[cur_ones-1];
			cnt[cur_ones] += cnt[cur_ones-1]; cnt[cur_ones-1] = 0;
			if (cur_ones > 1) {
				cur_tot += cur_ones-1;
				cnt[cur_ones-1]++;
			} else {
				assert(cur_ones == 1);
				cur_tot += cur_ones;
				cnt[cur_ones]++;
			}
		} else if (c == '0') {
			cur_ones = 0;

			cnt[0]++;
		} else assert(false);

		ans += cur_tot;
	}
	cout << ans << '\n';

	return 0;
}