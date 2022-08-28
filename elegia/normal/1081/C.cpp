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

const int N = 2010, P = 998244353;

int n, m, k;
int dp[N][N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &n, &m, &k);
  dp[1][0] = m;
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < i; ++j) {
      dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % P;
      dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (ll)(m - 1)) % P;
    }
  printf("%d\n", dp[n][k]);

#ifdef LBT
  LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}