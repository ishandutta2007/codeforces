#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

pair<int, int> can[2000];

void solve() {
	fill(can, can + 2000, pair{-1, -1});
	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j + 1 < m; ++j) {
			can[stoi(s.substr(j, 2))] = {i, j};
		}
		for (int j = 0; j + 2 < m; ++j) {
			can[1000 + stoi(s.substr(j, 3))] = {i, j};
		}
	}
	string s;
	cin >> s;
	vector<int> dp(m + 1, -1);
	vector<pair<int, int>> which(m + 1);
	dp[0] = 0;
	for (int i = 2; i <= m; ++i) {
		if (~dp[i - 2] && ~can[stoi(s.substr(i - 2, 2))].first) {
			dp[i] = i - 2;
			which[i] = can[stoi(s.substr(i - 2, 2))];
		} else if (i >= 3 && ~dp[i - 3] && ~can[1000 + stoi(s.substr(i - 3, 3))].first) {
			dp[i] = i - 3;
			which[i] = can[1000 + stoi(s.substr(i - 3, 3))];
		}
	}
	if (dp[m] == -1) {
		cout << "-1\n";
		return;
	}
	vector<vector<int>> ans;
	for (int i = m; i; i = dp[i]) {
		ans.push_back({which[i].second, which[i].second + i - dp[i], which[i].first});
	}
	reverse(all(ans));
	cout << ans.size() << "\n";
	for (auto v : ans) {
		cout << v[0] + 1 << " " << v[1] << " " << v[2] + 1 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}