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

const int N = 210, L = 30; 

int n, k;
int dp[N][N * L];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif
	
	scanf("%d%d", &n, &k);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int rep = 0; rep < n; ++rep) {
		ll a;
		scanf("%lld", &a);
		int c2 = 0, c5 = 0;
		while (!(a & 1)) {
			a >>= 1;
			++c2;
		}
		while (a % 5 == 0) {
			a /= 5;
			++c5;
		}
		for (int i = k; i; --i)
			for (int j = n * L; j >= c5; --j)
				if (dp[i - 1][j - c5] != -1 && (dp[i][j] == -1 || dp[i][j] < dp[i - 1][j - c5] + c2))
					dp[i][j] = dp[i - 1][j - c5] + c2;
	}
	int ans = 0;
	for (int i = 0; i <= n * L; ++i)
		ans = max(ans, min(i, dp[k][i]));
	printf("%d\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}