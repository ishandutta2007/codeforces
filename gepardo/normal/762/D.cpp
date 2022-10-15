#include <iostream>
#include <cstdint>
#include <sstream>
#include <queue>

using namespace std;

const int64_t infinity = 123456789012345678LL;

int64_t a[100000][3];
int64_t dp[100000][3];

#define max __max__

template<typename T>
inline T max(T a, T b) {
	return (a > b) ? a : b;
}

template<typename T, typename... Args>
inline T max(T a, Args... b) {
	return max(a, max(b...));
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[j][i];
		}
	}
	dp[0][0] = 0;
	dp[0][1] = -infinity;
	dp[0][2] = -infinity;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(
			dp[i-1][0] + a[i][0],
			dp[i-1][1] + a[i][0] + a[i][1],
			dp[i-1][2] + a[i][0] + a[i][1] + a[i][2]
		);
		dp[i][1] = max(
			dp[i-1][0] + a[i][0] + a[i][1],
			dp[i-1][1] + a[i][1],
			dp[i-1][2] + a[i][1] + a[i][2]
		);
		dp[i][2] = max(
			dp[i-1][0] + a[i][0] + a[i][1] + a[i][2],
			dp[i-1][1] + a[i][1] + a[i][2],
			dp[i-1][2] + a[i][2]
		);
		if (i > 1) {
			int64_t sum1 = a[i-1][0] + a[i-1][1] + a[i-1][2];
			int64_t sum2 = a[i][0] + a[i][1] + a[i][2];
			int64_t sum = sum1 + sum2;
			dp[i][0] = max(
				dp[i][0],
				dp[i-2][2] + sum
			);
			dp[i][2] = max(
				dp[i][2],
				dp[i-2][0] + sum
			);
		}
	}
	cout << dp[n][2] << endl;
	return 0;
}