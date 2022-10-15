#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n), dp(n, INT_MAX);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	dp[n-1] = 0;
	for (int i = n-2; i >= 0; i--) {
		for (int j = i+1; j < n; j++) {
			if (abs(v[i] - v[j]) <= k) {
				dp[i] = min(dp[i], dp[j]);
			}
		}
		if (dp[i] != INT_MAX) {
			dp[i]++;
		}
	}
	if (dp[0] == INT_MAX) {
		dp[0] = -1;
	}
	cout << dp[0] << endl;
	return 0;
}