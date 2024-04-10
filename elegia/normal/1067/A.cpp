#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010, P = 998244353;

int n;
int dp[N][210][2];
int a[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[n + 1] = 1;
	dp[0][1][0] = 1;
	for (int i = 1; i <= n + 1; ++i) {
		for (int x = 1; x <= 200; ++x) {
			if ((dp[i - 1][x][0] += dp[i - 1][x - 1][0]) >= P)
				dp[i - 1][x][0] -=P;
			if ((dp[i - 1][x][1] += dp[i - 1][x - 1][1]) >= P)
				dp[i - 1][x][1] -=P;
		}
		for (int x = 1; x <= 200; ++x) {
			dp[i][x][0] = ((dp[i - 1][x - 1][0]) + (dp[i - 1][x - 1][1])) % P;
			dp[i][x][1] = ((dp[i - 1][x][0] + P - dp[i - 1][x - 1][0]) % P + (dp[i - 1][200][1] + P - dp[i - 1][x - 1][1]) % P) % P;
		}
		if (a[i] != -1)
			for (int x = 1; x <= 200; ++x)
				if (x != a[i])
					dp[i][x][0] = dp[i][x][1] = 0;
	}
	printf("%d\n", dp[n + 1][1][1]);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}