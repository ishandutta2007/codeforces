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

const int N = 60, P = 1000000007, I2 = 500000004;

int n;
int d[N], fac[N], pw[N], inv[N], ifac[N], c1[N], c2[N];
int dp[N][N];
int sub[N][N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &d[i]);
	for (int i = 2; i <= n; ++i) {
		c1[i] = c1[i - 1] + (d[i] == 2);
		c2[i] = c2[i - 1] + (d[i] == 3);
	}
	fac[0] = 1;
	pw[0] = 1;
	inv[1] = 1;
	ifac[0] = 1;
	for (int x = 2; x <= n; ++x)
		inv[x] = -(P / x) * (ll)inv[P % x] % P + P;
	for (int x = 1; x <= n; ++x) {
		fac[x] = fac[x - 1] * (ll)x % P;
		pw[x] = pw[x - 1] * (ll)I2 % P;
		ifac[x] = ifac[x - 1] * (ll)inv[x] % P;
	}
	sub[0][0][0] = 1;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; i + j * 2 <= n; ++j)
			sub[0][i][j] = fac[i + j * 2] * (ll)pw[j] % P;
	for (int k = 1; k <= n; ++k)
		for (int j = 0; j <= n; ++j)
			for (int i = 0; i <= n; ++i) {
				int m = i + j * 2 - k * 2;
				if (m < 0)
					continue;
				if (j >= 1)
					sub[k][i][j] = sub[k][i][j - 1] * (m * (ll)(m - 1) / 2) % P;
				if (j >= 2)
					sub[k][i][j] = (sub[k][i][j] + sub[k - 1][i + 1][j - 2] * (ll)(j - 1) % P * m % P) % P;
				if (i >= 1 && j >= 1)
					sub[k][i][j] = (sub[k][i][j] + sub[k - 1][i - 1][j - 1] * (ll)i % P * m % P) % P;
				if (k >= 2) {
					if (j >= 3)
						sub[k][i][j] = (sub[k][i][j] + sub[k - 2][i + 2][j - 3] * (ll) ((j - 1) * (j - 2) / 2) % P) % P;
					if (j >= 2 && i >= 1)
						sub[k][i][j] = (sub[k][i][j] + sub[k - 2][i][j - 2] * (ll)((j - 1) * i) % P) % P;
					if (j >= 1 && i >= 2)
						sub[k][i][j] = (sub[k][i][j] + sub[k - 2][i - 2][j - 1] * (ll)(i * (i - 1) / 2)) % P;
				}
				if (j == 0) {
					if (i >= 1)
						sub[k][i][0] = (sub[k][i][0] + sub[k][i - 1][0] * (ll)m) % P;
					if (i >= 2)
						sub[k][i][0] = (sub[k][i][0] + sub[k - 1][i - 2][0] * (ll)(i - 1)) % P;
				}
			}

	dp[n + 1][0] = 1;
	for (int l = n; l > 1; --l)
		for (int d = 1; d <= n - l + 1; ++d) {
			int v1 = c1[l + d - 1] - c1[l - 1], v2 = c2[l + d - 1] - c2[l - 1];
			for (int k = 0; k * 2 <= v1 + v2 * 2; ++k)
				if (v1 + v2 * 2 - k * 2 >= 0 && v1 + v2 * 2 - k * 2 <= n + 1) {
					dp[l][d] = (dp[l][d] + sub[k][v1][v2] * (ll)dp[l + d][v1 + v2 * 2 - k * 2]) % P;
				}
		}

	printf("%d\n", dp[2][d[1]]);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}