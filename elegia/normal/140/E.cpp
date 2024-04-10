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

const int N = 1000010, L = 5010;

int n, m;
int fall[L], ans[L], tmp[L], fac[L];
int dp[L][L];
int l[N];
int P;

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d", &n, &m, &P);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &l[i]);
	int ml = *max_element(l + 1, l + n + 1);
	dp[1][1] = 1;
	for (int i = 1; i < ml; ++i) {
		for (int j = 1; j <= i && j <= m; ++j) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (ll)(j - 1)) % P;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % P;
		}
	}
	fall[0] = 1;
	for (int i = 1; i <= ml; ++i)
		fall[i] = fall[i - 1] * (ll)(m - i + 1) % P;
	fac[0] = 1;
	for (int i = 1; i <= ml; ++i)
		fac[i] = fac[i - 1] * (ll)i % P;
	for (int i = 1; i <= l[1]; ++i)
		ans[i] = dp[l[1]][i] * (ll)fall[i] % P;
	for (int i = 2; i <= n; ++i) {
		int sum = accumulate(ans + 1, ans + l[i - 1] + 1, 0LL) % P;
		for (int j = 1; j <= l[i] && j <= m; ++j) {
			if (j > l[i - 1])
				ans[j] = sum * (ll)dp[l[i]][j] % P * fall[j] % P;
			else {
				ans[j] = (sum * (ll)dp[l[i]][j] % P * fall[j] % P - ans[j] * (ll)dp[l[i]][j] % P * fac[j] % P) % P;
				if (ans[j] < 0)
					ans[j] += P;
			}
		}
	}
	printf("%d\n", int(accumulate(ans + 1, ans + min(l[n], m) + 1, 0LL) % P));

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}