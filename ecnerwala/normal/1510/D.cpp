#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, D; cin >> N >> D;
	vector<int> A(N);
	array<pair<int64_t, vector<int>>, 10> dp; dp.fill({-1, {}});
	dp[1] = {1, {}};
	vector<bool> ans(N, true);
	for (int i = 0; i < N; i++) {
		array<pair<int64_t, vector<int>>, 10> ndp; ndp.fill({-1, {}});
		int a; cin >> a;
		A[i] = a;
		if (D % std::gcd(a, 10) != 0) {
			ans[i] = false;
			continue;
		}
		for (int d = 0; d < 10; d++) {
			if (dp[d].first == -1) continue;
			auto setmin = [&](auto& loc, const auto& cnd) {
				if (loc.first == -1 || std::make_pair(cnd.first, cnd.second.size()) < std::make_pair(loc.first, loc.second.size())) {
					loc = cnd;
				}
			};
			setmin(ndp[d * a % 10], dp[d]);
			dp[d].first *= a;
			dp[d].second.push_back(i);
			if (dp[d].second.size() > 4) continue;
			setmin(ndp[d], dp[d]);
		}
		dp = std::move(ndp);
	}

	if (dp[D].first == -1) {
		cout << -1 << '\n';
		exit(0);
	}
	for (int a : dp[D].second) ans[a] = false;
	int cnt = std::accumulate(ans.begin(), ans.end(), 0);
	if (cnt == 0) {
		cout << -1 << '\n';
		exit(0);
	}
	cout << cnt << '\n';
	for (int i = 0; i < N; i++) {
		if (ans[i]) {
			cout << A[i] << " \n"[!--cnt];
		}
	}

	return 0;
}