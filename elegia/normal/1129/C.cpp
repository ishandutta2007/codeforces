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

const int N = 3010, P = 1000000007;

int n;
int good[N], dp[N][N];
int taboo[] = { 0b0011, 0b0101, 0b1110, 0b1111 };
bool vis[1 << 4];
int f[N];

void run(int* a, int* g, int n) {
  static int nxt[N];
  int k = 0;
  for (int i = 2; i <= n; ++i) {
    while (k && a[k + 1] != a[i])
      k = nxt[k];
    if (a[k + 1] == a[i])
      ++k;
    nxt[i] = k;
    g[i] = max(g[i], nxt[i]);
  }
}

void add(int& x, int y) {
  if ((x += y) >= P)
    x -= P;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  for (int i = 0; i < 4; ++i)
    vis[taboo[i]] = true;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &f[i]);
  for (int i = 0; i < n; ++i)
    run(f + i, good + i, n - i);
  for (int i = 1; i <= n; ++i) {
    dp[i][i - 1] = 1;
    for (int j = i; j <= n; ++j) {
      for (int l = 1; l <= 4 && l <= j - i + 1; ++l) {
        if (l != 4 || !vis[f[j - 3] << 3 | f[j - 2] << 2 | f[j - 1] << 1 | f[j]])
          add(dp[i][j], dp[i][j - l]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i - good[i]; ++j)
      add(ans, dp[j][i]);
    printf("%d\n", ans);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}