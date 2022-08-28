#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <chrono>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#ifdef LBT

#define LOG(FMT...) fprintf(stderr, FMT)

#else

#define LOG(FMT...)

#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;

int n, m;
int a[N][N], x[N][N], y[N][N], r[N], c[N];
int tmp[N], res[N];

void grank(int n) {
  static int st[N];
  memcpy(st, tmp, sizeof(st));
  sort(st + 1, st + n + 1);
  int cnt = unique(st + 1, st + n + 1) - st - 1;
  for (int i = 1; i <= n; ++i)
    res[i] = lower_bound(st + 1, st + cnt + 1, tmp[i]) - st;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; ++i) {
    memcpy(tmp, a[i], sizeof(tmp));
    grank(m);
    memcpy(x[i], res, sizeof(res));
    r[i] = *max_element(res + 1, res + m + 1);
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i)
      tmp[i] = a[i][j];
    grank(n);
    for (int i = 1; i <= n; ++i)
      y[i][j] = res[i];
    c[j] = *max_element(res + 1, res + n + 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      //LOG("%d %d: %d %d %d %d\n", i, j, x[i][j], y[i][j], r[i], c[j]);
      int mx = max(x[i][j], y[i][j]);
      mx += max(r[i] - x[i][j], c[j] - y[i][j]);
      printf("%d ", mx);
    }
    putchar('\n');
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}