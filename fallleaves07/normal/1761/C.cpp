#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		ans[i].emplace_back(i);
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				ans[j + 1].emplace_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", (int)ans[i].size());
		for (auto v : ans[i]) {
			printf(" %d", v);
		}
		puts("");
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}