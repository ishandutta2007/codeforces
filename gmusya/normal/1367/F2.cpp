#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		map <int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]] = 1;
		}
		{
			int cnt = 0;
			for (auto &now : m)
				now.second = cnt++;
		}
		for (int i = 0; i < n; i++)
			a[i] = m[a[i]];
		int k = m.size();
		vector <vector <int>> p(k);
		for (int i = 0; i < n; i++)
			p[a[i]].push_back(i);
		vector <int> cnt(k);
		for (int i = 0; i < n; i++)
			cnt[a[i]]++;
		vector <int> l(k), r(k);
		for (int i = 0; i < k; i++) {
			l[i] = p[i][0];
			r[i] = p[i][p[i].size() - 1];
		}
		vector <pair <int, int>> dp(k);
		dp[0] = { cnt[0], 1 };
		for (int i = 1; i < k; i++) {
			if (l[i] > r[i - 1])
				dp[i] = { dp[i - 1].first + cnt[i], dp[i - 1].second + 1 };
			else dp[i] = { cnt[i], 1 };
		}
		int answer = 0;
		for (int i = 0; i < k; i++) {
			int ans = dp[i].first;
			int L = i - dp[i].second, R = i + 1;
			if (L >= 0) ans += lower_bound(p[L].begin(), p[L].end(), l[L + 1]) - p[L].begin();
			if (R < k) ans += cnt[R] - (lower_bound(p[R].begin(), p[R].end(), r[R - 1]) - p[R].begin());
			answer = max(answer, ans);
		}
		for (int i = 0; i < k - 1; i++) {
			int it0 = 0, it1 = 0;
			while (it0 < cnt[i] && it1 < cnt[i + 1]) {
				if (p[i][it0] < p[i + 1][it1]) it0++;
				else it1++;
				answer = max(answer, it0 + (cnt[i + 1] - it1));
			}
		}
		cout << n - answer << '\n';
	}
	return 0;
}

/*
12
4 3 2 2 2 2 3 3 3 3 2 1
*/