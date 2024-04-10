#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

struct IO_Tp
{
  const static int _I_Buffer_Size = 25 << 20;
  char _I_Buffer[_I_Buffer_Size], *_I_pos;
 
  IO_Tp() : _I_pos(_I_Buffer) {
//    freopen("tree.in", "r", stdin);
    fread(_I_Buffer, 1, _I_Buffer_Size, stdin);
  }
 
  IO_Tp &operator>>(int &res)
  {
    while (!isdigit(*_I_pos))
      ++_I_pos;
    res = *_I_pos++ & 15;
    while (isdigit(*_I_pos))
      (res *= 10) += *_I_pos++ & 15;
    return *this;
  }
 
  IO_Tp &operator>>(char *res)
  {
    while (isspace(*_I_pos))
      ++_I_pos;
    while (!isspace(*_I_pos))
      *res++ = *_I_pos++;
    *res = '\0';
    return *this;
  }
} IO;

struct E {
  int v;
  E* next;
};

const int N = 200010;

int n, lm, rt;
int fw[N * 2], deg[N], sub[N], pref[N], prt[N], dfn[N], rdfn[N], top[N], dep[N], ed[N * 2];
map<int, int> seg;
E* g[N];

int lowBit(int k) { return k & -k; }

void ch(int k, int x) {
  for (; k <= lm; k += lowBit(k))
    fw[k] += x;
}

int qry(int k) {
  int ret = 0;
  for (; k; k -= lowBit(k))
    ret += fw[k];
  return ret;
}

void adde(int u, int v) {
  static E pool[N * 2], *p = pool;
  p->v = v;
  p->next = g[u];
  g[u] = p;
  ++p;
}

void dfs(int u) {
  sub[u] = 1;
  for (E* p = g[u]; p; p = p->next)
    if (!sub[p->v]) {
      prt[p->v] = u;
      dep[p->v] = dep[u] + 1;
      dfs(p->v);
      sub[u] += sub[p->v];
      if (sub[pref[u]] < sub[p->v])
        pref[u] = p->v;
    }
}

void hld(int u) {
  static int t;
  dfn[u] = ++t;
  rdfn[t] = u;
  if (!top[u]) top[u] = u;
  if (pref[u]) {
    top[pref[u]] = top[u];
    hld(pref[u]);
  }
  for (E* p = g[u]; p; p = p->next)
    if (!dfn[p->v])
      hld(p->v);
}

void split(int k) {
  if (k == 0) return;
  map<int, int>::iterator it = seg.lower_bound(k);
  if (it->first == k) return;
  seg.insert(make_pair(k, it->second));
}

int dist(int u, int v) {
  int x = top[u], y = top[v], ret = dep[u] + dep[v];
  while (x != y) {
    if (dep[x] < dep[y]) {
      swap(u, v);
      swap(x, y);
    }
    u = prt[x];
    x = top[u];
  }
  return ret - 2 * min(dep[u], dep[v]) + 1;
}

int qwhen(int u) {
  int col = seg.lower_bound(dfn[u])->second;
  return qry(col - 1) + dist(u, ed[col]);
}

int main() {
//  freopen("tree.out", "w", stdout);
  int q;
  IO >> n >> q;
  lm = n + q;
  int rt = n;
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    IO >> u >> v;
    adde(u, v);
    adde(v, u);
    ++deg[u]; ++deg[v];
  }
  priority_queue<int, vector<int>, greater<int> > que;
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 1)
      que.push(i);
  dfs(1);
  hld(1);
  for (int i = 1; i <= n; ++i) {
    int u = que.top(); que.pop();
    ch(i, 1);
    ed[i] = u;
    seg.insert(make_pair(dfn[u], i));
    for (E* p = g[u]; p; p = p->next)
      if (--deg[p->v] == 1)
        que.push(p->v);
  }
  rt = n;
  int cnt = n;
  while (q--) {
    static char opt[20];
    int u, v;
    IO >> opt >> u;
    if (opt[0] == 'u') {
      v = rt;
      rt = u;
      int d = dist(u, v);
      ++cnt;
      ed[cnt] = v;
      int x = top[u], y = top[v];
      while (x != y) {
        if (dep[x] < dep[y]) {
          swap(x, y);
          swap(u, v);
        }
        split(dfn[u]);
        split(dfn[x] - 1);
        int lst = dfn[x] - 1;
        for (map<int, int>::iterator it = seg.lower_bound(dfn[x]); it != seg.end() && it->first <= dfn[u]; seg.erase(it++)) {
          ch(it->second, -it->first + lst);
          lst = it->first;
        }
        seg.insert(make_pair(dfn[u], cnt));
        u = prt[x];
        x = top[u];
      }
      if (dep[u] > dep[v]) swap(u, v);
      split(dfn[u] - 1);
      split(dfn[v]);
      int lst = dfn[u] - 1;
      for (map<int, int>::iterator it = seg.lower_bound(dfn[u]); it != seg.end() && it->first <= dfn[v]; seg.erase(it++)) {
        ch(it->second, -it->first + lst);
        lst = it->first;
      }
      seg.insert(make_pair(dfn[v], cnt));
      ch(cnt, d);
    } else if (opt[0] == 'w') {
      printf("%d\n", qwhen(u));
    } else {
      IO >> v;
      printf("%d\n", qwhen(u) < qwhen(v) ? u : v);
    }
  }
  return 0;
}