#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == '*') a[i][j] = -1;
			else if (c == '.') a[i][j] = 0;
			else a[i][j] = c - '0';
		}
	}
	bool ok = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] < 0) continue;
			int cnt = 0;
			for (int dx = -1; dx <= 1; ++dx) {
				for (int dy = -1; dy <= 1; ++dy) {
					if (!dx && !dy or i + dx >= n or i + dx < 0 or j + dy >= m or j + dy < 0) continue;
					cnt += a[i + dx][j + dy] < 0;
				}
			}
			ok &= cnt == a[i][j];
		}
	}
	cout << (ok ? "YES" : "NO") << '\n';
	return 0;	
}