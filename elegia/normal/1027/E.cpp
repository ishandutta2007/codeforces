#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

typedef long long ll;

const int P = 998244353, N = 510;

int n, k;

int dp[N], cur[N], sum[N];

int main() {
	scanf("%d%d", &n, &k);
	--k;
	for (int i = 1; i <= n; ++i) {
		memset(cur, 0, sizeof(cur));
		cur[0] = sum[0] = 1;
		for (int j = 1; j <= n; ++j) {
			if (j >= i + 1)
				cur[j] = (sum[j - 1] - sum[j - i - 1] + P) % P;
			else
				cur[j] = sum[j - 1];
			sum[j] = (sum[j - 1] + cur[j]) % P;
		}
		dp[i] = cur[n];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = (ans + (dp[i] - dp[i - 1] + P) % P * (ll)dp[min(k / i, n)]) % P;
	printf("%d\n", ans * 2 % P);
	return 0;
}