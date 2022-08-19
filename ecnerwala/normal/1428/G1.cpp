#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int K; cin >> K;

	array<int64_t, 6> F; for (auto& a : F) cin >> a;

	const int64_t INF = 1e18;
	vector<int64_t> dp({0});
	for (int d = 5; d >= 0; d--) {
		vector<int64_t> ndp(dp.size() * 10, -INF);
		array<deque<pair<int64_t, int>>, 3> stk;

		for (int i = 0; i < int(ndp.size()); i++) {
			if (i % 10 == 0) {
				int64_t val = dp[i / 10] - (i / 3) * F[d];
				int z = i%3;
				while (!stk[z].empty() && val >= stk[z].back().first) {
					stk[z].pop_back();
				}
				stk[z].push_back({val, i});
			}
			ndp[i] = 0; // you can always do 0

			for (int z = 0; z < 3; z++) {
				while (!stk[z].empty() && i - stk[z].front().second > 9 * (K-1)) {
					stk[z].pop_front();
				}
				if (!stk[z].empty()) {
					assert(i - stk[z].front().second <= 9 * (K-1));
					int64_t cnd = stk[z].front().first + (stk[z].front().second / 3) * F[d];

					int diff = i - stk[z].front().second;
					assert(diff <= 9 * (K-1));
					cnd += diff / 3 * F[d];

					ndp[i] = max(ndp[i], cnd);
				}
			}

			for (int e = 1; e <= 9; e++) {
				int diff = 9 * (K-1) + e;
				if (diff <= i && (i - diff) % 10 == 0) {
					int64_t cnd = dp[(i - diff) / 10];
					cnd += (K-1) * 3 * F[d];
					if (e % 3 == 0) {
						cnd += e / 3 * F[d];
					}
					ndp[i] = max(ndp[i], cnd);
				}
			}
		}
		dp = std::move(ndp);
	}

	assert(int(dp.size()) == 999999 + 1);

	int Q; cin >> Q;
	while (Q--) {
		int N; cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}