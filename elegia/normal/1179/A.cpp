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

const int N = 100010;

int n;
int a[N * 2];
pair<int, int> ans[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  int x = a[1], y;
  for (int i = 1; i <= n - 1; ++i) {
    y = a[i + 1];
    ans[i] = make_pair(x, y);
    if (x < y)
      swap(x, y);
    a[n + i] = y;
  }
  while (q--) {
    ll m;
    scanf("%lld", &m);
    if (m <= n - 1)
      printf("%d %d\n", ans[m].first, ans[m].second);
    else
      printf("%d %d\n", x, a[m % (n - 1) + n]);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}