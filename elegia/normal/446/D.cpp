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

const int N = 510, T = 110;

int n, a, b, k;
int id[N], deg[N], ia[N], ib[N];
bool trap[N];
int g[N][N];
double mt[N][N], fp[N][N]; // a * a, a * b
double bas[N], tmp[N];

// trap u : p[u][u] = 1
// notrap u : p[u][v] = sum_adj p[adj][v] / |adj|

// P : p[adj][v] / |adj|



int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int m;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &trap[i]);
  for (int i = 1; i <= n; ++i)
    if (trap[i]) {
      id[i] = ++b;
      ib[b] = i;
    } else {
      id[i] = ++a;
      ia[a] = i;
    }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    ++g[u][v];
    ++g[v][u];
  }
  for (int i = 1; i <= n; ++i)
    deg[i] = accumulate(g[i] + 1, g[i] + n + 1, 0);
  for (int i = 1; i <= a; ++i)
    for (int j = 1; j <= b; ++j)
      if (g[ia[i]][ib[j]])
        fp[i][j] = g[ia[i]][ib[j]] / (double)deg[ia[i]];
  for (int i = 1; i <= a; ++i)
    for (int j = 1; j <= a; ++j)
      if (g[ia[i]][ia[j]])
        mt[i][j] = -g[ia[i]][ia[j]] / (double)deg[ia[i]];
  for (int i = 1; i <= a; ++i)
    mt[i][i] = 1;
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j)
      fp[i][j] /= mt[i][i];
    for (int j = a; j >= i; --j)
      mt[i][j] /= mt[i][i];
    for (int j = i + 1; j <= a; ++j) {
      for (int t = 1; t <= b; ++t)
        fp[j][t] -= fp[i][t] * mt[j][i];
      for (int t = a; t >= i; --t)
        mt[j][t] -= mt[i][t] * mt[j][i];
    }
  }
  for (int i = a; i; --i) {
    for (int j = 1; j < i; ++j) {
      for (int t = 1; t <= b; ++t)
        fp[j][t] -= fp[i][t] * mt[j][i];
      for (int t = 1; t <= i; ++t)
        mt[j][t] -= mt[i][t] * mt[j][i];
    }
  }
  for (int i = 1; i <= b; ++i)
    bas[i] = fp[1][i];
  memset(mt, 0, sizeof(mt));
  for (int i = 1; i <= b; ++i) {
    int u = ib[i];
//    printf("%d\n", deg[u]);
    for (int v = 1; v <= n; ++v)
      if (g[u][v]) {
//        printf("%d %d(%d)\n", u, v, id[v]);
        if (trap[v])
          mt[i][id[v]] += g[u][v] / (double)deg[u];
        else
          for (int j = 1; j <= b; ++j)
            mt[i][j] += fp[id[v]][j] * g[u][v] / deg[u];
      }
  }
//  printf("%d %d\n%d %d\n", int(mt[1][1] * 1000), int(mt[1][2] * 1000), int(mt[2][1] * 1000), int(mt[2][2] * 1000));
  k -= 2;
  while (k) {
    if (k & 1) {
      memset(tmp, 0, sizeof(tmp));
      for (int i = 1; i <= b; ++i)
        for (int j = 1; j <= b; ++j)
          tmp[j] += bas[i] * mt[i][j];
      memcpy(bas, tmp, sizeof(tmp));
    }
    if (k >>= 1) {
      memset(fp, 0, sizeof(fp));
      for (int i = 1; i <= b; ++i)
        for (int j = 1; j <= b; ++j)
          for (int t = 1; t <= b; ++t)
            fp[i][j] += mt[i][t] * mt[t][j];
      memcpy(mt, fp, sizeof(mt));
    }
  }
//  printf("%d\n", int(bas[b] * 1000));
  printf("%.6f\n", bas[b]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}