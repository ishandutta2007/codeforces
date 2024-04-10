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

int ans = 1;

const int N = 16;
int n;
int a[N];

void dc(int l, int r) {
  if (is_sorted(a + l, a + r + 1)) {
    ans = max(ans, r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  dc(l, mid);
  dc(mid + 1, r);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  dc(0, n - 1);
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}