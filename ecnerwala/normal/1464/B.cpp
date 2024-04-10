#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	string S; cin >> S;
	int64_t X, Y; cin >> X >> Y;
	if (X > Y) {
		swap(X, Y);
		for (auto& c : S) {
			if (c == '0' || c == '1') c ^= 1;
			else if (c == '?') continue;
			else assert(false);
		}
	}
	assert(X <= Y);
	// Should be prefix of 0's and suffix of 1's
	int N = int(S.size());
	array<int, 2> tot{0,0};

	for (char c : S) if (c != '?') tot[c - '0']++;

	array<int, 2> cnt{0,0};
	int64_t cur_tot = 0;

	vector<array<int64_t, 2>> cost; cost.reserve(N);
	for (int i = 0; i < N; i++) {
		if (S[i] == '?') {
			cost.push_back({
				(Y * cnt[1] + X * (tot[1] - cnt[1])),
				(X * cnt[0] + Y * (tot[0] - cnt[0])),
			});
		} else {
			if (S[i] == '0') {
				cur_tot += Y * cnt[1];
			} else {
				cur_tot += X * cnt[0];
			}
			cnt[S[i] - '0']++;
		}
	}

	int64_t ans = 2e18;
	int M = int(cost.size());
	int64_t cnd = 0;
	for (int j = 0; j < M; j++) {
		cnd += cost[j][1];
	}
	for (int j = 0; j <= M; j++) {
		ans = min(ans, cur_tot + cnd + int64_t(j) * int64_t(M-j) * X);
		if (j < M) {
			cnd -= cost[j][1];
			cnd += cost[j][0];
		}
	}

	cout << ans << '\n';

	return 0;
}