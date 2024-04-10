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

const int N = 100010, B = 320;

int n, b;
int a[N];
int ans[N][B];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i] += i;
  }
  int q;
  scanf("%d", &q);
  b = sqrt(q);
  for (int i = n; i; --i) {
    for (int j = 1; j <= b; ++j)
      ans[i][j] = 1 + (a[i] + j > n ? 0 : ans[a[i] + j][j]);
  }
  while (q--) {
    int p, k;
    scanf("%d%d", &p, &k);
    if (k <= b)
      printf("%d\n", ans[p][k]);
    else {
      int cur = 0;
      while (p <= n) {
        ++cur;
        p = a[p] + k;
      }
      printf("%d\n", cur);
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}