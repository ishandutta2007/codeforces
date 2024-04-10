#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;



int n, m, k;
int dp[1001][1001][11];
int lenlink[1001][1001];
int ans = 0;


int main() {
	cin >> n >> m >> k;
	string s, t;
	cin >> s >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] != t[j - 1]) {
				lenlink[i][j] = 0;
			} else {
				lenlink[i][j] = lenlink[i - 1][j - 1] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int g = 1; g <= k; g++) {
				dp[i][j][g] = dp[i - 1][j][g];
				dp[i][j][g] = max(dp[i][j][g], dp[i][j - 1][g]);
				dp[i][j][g] = max(dp[i][j][g], dp[i - lenlink[i][j]][j - lenlink[i][j]][g - 1] + lenlink[i][j]);
				ans = max(ans, dp[i][j][g]);
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}