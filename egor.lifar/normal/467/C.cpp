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
#include <assert.h>


using namespace std;


long long n, m, k;
long long a[5000];
long long d[5000];
long long dp[5000][5001];


int main() {
	cin >> n >> m >> k;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = (i > 0 ? d[i - 1]: 0) + a[i];
	}
	for (int i = 0; i < 5000; i++) {
		for (long long j = 1; j <= k; j++) {
			if (m * j > i + 1) {
				dp[i][j] = -1;
				continue;
			}
			dp[i][j] = (i > 0 ? dp[i - 1][j]: -1);
			long long s = -1;
			if (i + 1 >= m) {
				s = (i - m >= 0 ? dp[i - m][j - 1]: 0) + d[i] - (i - m >= 0 ? d[i - m]: 0);
			}
			dp[i][j] = max(dp[i][j], s);
		}
	}
	long long ans = 0;
	for (int i = 0; i < 5000; i++) {
		ans = max(ans, dp[i][k]);
	}
	cout << ans << endl;
    return 0;
}