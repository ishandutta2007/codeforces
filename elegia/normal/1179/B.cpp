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

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n - i + 1; ++i)
    for (int j = 1; j <= m; ++j)
      printf("%d %d\n%d %d\n", i, j, n - i + 1, m - j + 1);
  if (n & 1) {
    for (int j = 1; j < m - j + 1; ++j)
      printf("%d %d\n%d %d\n", (n + 1) >> 1, j, (n + 1) >> 1, m - j + 1);
    if (m & 1)
      printf("%d %d\n", (n + 1) >> 1, (m + 1) >> 1);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}