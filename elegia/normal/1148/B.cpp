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

const int N = 200010;

int n, m, a, b, k;
int x[N], y[N];

bool pred(int v) {
  v -= b;
  int cnt = n;
  int lb = upper_bound(y + 1, y + m + 1, v) - y - 1;
  int ptr = 1;
  for (int i = 1; i <= n; ++i) {
    int cur = i - 1;
    int p = x[i] + a;
    while (ptr <= lb && y[ptr] < p) ++ptr;
    cnt = min(cnt, cur + lb - ptr + 1);
  }
  return cnt > k;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &x[i]);
  for (int i = 1; i <= m; ++i)
    scanf("%d", &y[i]);
  int l = 0, r = 2e9 + 10;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (pred(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (l > 2e9 + 5)
    puts("-1");
  else
    printf("%d\n", l);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}