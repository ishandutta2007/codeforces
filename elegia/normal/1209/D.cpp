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
int f[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int k;
  scanf("%d%d", &n, &k);
  iota(f + 1, f + n + 1, 1);
  int ans = 0;
  while (k--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = find(x);
    y = find(y);
    if (x != y)
      f[x] = y;
    else
      ++ans;
  }
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}