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


int n, m, c0, d0;
int a[11], b[11], c[11], d[11];
int dp[1002][11];



int main(){
	cin >> n >> m >> c0 >> d0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k <= a[j] / b[j]; k++) {
				if (i - c[j] * k >= 0) {
					dp[i][j] = max(dp[i][j], dp[i - c[j] * k][j - 1] + k * d[j]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, dp[i][m] + ((n - i) / c0) * d0);
	}
	cout << ans << endl;
    return 0;
}