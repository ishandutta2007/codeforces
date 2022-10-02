#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>


using namespace std;


const int MaxN = 2100;
const long long MOD = 1000000007;
int n, k;
int sl[MaxN];
long long ps[MaxN];
long long dp[MaxN][MaxN][2];


int main() {
	cin >> n >> k; 
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		sl[i] = (int)ch - 'a';
	}
	for (int i = 0; i < MaxN; i++) {
		ps[i] = 0;
		for (int j = 0; j < MaxN; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][0][0] = 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= k; j++) {
			dp[i][j][0] = (dp[i][j][0] + ps[j]) % MOD;
		}
		int cval = i + 1;
		while (cval < n && (cval - i - 1) * (n - cval) <= k) {
			int sum = (cval - i - 1) * (n - cval);
			for (int j = 0; j <= k - sum; j++)
				dp[i][j + sum][0] = (dp[i][j + sum][0] + dp[cval][j][1]) % MOD;
			
			cval++;
		}
		if (cval < n) {
			cval = n - 1;
			while (cval > i && (cval - i - 1) * (n - cval) <= k) {
				int sum = (cval - i - 1) * (n - cval);
				for (int j = 0; j <= k - sum; j++) {
					dp[i][j + sum][0] = (dp[i][j + sum][0] + dp[cval][j][1]) % MOD;
				}
				cval--;
			}
		}
		for (int j = 0; j <= k + i - n; j++) {
			dp[i][j + n - i][1] = (dp[i][j + n - i][1] + dp[i][j][0]) % MOD;
		}
		for (int j = 0; j <= k; j++) {
			dp[i][j][0] = (dp[i][j][0] * sl[i]) % MOD;
			dp[i][j][1] = (dp[i][j][1] * (25 - sl[i])) % MOD;
			ps[j] += dp[i][j][0];
		}
	}
	long long ans = 0;
	if (k == 0) {
		ans++;
	}
	for (int i = 0; i < n; i++) {
		ans = (ans + dp[i][k][0]) % MOD;
		if (k - (i * (n - i)) >= 0) {
			ans = (ans + dp[i][k - (i * (n - i))][1]) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}