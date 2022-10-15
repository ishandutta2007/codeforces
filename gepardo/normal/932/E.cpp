#include <iostream>

using namespace std;

int module = (int)1e9 + 7;

inline int binPow(int64_t a, int n) {
	int64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= module;
		}
		a *= a;
		a %= module;
		n >>= 1;
	}
	return res;
}

int main() {
	int n, k; cin >> n >> k;
	
	static int dp[5001][5001] = {};
	
	dp[0][0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			int64_t add1 = ((int64_t)dp[i][j] * j) % module;
			int64_t add2 = ((int64_t)dp[i][j] * (n - j + module)) % module;
			dp[i+1][j] += add1;
			dp[i+1][j] %= module;
			dp[i+1][j+1] += add2;
			dp[i+1][j+1] %= module;
		}
	}
	
	int r2 = (module + 1) / 2;
	int64_t ip = binPow(2, n);
	
	int64_t ans = 0;
	for (int i = 0; i <= k; i++) {
		int64_t add = (dp[k][i] * ip) % module;
		ans += add;
		ans %= module;
		ip *= r2;
		ip %= module;
	}
	
	cout << ans << endl;
	return 0;
}