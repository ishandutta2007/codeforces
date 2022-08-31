#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <tuple>
#include <stack>
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

const int N = 100010, D = 50;

int n, d, sc;
int dfn[N * D], low[N * D], good[N * D], belongs[N * D], nxt[N * D];
int ev[N], enxt[N];
bool instk[N * D], use[N];
char s[N][D];
int ans[N * D], seq[N * D];
int g[N];

int norm(int x) { return x >= d ? (x - d) : x; }
int gu(int u, int k) { return (u - 1) * d + k + 1; }
void tarjan();
int dfs2(int u);
void adde(int u, int v);

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int m;
  scanf("%d%d%d", &n, &m, &d);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    adde(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i]);
  }
  tarjan();
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i <= sc; ++i)
      dfs2(seq[i]);
  printf("%d\n", ans[1]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}

int dfs2(int u) {
  ans[u] = 0;
  for (int v = u; v; v = nxt[v]) {
    for (int i = g[(v - 1) / d + 1]; i; i = enxt[i]) {
      if (belongs[gu(ev[i], norm((v - 1) % d + 1))] != u)
        ans[u] = max(ans[u], ans[belongs[gu(ev[i], norm((v - 1) % d + 1))]]);
    }
  }
  return ans[u] += good[u];
}

void tarjan() {
  static int t, top, fc;
  static int stk[N * D];
  static int fi[N * D], fuu[N * D];
  fuu[++fc] = 1;
  fi[fc] = -1;
  while (fc) {
    int uu = fuu[fc], u = (uu - 1) / d + 1, k = (uu - 1) % d;
    int i = fi[fc];
    if (i == -1) {LOG("DFS %d %d\n", u, k);
      dfn[uu] = low[uu] = ++t;
      stk[++top] = uu;
      instk[uu] = true;
      i = g[u];
    } else {
      low[uu] = min(low[uu], low[gu(ev[i], norm(k + 1))]);
      i = enxt[i];
    }
    for (; i; i = enxt[i]) {
      int vv = gu(ev[i], norm(k + 1));
      LOG("%d %d -> %d %d\n", u, k, ev[i], norm(k + 1));
      if (!dfn[vv]) {
        LOG("%d %d PUSH %d %d\n", u, k, ev[i], norm(k + 1));
        ++fc;
        fuu[fc] = vv;
        fi[fc] = -1;
        break;
      } else if (instk[vv])
        low[uu] = min(low[vv], low[uu]);
    }
    if (i) {
      fi[fc - 1] = i;
      continue;
    }
    if (dfn[uu] == low[uu]) {
      LOG("SCC:");
      int v;
      int tmp = top;
      do {
        v = stk[top--];
        LOG(" %d", v);
        instk[v] = false;
        low[v] = dfn[uu];
        belongs[v] = uu;
      } while (uu != v);
      LOG("\n");
      int cost = 0;
      for (int i = top + 1; i <= tmp; ++i) {
        int v = stk[i];
        int u = (v - 1) / d + 1, k = (v - 1) % d;
        if (s[u][k] == '1') {
          if (!use[u]) {
            ++cost;
            use[u] = true;
          }
        }
        if (i < tmp)
          nxt[v] = stk[i + 1];
      }
      for (int i = top + 1; i <= tmp; ++i) {
        int v = stk[i];
        use[(v - 1) / d + 1] = false;
      }
      good[uu] = cost;
      seq[++sc] = uu;
    }
    LOG("LEAVE %d %d\n", u, k);
    --fc;
  }
}

void adde(int u, int v) {
  static int t;
  ++t;
  ev[t] = v;
  enxt[t] = g[u];
  g[u] = t;
}