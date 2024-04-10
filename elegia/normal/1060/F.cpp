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

const int N = 52;

int n;
vector<int> ch[N];
double f[N][N], binom[N][N];
int sub[N];

void dfs(int u) {
  static double tmp[N], tmp2[N];
  f[u][0] = 1;
  sub[u] = 1;
  for (int v : ch[u])
    if (!sub[v]) {
      dfs(v);
      tmp[0] = 0;
      for (int i = 0; i < sub[v]; ++i)
        tmp[i + 1] = f[v][i] * (i + 1) / sub[v];
      for (int i = 0; i < sub[v]; ++i)
        for (int j = 0; j <= i; ++j)
          tmp[j] += f[v][i] / sub[v] / 2;
      memset(tmp2, 0, sizeof(double) * (sub[u] + sub[v]));
      for (int i = 0; i < sub[u]; ++i)
        for (int j = 0; j <= sub[v]; ++j)
          tmp2[i + j] += tmp[j] * f[u][i] * binom[i + j][i] * binom[sub[u] - 1 - i + sub[v] - j][sub[u] - 1 - i];
      for (int i = 0; i < sub[u] + sub[v]; ++i)
        f[u][i] = tmp2[i] / binom[sub[u] - 1 + sub[v]][sub[u] - 1];
      sub[u] += sub[v];
    }
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
  }
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    scanf("%d%d", &u, &v);
    ch[u].push_back(v);
    ch[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    memset(f, 0, sizeof(f));
    memset(sub, 0, sizeof(sub));
    dfs(i);
    printf("%.010lf\n", f[i][0]);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}