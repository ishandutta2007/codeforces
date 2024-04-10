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


#define INF 1000000000


int n;
int p[30001];
int b[30001];
int d;
int m = 410;
int dp[30001][900];



int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		b[p[i]]++;
	}
	int ans = 0;
	for (int i = 0; i <= 30000; i++) {
		for (int j = -m; j <= m; j++) {
			if (d + j > 0) {
				if (i == 0) {
					if (j == 0) {
						dp[i][j + m] = b[i]; 
					} else {
						dp[i][j + m] = -INF;
					}
					continue;
				}
				dp[i][j + m] = max((i - j - 1 - d >= 0 && j + 1 <= m ? dp[i - j - 1 - d][j + m + 1]: -INF), max((i - d >= j ? dp[i - j - d][j + m]: -INF), (i + 1 - d >= j && j + m - 1 >= 0 ? dp[i - j + 1 - d][j + m - 1]: -INF)));
				if (dp[i][j + m] != -INF) {
					dp[i][j + m] += b[i];
				}
				ans = max(ans, dp[i][j + m]);
			} else {
				dp[i][j + m] = -INF;
			}
		}
	}
	cout << ans << endl;
    return 0;
}