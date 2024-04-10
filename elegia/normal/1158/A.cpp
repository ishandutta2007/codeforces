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

const int N = 100010;

int n, m;
int a[N], b[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i)
    scanf("%d", &b[i]);
  int x = *max_element(a + 1, a + n + 1), y = *min_element(b + 1, b + m + 1);
  if (x > y) {
    puts("-1");
    return 0;
  }
  sort(a + 1, a + n + 1);
  ll ans = accumulate(a + 1, a + n + 1, 0LL) * m + accumulate(b + 1, b + m + 1, 0LL);
  if (x < y)
    ans -= a[n] * (ll)(m - 1) + a[n - 1];
  else
    ans -= a[n] * (ll)m;
  printf("%lld\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}