#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


int n;
int c[100001];
long long dp[100001][2];
string s[100001], s1[100001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1000000000000000000LL;
		dp[i][1] = 1000000000000000000LL;
		cin >> s[i];
		s1[i] = s[i];
		reverse(s1[i].begin(), s1[i].end());
		if (s[i] > s[i - 1] || s[i] == s[i - 1]) {
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		}
		if (s[i] > s1[i - 1] || s[i] == s1[i - 1]) {
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		}
		if (s1[i] > s[i - 1] || s1[i] == s[i - 1]) {
			dp[i][1] = min(dp[i][1], c[i] + dp[i - 1][0]);
		}
		if (s1[i] > s1[i - 1] || s1[i] == s1[i - 1]) {
			dp[i][1] = min(dp[i][1], c[i] + dp[i - 1][1]);
		}
	}
	long long ans = min(dp[n][0], dp[n][1]);
	if (ans == 1000000000000000000LL) {
		ans = -1;
	}
	cout << ans << endl;
    return 0;
}