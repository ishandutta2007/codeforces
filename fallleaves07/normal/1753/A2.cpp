#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), loc;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]) {
			loc.emplace_back(i);
		}
	}
	int m = loc.size();
	if (m % 2) {
		puts("-1");
		return;
	}
	vector<pair<int, int>> ans;
	if (m == 0) {
		for (int i = 0; i < n; i++) {
			ans.emplace_back(i, i);
		}
	} else {
		int lst = 0;
		for (int i = 0; i < m; i += 2) {
			for (int j = lst; j < loc[i]; j++) {
				ans.emplace_back(j, j);
			}
			if ((loc[i + 1] - loc[i]) % 2) {
				if (a[loc[i + 1]] == a[loc[i]]) {
					ans.emplace_back(loc[i], loc[i + 1]);
				} else {
					ans.emplace_back(loc[i], loc[i]);
					ans.emplace_back(loc[i] + 1, loc[i + 1]);
				}
			} else {
				if (a[loc[i + 1]] == a[loc[i]]) {
					ans.emplace_back(loc[i], loc[i]);
					ans.emplace_back(loc[i] + 1, loc[i + 1]);
				} else {
					ans.emplace_back(loc[i], loc[i + 1]);
				}
			}
			lst = loc[i + 1] + 1;
		}
		for (int i = lst; i < n; i++) {
			ans.emplace_back(i, i);
		}
	}
	printf("%ld\n", ans.size());
	for (auto [x, y] : ans) {
		printf("%d %d\n", x + 1, y + 1);
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