#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		bool ok = 1;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ok &= a[i][j] <= 4, ++j) cin >> a[i][j];
		if (!ok || a[0][0] > 2 || a[0][m - 1] > 2 || a[n - 1][0] > 2 || a[n - 1][m - 1] > 2) {
			cout  << "NO\n";
			continue;
		}
		for (int i = 0;i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 || i == n -1 || j == 0 || j == m - 1) {
					ok &= (a[i][j] <= 3);
					a[i][j] = 3;
				} else a[i][j] = 4;
			}
		}
		a[0][m - 1] = 2;
		a[0][0] = 2;
		a[n - 1][m - 1] = 2;
		a[n - 1][0] = 2;
		if (!ok) cout << "NO\n";
		else {
			cout << "YES\n";
			for (auto el1 : a) {
				for (auto el2 : el1) cout << el2 << ' ';
				cout << '\n';
			}		                                 
		}
	}
}