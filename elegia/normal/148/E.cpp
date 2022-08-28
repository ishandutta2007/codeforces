#include <cstdio>

#include <algorithm>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int a[N], w[N];
int dp[M];

int main() {
	scanf("%d%d", &n, &m);
	while (n--) {
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= k; ++i)
			scanf("%d", &a[i]);
		for (int l = 1; l <= k; ++l) {
			int sum = 0;
			for (int i = 1; i <= l; ++i)
				sum += a[i];
			w[l] = sum;
			for (int j = l; j; --j) {
				sum -= a[j];
				sum += a[k - (l - j + 1) + 1];
				w[l] = max(w[l], sum);
			}
		}
		for (int i = m; i >= 0; --i) {
			for (int j = 1; j <= i && j <= k; ++j)
				dp[i] = max(dp[i], dp[i - j] + w[j]);
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}