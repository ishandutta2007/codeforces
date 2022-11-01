#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		bool tf = false;
		cin >> n >> m;
		vector <vector <char>> a(n);
		for (int i = 0; i < n; i++)
			a[i].resize(m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'A')
					tf = true;
			}
		if (!tf) {
			cout << "MORTAL" << endl;
			continue;
		}
		int ans = 4;
		for (int i = 0; i < n; i++)
			if (a[i][0] == 'A' || a[i][m - 1] == 'A')
				ans = 3;
		for (int j = 0; j < m; j++)
			if (a[0][j] == 'A' || a[n - 1][j] == 'A')
				ans = 3;
		if (a[0][0] == 'A' || a[n - 1][0] == 'A' || a[n - 1][m - 1] == 'A' || a[0][m - 1] == 'A')
			ans = 2;
		for (int i = 0; i < n; i++) {
			tf = true;
			for (int j = 0; j < m; j++)
				if (a[i][j] == 'P')
					tf = false;
			if (tf)
				ans = min(ans, 2);
			if (tf && (i == 0 || i == n - 1))
				ans = 1;
		}
		for (int j = 0; j < m; j++) {
			tf = true;
			for (int i = 0; i < n; i++)
				if (a[i][j] == 'P')
					tf = false;
			if (tf)
				ans = min(ans, 2);
			if (tf && (j == 0 || j == m - 1))
				ans = 1;
		}
		tf = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 'P')
					tf = false;
		if (tf)
			ans = 0;
		cout << ans << endl;
	}
	return 0;
}