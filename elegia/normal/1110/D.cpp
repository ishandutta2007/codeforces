#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1000010;

int n, m;
int a[N], dp[N][7][7];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int c;
    scanf("%d", &c);
    ++a[c];
  }
  for (int i = m; i; --i) {
    for (int j = 0; j < 7; ++j)
      for (int k = 0; k < 7; ++k) {
        if (j > a[i])
          continue;
        int x = a[i] - j, t = (i - 2) < 1 ? 0 : a[i - 2];
        for (int v = 0; v < 3 && v + k < 7 && v <= t && v <= x; ++v) {
          dp[i - 1][k + v][v] = max(dp[i - 1][k + v][v], dp[i][j][k] + v + (x - v) / 3);
        }
      }
  }
  printf("%d\n", dp[0][0][0]);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}