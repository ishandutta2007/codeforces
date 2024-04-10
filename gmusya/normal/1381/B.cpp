#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n + n);
		for (int i = 0; i < n + n; i++)
			cin >> a[i];
		vector <int> w;
		int val = -10;
		int cnt = 0;
		for (int i = 0; i < n + n; i++) {
			if (val < a[i]) {
				w.push_back(cnt);
				cnt = 0;
				val = a[i];
			}
			cnt++;
		}
		w.push_back(cnt);
		int m = w.size();
		vector <vector <bool>> dp(m + 1, vector <bool>(n + 1));
		dp[0][0] = true;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j - w[i - 1] >= 0 && dp[i - 1][j - w[i - 1]]) dp[i][j] = true;
			}
		}
		if (dp[m][n]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}