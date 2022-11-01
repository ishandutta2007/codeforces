#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <vector <pair <int, bool>>> dp(n + 1, vector <pair <int, bool>>(5));
	for (int i = 0; i < 5; i++)
		dp[0][i] = { -1, 1 };
	for (int i = 1; i < n; i++)
		for (int cur = 0; cur < 5; cur++) {
			if (a[i - 1] < a[i])
				for (int prev = 0; prev < cur; prev++) 
					if (dp[i - 1][prev].second) dp[i][cur] = { prev, 1 };
			if (a[i - 1] == a[i])
				for (int prev = 0; prev < 5; prev++)
					if (prev != cur)
						if (dp[i - 1][prev].second) dp[i][cur] = { prev, 1 };
			if (a[i - 1] > a[i])
				for (int prev = cur + 1; prev < 5; prev++)
					if (dp[i - 1][prev].second) dp[i][cur] = { prev, 1 };
		}
	int pos = -1;
	for (int i = 0; i < 5; i++)
		if (dp[n - 1][i].second) {
			pos = i;
			break;
		}
	if (pos == -1) {
		cout << -1;
		return 0;
	}
	vector <int> ans;
	n--;
	while (n != -1) {
		ans.push_back(pos);
		pos = dp[n][pos].first;
		n--;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << " ";
	return 0;
}