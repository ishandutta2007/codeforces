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

const int N = 5010;

int n, a, b;
char s[N];
int dp[N];
short lcp[N][N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d%s", &n, &a, &b, s + 1);
  for (int i = n; i; --i)
    for (int j = n; j; --j)
      lcp[i][j] = (s[i] == s[j]) ? (lcp[i + 1][j + 1] + 1) : 0;
  for (int i = n; i; --i) {
    int len = 0;
    for (int j = 1; j < i; ++j)
      len = max(len, min((int)lcp[i][j], i - j));
    if (len == 0)
      dp[i] = dp[i + 1] + a;
    else
      dp[i] = min(dp[i + 1] + a, dp[i + len] + b);
  }
  printf("%d\n", dp[1]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}