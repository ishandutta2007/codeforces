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

struct E {
  int v, w;
  E* next;
};

struct Nde {
  int u, v, w, id;
  
  bool operator<(const Nde& rhs) const {
    return w < rhs.w;
  }
};

const int N = 200010, L = 18;

int n, m;
int prt[N][L], mx[N][L];
int val[N];
int ans[N], f[N], dep[N];
bool vis[N];
Nde ed[N];
E* g[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void adde(int u, int v, int w);
void dfs(int u);
pair<int, int> qry(int u, int v);
void flush(int u, int d, int w);

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  scanf("%d%d", &n, &m);
  iota(f + 1, f + n + 1, 1);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &ed[i].u, &ed[i].v, &ed[i].w);
    ed[i].id = i;
  }
  sort(ed + 1, ed + m + 1);
  for (int i = 1; i <= m; ++i) {
    int x = find(ed[i].u), y = find(ed[i].v);
    if (x != y) {
      f[x] = y;
      adde(ed[i].u, ed[i].v, ed[i].w);
      adde(ed[i].v, ed[i].u, ed[i].w);
    }
  }
  dfs(1);
  iota(f + 1, f + n + 1, 1);
  for (int i = 1; i <= m; ++i) {
    if (prt[ed[i].u][0] == ed[i].v || prt[ed[i].v][0] == ed[i].u)
      continue;
    int lca, cans;
    tie(cans, lca) = qry(ed[i].u, ed[i].v);
    ans[ed[i].id] = cans - 1;
    flush(ed[i].u, dep[lca], ed[i].w);
    flush(ed[i].v, dep[lca], ed[i].w);
  }
  for (int i = 1; i <= m; ++i)
    if (prt[ed[i].u][0] == ed[i].v || prt[ed[i].v][0] == ed[i].u) {
      int u = ed[i].u, v = ed[i].v;
      if (prt[u][0] == v)
        swap(u, v);
      ans[ed[i].id] = val[v] - 1;
    }
  for (int i = 1; i <= m; ++i)
    printf("%d ", ans[i]);
  
  return 0;
}

void flush(int u, int d, int w) {
  u = find(u);
  while (dep[u] > d) {
    val[u] = w;
    f[u] = prt[u][0];
    u = find(u);
  }
}

pair<int, int> qry(int u, int v) {
  int ret = 0;
  if (dep[u] < dep[v])
    swap(u, v);
  for (int k = L - 1; k >= 0; --k)
    if ((dep[u] - dep[v]) >> k & 1) {
      ret = max(ret, mx[u][k]);
      u = prt[u][k];
    }
  if (u == v)
    return make_pair(ret, u);
  for (int k = L - 1; k >= 0; --k)
    if (prt[u][k] != prt[v][k]) {
      ret = max({ret, mx[u][k], mx[v][k]});
      u = prt[u][k];
      v = prt[v][k];
    }
  return make_pair(max({ret, mx[u][0], mx[v][0]}), prt[u][0]);
}

void dfs(int u) {
  vis[u] = true;
  for (int i = 1; i < L; ++i) {
    prt[u][i] = prt[prt[u][i - 1]][i - 1];
    mx[u][i] = max(mx[u][i - 1], mx[prt[u][i - 1]][i - 1]);
  }
  for (E* p = g[u]; p; p = p->next)
    if (!vis[p->v]) {
      dep[p->v] = dep[u] + 1;
      prt[p->v][0] = u;
      mx[p->v][0] = p->w;
      dfs(p->v);
    }
}

void adde(int u, int v, int w) {
  static E pool[N * 2];
  static E* p = pool;
  p->v = v;
  p->w = w;
  p->next = g[u];
  g[u] = p;
  ++p;
}