#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 510, P = 998244353;

int n;
int a[N];
int dp[N][N], pos[N][N];



int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%*d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    int p = i;
    for (int j = i; j <= n; ++j) {
      if (a[j] < a[p])
        p = j;
      pos[i][j] = p;
    }
  }
  for (int len = 0; len <= n; ++len)
    for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
      if (len <= 1) {
        dp[l][r] = 1;
        continue;
      }
      int p1 = 0, p2 = 0;
      int p = pos[l][r];

      for (int i = l; i <= p; ++i)
        p1 = (p1 + dp[l][i - 1] * (ll)dp[i][p - 1]) % P;
      for (int i = p; i <= r; ++i)
        p2 = (p2 + dp[p + 1][i] * (ll)dp[i + 1][r]) % P;
      dp[l][r] = p1 * (ll)p2 % P;
    }
  printf("%d\n", dp[1][n]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}