#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n;
	cin >> n;
	vector<vector<vector<int>>> a(4, vector<vector<int>>(n, vector<int>(n)));
	for (int it = 0; it < 4; ++it) {
		for (int i = 0; i < n; ++i) {
			char c;
			for (int j = 0; j < n; ++j) {
				cin >> c;
				a[it][i][j] = (c - '0');
			}
		}
		string _;
		getline(cin, _, '\n');
	}
	vector<int> p(4);
	iota(all(p), 0);
	int ans = LLONG_MAX;
	do {
		int ans_w = 0, ans_b = 0;
		for (int who = 0; who < 4; ++who) {
			int board = p[who];
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					int need_w = (i + j) % 2;
					if (who == 1 or who == 2) need_w ^= 1;
					int res = (a[board][i][j] != need_w);
					ans_w += res;
					ans_b += (res ^ 1);
				}
			}
		}
		ans = min(ans, min(ans_w, ans_b));
	} while(next_permutation(all(p)));
	cout << ans << "\n";
	return 0;
}