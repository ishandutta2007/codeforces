#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int tr[4][4] = {
		{0, 1, 1, 1},
		{0, 0, 2, 0},
		{0, 2, 0, 0},
		{1, 1, 1, 0},
};

const int N = 1010, P = 998244353;

int dp[N * 2][4], tmp[N * 2][4];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	dp[1][0] = dp[1][3] = 1;
	dp[2][1] = dp[2][2] = 1;
	for (int l = 1; l < n; ++l) {
		memcpy(tmp, dp, sizeof(tmp));
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= l * 2; ++j)
			for (int u = 0; u < 4; ++u)
				for (int v = 0; v < 4; ++v)
					dp[j + tr[u][v]][v] = (dp[j + tr[u][v]][v] + tmp[j][u]) % P;
	}
	printf("%d\n", int(accumulate(dp[k], dp[k] + 4, 0LL) % P));

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}