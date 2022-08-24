#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1e9;
	vector<vector<int>> p(n, vector<int>(m + 1, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			p[i][j + 1] = p[i][j] + (a[i][j] == '1');
		}
	}
	for (int l = 0; l < m; ++l) {
		for (int r = l + 3; r < m; ++r) {
			int mns[4] = {(int)1e9, (int)1e9, (int)1e9, (int)1e9};
			for (int i = 0; i < n; ++i) {
				int border = (r - l - 1) - (p[i][r] - p[i][l + 1]);
				ans = min(ans, border + mns[0]);
				int inner = (a[i][l] == '0') + (a[i][r] == '0') + (p[i][r] - p[i][l + 1]);
				for (int j = 0; j < 3; ++j) {
					mns[j] = min(mns[j], mns[j + 1]) + inner;
				}
				mns[3] = border;
			}
		}
	}
	cout << ans << "\n";
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