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

const int N = 200010, L = 20;

int n, m, q;
int val[N], prt[N][L];
int p[N], a[N], rev[N], good[N];
char s[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &p[i]);
  for (int i = 1; i <= n; ++i)
    rev[p[i]] = i;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
    a[i] = rev[a[i]];
  }
  for (int i = 1; i <= m; ++i) {
    if (a[i] == 1)
      prt[i][0] = val[n];
    else
      prt[i][0] = val[a[i] - 1];
    val[a[i]] = i;
    for (int j = 1; j < L; ++j)
      prt[i][j] = prt[prt[i][j - 1]][j - 1];
    good[i] = i;
    for (int j = 0; j < L; ++j)
      if ((n - 1) >> j & 1)
        good[i] = prt[good[i]][j];
    good[i] = max(good[i], good[i - 1]);
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (good[r] >= l)
      putchar('1');
    else
      putchar('0');
  }


#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}