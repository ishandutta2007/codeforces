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

int n;
ll dp[42][3][3];
int t[3][3];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d", &t[i][j]);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k) {
				if (j == k)
					continue;
				int ano = 0;
				while (ano == j || ano == k)
					++ano;
				dp[i][j][k] = min(dp[i - 1][j][ano] + dp[i - 1][ano][k] + t[j][k],
				                  dp[i - 1][j][k] * 2 + t[j][ano] + dp[i - 1][k][j] + t[ano][k]);
			}
	printf("%lld\n", dp[n][0][2]);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}