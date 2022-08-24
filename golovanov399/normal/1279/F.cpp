#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int main() {
	cin.sync_with_stdio(false);
	int n = nxt(), k = nxt(), l = nxt();
	string s;
	cin >> s;

	if (1ll * l * k >= n) {
		cout << "0\n";
		return 0;
	}

	vector<int> p(n + 1);
	for (int i = 0; i < n; ++i) {
		p[i + 1] = p[i] + !!isupper(s[i]);
	}

	auto check = [&](long double penalty) -> pair<long double, int> {
		vector<pair<long double, int>> dp(n + 1);
		for (int i = 1; i <= n; ++i) {
			dp[i] = dp[i - 1];
			dp[i].first += p[i] - p[i - 1];
			int j = max(0, i - l);
			dp[i] = min(dp[i], {dp[j].first + penalty, dp[j].second + 1});
		}
		return dp[n];
	};

	int ans = n;

	for ([[maybe_unused]] char parenthesis : ")") {
		long double l = -2 * n, r = 2 * n;
		for (int it = 0; it < 50; ++it) {
			long double m = (l + r) / 2;
			auto re = check(m);
			if (re.second >= k) {
				l = m;
			} else {
				r = m;
			}
		}

		auto re = check(r);
		ans = min<int>(ans, roundl(re.first - r * k));

		for (int i = 0; i <= n; ++i) {
			p[i] = i - p[i];
		}
	}

	cout << ans << "\n";
	return 0;
}