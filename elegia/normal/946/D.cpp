#include <cstdio>

#include <algorithm>
#include <limits>

using namespace std;

const int N = 510;

int n, m, k;
int hour[N], help[N];
int dp[N][N];
char s[N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	fill(dp[0] + 1, dp[0] + m + 1, (int)1e8);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		int cnt = 0;
		for (int j = 1; j <= m; ++j)
			if (s[j] == '1')
				hour[++cnt] = j;
		help[0] = hour[cnt] - hour[1] + 1;
		for (int j = 1; j <= min(cnt, k); ++j) {
			help[j] = 1e8;
			for (int k = cnt - j; k <= cnt; ++k)
				help[j] = min(help[j], hour[k] - hour[k - (cnt - j) + 1] + 1);
		}
		if (cnt <= k)
			help[cnt] = 0;
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j] + help[0];
			for (int l = 1; l <= min(j, cnt); ++l)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + help[l]);
		}
	}
	printf("%d\n", *min_element(dp[n], dp[n] + k + 1));
	return 0;
}