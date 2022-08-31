#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <random>
#include <limits>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 5010;

int n;
int a[N];
int dp[N][N][2];

int dist(int a, int b) { return max(0, a - b + 1); }

int main() {
	scanf("%d", &n);
	if (n == 1) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	fill(**dp, *dp[n] + N * 2, 1 << 30);
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i][0][0] = 0;
		for (int j = 1; j <= (n + 1) / 2; ++j) {
			dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
			if (i != 1) {
				if (i != 2) {
					int cur = min(a[i - 1], a[i - 2] - 1);
					dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][1] + dist(cur, a[i]) + dist(a[i + 1], a[i]));
				} else
					dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][1] + dist(a[i - 1], a[i] + dist(a[i + 1], a[i])));
				dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][0] + dist(a[i - 1], a[i]) + dist(a[i + 1], a[i]));
			} else if (j == 1)
				dp[i][j][1] = dist(a[2], a[1]);
		}
	}
	for (int i = 1; i <= (n + 1) / 2; ++i)
		printf("%d\n", min(dp[n][i][0], dp[n][i][1]));
	return 0;
}