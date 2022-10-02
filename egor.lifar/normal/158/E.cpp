#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n, k;
int d[4001], t[4001];
int dp[4002][4002];


int main() {
	cin >> n >> k;
	if (n == 0) {
		cout << 86400 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i] >> t[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = min((i > 0 && j > 0 ? dp[i - 1][j - 1]: 1000000000), max((i > 0 ? dp[i - 1][j]: 0), d[i]) + t[i]);
			if (j >= i + 1) {
				dp[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans = max(ans, d[i + 1] - dp[i][k]);
	}
	ans = max(ans, 86400 - dp[n - 1][k] + 1);
	cout << ans << endl;
 	return 0;
}