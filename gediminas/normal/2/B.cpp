#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
3
1 2 3
4 5 6
7 8 9
*/
/*input
3
10 10 0
10 10 10
10 10 10
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	int a[n][n][2] = {};

	string ans = "";
	int kie = 100000000;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;

			if (x == 0) {
				kie = 1;
				ans = string(i, 'D') + string(j, 'R') + string(n - 1 - i, 'D') + string(n - 1 - j, 'R');
				a[i][j][0] = 10000000;
				a[i][j][1] = 10000000;
				continue;
			}

			while (x % 2 == 0) {
				a[i][j][0]++;
				x /= 2;
			}

			while (x % 5 == 0) {
				a[i][j][1]++;
				x /= 5;
			}
		}
	}

	for (int t = 0; t < 2; ++t) {
		int dp[n][n][2] = {};
		char d[n][n] = {};

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 and j == 0) {
					dp[i][j][0] = 0;
					dp[i][j][1] = 0;
				}
				else if (i == 0) {
					dp[i][j][0] = dp[i][j - 1][0];
					dp[i][j][1] = dp[i][j - 1][1];
					d[i][j] = 'R';
				}
				else if (j == 0) {
					dp[i][j][0] = dp[i - 1][j][0];
					dp[i][j][1] = dp[i - 1][j][1];
					d[i][j] = 'D';
				}
				else {
					dp[i][j][0] = dp[i - 1][j][0];
					dp[i][j][1] = dp[i - 1][j][1];
					d[i][j] = 'D';

					if (dp[i][j][t] > dp[i][j - 1][t]) {
						dp[i][j][0] = dp[i][j - 1][0];
						dp[i][j][1] = dp[i][j - 1][1];
						d[i][j] = 'R';
					}
				}

				dp[i][j][0] += a[i][j][0];
				dp[i][j][1] += a[i][j][1];
			}
		}

		int x = n - 1, y = n - 1;
		string p = "";
		int a = dp[x][y][0], b = dp[x][y][1];

		while (x > 0 or y > 0) {
			p.push_back(d[x][y]);

			if (p.back() == 'R') {
				y--;
			}
			else {
				x--;
			}
		}

		debug(a, b, p);
		reverse(p.begin(), p.end());

		if (min(a, b) < kie) {
			kie = min(a, b);
			ans = p;
		}
	}

	cout << kie << "\n" << ans;
}