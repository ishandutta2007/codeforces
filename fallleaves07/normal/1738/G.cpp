#include<bits/stdc++.h>
using namespace std;
using LL = long long;

bool solve() {
	int n, k;
	cin >> n >> k;
	vector<string> s(n);
	vector mp(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mp[i + 1][j + 1] = s[i][j] - '0';
		}
	}
	vector ans(n + 1, vector<int>(n + 1, 0));
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j < i; j++) {
			ans[n - k + i][j] = 1;
			ans[j][n - k + i] = 1;
		}
	}
	vector<int> loc;
	for (int i = 1; i <= n; i++) {
		if (i < k) {
			loc.push_back(n - k + i + 1);
		}
		vector<int> nxt = loc;
		for (int j = 1, d = 0; j <= n; j++) {
			if (mp[i][j] == 0 && ans[i][j] != 1) {
				while (d < (int)loc.size() && loc[d] < j) {
					++d;
				}
				if (d >= (int)loc.size()) {
					return false;
				}
				nxt[d] = min(nxt[d], j);
			}
		}
		if (n - i + 1 < k) {
			nxt[0] = 0;
		}
		for (int d = 0; d < (int)loc.size(); d++) {
			for (int j = nxt[d]; j <= loc[d]; j++) {
				ans[i][j] = 1;
			}
		}
		loc.clear();
		for (auto v : nxt) {
			if (v) {
				loc.push_back(v);
			}
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++, puts("")) {
		for (int j = 1; j <= n; j++) {
			printf("%d", ans[i][j]);
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		if (!solve()) {
			puts("NO");
		}
	}
    return 0;
}