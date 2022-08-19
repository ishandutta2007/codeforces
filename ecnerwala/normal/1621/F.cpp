#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; int64_t A, B, C; cin >> N >> A >> B >> C;
		string S; cin >> S;
		int cnt0 = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == '0') {
				cnt0++;
			}
		}
		int cnt00 = 0;
		for (int i = 0; i+1 < N; i++) {
			if (S[i] == '0' && S[i+1] == '0') {
				cnt00++;
			}
		}

		int tot_A = cnt00;
		int tot_C = cnt0 - tot_A;

		std::vector<int> cost11; cost11.reserve(N);
		for (int i = 0; i < N; i++) {
			if (S[i] == '1') {
				int j = i+1;
				while (j < N && S[j] != '1') j++;
				if (j < N) {
					cost11.push_back(j - i - 1);
				}
			}
		}
		std::sort(cost11.begin(), cost11.end());

		int64_t ans = 0;

		for (int start1 = 0; start1 < 2; start1++) {
			int cur_A = 0;
			int cur_C = 0;
			for (int num11 = start1; num11 <= int(cost11.size()); num11++) {
				if (num11) {
					if (cost11[num11-1]) {
						cur_A += cost11[num11-1]-1;
						cur_C++;
					} else {
						// no additional cost
					}
				}
				if (cur_A + cur_C + start1 > num11) break;
				for (int num_ops : {num11 - start1, num11 - start1 + 1}) {
					if (num_ops < cur_A + cur_C) continue;
					if (num_ops > tot_A + tot_C) continue;
					num_ops -= (cur_A + cur_C);
					int64_t cnd = num11 * B + cur_A * A - cur_C * C;
					int v = std::min(num_ops, tot_A - cur_A);
					cnd += v * A - (num_ops - v) * C;
					ans = std::max(ans, cnd);
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}