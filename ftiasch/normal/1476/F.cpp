#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<int> p(n + 1);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
		}
		auto rbound = [&p](int i) { return i + p[i]; };
		vector<int> dp(n + 1), plan(n + 1, -1), sufmax;
		vector<pair<int, int>> c{{dp[0], 0}};
		for (int i = 1; i <= n; ++i) {
			dp[i] = dp[i - 1];
			if (p[i] == 0) {
				continue;
			}
			if (i <= dp[i - 1]) {
				dp[i] = max(dp[i], i + p[i]);
			}
			auto it = lower_bound(c.begin(), c.end(), make_pair(i - p[i] - 1, 0));
			if (it != c.end()) {
				int j = it->second;
				auto jt = lower_bound(sufmax.begin(), sufmax.end(), j + 1);
				int m = i - 1;
				if (jt != sufmax.end()) {
					m = max(m, rbound(*jt));
				}
				if (dp[i] < m) {
					dp[i] = m;
					plan[i] = j;
				}
			}
			if (c.back().first < dp[i]) {
				c.emplace_back(dp[i], i);
			}
			while (!sufmax.empty() && rbound(sufmax.back()) <= rbound(i)) {
				sufmax.pop_back();
			}
			sufmax.push_back(i);
		}
		if (dp[n] >= n) {
			puts("YES");
			vector<char> solution(n + 1, '\0');
			for (int i = n; i > 0;) {
				int j = plan[i];
				if (~j) {
					solution[--i] = 'L';
					while (j < i) {
						solution[--i] = 'R';
					}
				} else {
					solution[--i] = 'R';
				}
			}
			puts(solution.data());
		} else {
			puts("NO");
		}
	}
}