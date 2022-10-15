#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MODULO = (int)1e9 + 7;

int main() {
	int t, l, r; cin >> t >> l >> r;
	static int64_t dp[6000000];
	for (int i = 0; i <= r; i++) {
		dp[i] = 123456789012345678LL;
	}
	dp[1] = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = i+i, k = 2; j <= r; j += i, k++) {
			dp[j] = min(dp[j], dp[i] + (int64_t)i * k * (k-1) / 2);
		}
	}
	int64_t ans = 0, pow = 1;
	for (int i = l; i <= r; i++) {
		ans += pow * (dp[i] % MODULO);
		pow *= t;
		ans %= MODULO;
		pow %= MODULO;
	}
	cout << ans << endl;
	return 0;
}