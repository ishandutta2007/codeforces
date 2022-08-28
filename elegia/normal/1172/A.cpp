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

int n;
int a[N], b[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);

  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &b[i]);
  int pos = 0;
  for (int i = 1; i <= n; ++i)
    if (b[i] == 1) {
      pos = i;
      break;
    }
  bool flag = true;
  if (pos)
    for (int i = pos; i <= n; ++i)
      flag &= b[i] == (i - pos + 1);
  if (pos && flag) {
    flag = true;
    for (int i = 1; i < pos; ++i)
      if (b[i])
        flag &= (n - pos + 1) + i < b[i];
    if (flag) {
      printf("%d\n", pos - 1);
      return 0;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i])
      ans = max(ans, i - b[i] + 1);
  }
  printf("%d\n", ans + n);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}