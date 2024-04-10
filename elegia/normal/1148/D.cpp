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

const int N = 300010;

int n, ca, cb;
int a[N * 2], b[N * 2];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int rep = 0; rep < n; ++rep) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < y) {
      a[x] = rep + 1;
      ++ca;
    } else {
      b[x] = rep + 1;
      ++cb;
    }
  }
  if (ca > cb) {
    printf("%d\n", ca);
    for (int i = n * 2; i; --i)
      if (a[i])
        printf("%d ", a[i]);
  } else {
    printf("%d\n", cb);
    for (int i = 1; i <= n * 2; ++i)
      if (b[i])
        printf("%d ", b[i]);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}