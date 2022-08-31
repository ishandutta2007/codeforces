#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

const int K = 51, P = 110;

int dp[K][P], tmp[K][P];

int n, k, p;

int main() {
	scanf("%d%d%d", &n, &k, &p);
	fill(dp[0], dp[k] + p, -100000);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		a %= p;
		fill(tmp[0], tmp[k] + p, -100000);
		for (int j = 0; j < k; ++j) {
			int mex = -100000;
			for (int l = 0; l < p; ++l)
				mex = max(mex, dp[j][l] + l);
			tmp[j + 1][a] = max(tmp[j + 1][a], mex);
		}
		for (int j = 1; j <= k; ++j)
			for (int l = 0; l < p; ++l)
				tmp[j][(l + a) % p] = max(tmp[j][(l + a) % p], dp[j][l]);
		memcpy(dp, tmp, sizeof(dp));
	}
	int ans = -1000000;
	for (int i = 0; i < p; ++i)
		ans = max(ans, dp[k][i] + i);
	printf("%d\n", ans);
	return 0;
}