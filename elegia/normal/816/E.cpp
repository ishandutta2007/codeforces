#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;

const int N = 5010;

int n, b;

int c[N], d[N], prt[N], sz[N];
ll tmp[N][2];
ll dp[N][N][2];

int main() {
	scanf("%d%d", &n, &b);
	fill(**dp, **dp + N * N * 2, (ll)b + 1);
	scanf("%d%d", &c[1], &d[1]);
	for (int i = 2; i <= n; ++i)
		scanf("%d%d%d", &c[i], &d[i], &prt[i]);
	fill(sz + 1, sz + n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		dp[i][0][0] = 0;
		dp[i][1][0] = c[i];
		dp[i][0][1] = b + 1;
		dp[i][1][1] = c[i] - d[i];
	}
	for (int i = n; i >= 2; --i) {
		int p = prt[i];
		copy(*dp[p], *dp[p] + N * 2, *tmp);
		for (int j = 0; j <= sz[p]; ++j) {
			for (int k = 0; k <= sz[i]; ++k) {
				tmp[j + k][0] = min(tmp[j + k][0], dp[p][j][0] + dp[i][k][0]);
				tmp[j + k][1] = min(tmp[j + k][1], dp[p][j][1] + min(dp[i][k][0], dp[i][k][1]));
			}
		}
		sz[p] += sz[i];
		copy(*tmp, *tmp + N * 2, *dp[p]);
	}
	for (int j = n; j; --j) {
		if (dp[1][j][0] <= b || dp[1][j][1] <= b) {
			printf("%d\n", j);
			return 0;
		}
	}
	puts("0");
	return 0;
}