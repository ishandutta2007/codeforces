#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	static int counts[5001] = {};
	static bool marked[5001] = {};
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		counts[v[i]]++;
	}
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = (i == 0) ? 0 : dp[i-1];
		int curSum = 0;
		int curXor = 0;
		for (int j = i; j >= 0; j--) {
			if (!marked[v[j]]) {
				curSum += counts[v[j]];
				curXor ^= v[j];
				marked[v[j]] = true;
			}
			if (curSum == i - j + 1) {
				int val = (j == 0) ? 0 : dp[j-1];
				dp[i] = max(dp[i], val + curXor);
			}
		}
		for (int j = 0; j <= i; j++) {
			marked[v[j]] = false;
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}