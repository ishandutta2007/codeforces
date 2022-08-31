#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Edge {
  int v;
  Edge* next;
};

const int N = 100010, K = 210, P = 1000000007;

int n, k;
int use[K];
int sub[N];
int f[N][K], g[N][K];
int s[K][K];
Edge* gr[N];

void adde(int u, int v);
void dfs(int u);

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  scanf("%d%d", &n, &k);
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    scanf("%d%d", &u, &v);
    adde(u, v);
    adde(v, u);
  }
  dfs(1);
  s[0][0] = 1;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j)
      s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * (ll)j) % P;
  int fac = 1;
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    fac = fac * (ll)i % P;
    ans = (ans + fac * (ll)s[k][i] % P * use[i]) % P;
  }
  printf("%d\n", ans);

  return 0;
}

void dfs(int u) {
  static int tmp[K];
  sub[u] = 1;
  f[u][0] = 1;
  for (Edge* p = gr[u]; p; p = p->next)
    if (!sub[p->v]) {
      dfs(p->v);
      int k1 = min(k, sub[u] - 1), k2 = min(k, sub[p->v]);
      for (int i = k2; i; --i)
        g[p->v][i] = (g[p->v][i] + (ll)g[p->v][i - 1] + f[p->v][i - 1] + f[p->v][i]) % P;
      g[p->v][0] = (g[p->v][0] + f[p->v][0]) % P;
      memset(tmp, 0, sizeof(tmp));
      for (int i = 0; i <= k1; ++i)
        for (int j = 0; j <= k2 && i + j <= k; ++j)
          tmp[i + j] = (tmp[i + j] + (f[u][i] + g[u][i]) * (ll) g[p->v][j]) % P;
      sub[u] += sub[p->v];
      int kk = min(k, sub[u] - 1);
      for (int i = 0; i <= kk; ++i) {
        if ((f[u][i] += tmp[i]) >= P)
          f[u][i] -= P;
        if ((g[u][i] += g[p->v][i]) >= P)
          g[u][i] -= P;
      }
    }
  for (int i = 0; i <= min(k, sub[u] - 1); ++i) {
    if ((use[i] += f[u][i]) >= P)
      use[i] -= P;
  }
}

void adde(int u, int v) {
  static Edge pool[N * 2];
  static Edge* p = pool;
  p->v = v;
  p->next = gr[u];
  gr[u] = p;
  ++p;
}