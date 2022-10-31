#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos(-1.0L);

void precalc() {
}

const int maxn = 2 * 1000 + 10;
int n, m[2];

int a[2][maxn * maxn][2];

bool read() {
  if (scanf("%d%d%d", &n, &m[0], &m[1]) < 3) {
    return 0;
  }
  for (int it = 0; it < 2; ++it) {
    for (int i = 0; i < m[it]; ++i) {
      for (int j = 0; j < 2; ++j) {
        int x;
        scanf("%d", &x);
        a[it][i][j] = 2 * (abs(x) - 1) + (x < 0);
      }
    }
  }
  return 1;
}

vector<vector<int> > es, esrev;

const int maxv = 2 * maxn;
int used[maxv];

int tme;
int perm[maxv];

void dfs1(int v) {
  used[v] = 1;
  for (int it = 0; it < sz(es[v]); ++it) {
    int u = es[v][it];
    if (used[u]) {
      continue;
    }
    dfs1(u);
  }
  perm[tme++] = v;
}

int col[maxv];
int maxc;

void dfs2(int v) {
  col[v] = maxc;
  for (int it = 0; it < sz(esrev[v]); ++it) {
    int u = esrev[v][it];
    if (col[u] != -1) {
      continue;
    }
    dfs2(u);
  }
}

bool buildTopSort() {
  int cnt = 2 * n;
  for (int i = 0; i < cnt; ++i) {
    used[i] = 0;
  }
  tme = 0;
  for (int i = 0; i < cnt; ++i) {
    if (used[i]) {
      continue;
    }
    dfs1(i);
  }
  assert(tme == cnt);
  esrev = vector<vector<int> >(cnt);
  for (int i = 0; i < cnt; ++i) {
    for (int it = 0; it < sz(es[i]); ++it) {
      esrev[es[i][it]].pb(i);
    }
  }

  for (int i = 0; i < cnt; ++i) {
    col[i] = -1;
  }
  maxc = 0;
  for (int i = 0; i < cnt; ++i) {
    int v = perm[cnt - 1 - i];
    if (col[v] != -1) {
      continue;
    }
    dfs2(v);
    ++maxc;
  }

  bool fail = 0;
  for (int i = 0; i < n; ++i) {
    if (col[2 * i] == col[2 * i + 1]) {
      return 0;
    }
  }
  return 1;
}

struct Set {
  const static int k = maxv / 32 + 3;
  unsigned a[k];

  Set() {
    memset(a, 0, sizeof(a));
  }

  int get(int x) {
    return ((a[x >> 5] >> (x & 31)) & 1);
  }

  inline void operator |= (const Set &s) {
    for (int i = 0; i < k; ++i) {
      a[i] |= s.a[i];
    }
  }
};

Set go[maxv];

int ans[maxn];

void solve() {
  for (int ist = 0; ist < 2; ++ist) {
    int cnt = 2 * n;
    es = vector<vector<int> >(cnt);
    for (int i = 0; i < m[ist]; ++i) {
      es[1 ^ a[ist][i][0]].pb(a[ist][i][1]);
      es[1 ^ a[ist][i][1]].pb(a[ist][i][0]);
    }

    if (!buildTopSort()) {
      continue;
    }

    for (int i = 0; i < maxc; ++i) {
      go[i] = Set();
    }
    for (int i = cnt - 1; i >= 0; --i) {
      int v = perm[cnt - 1 - i];
      Set &cur = go[col[v]];
      cur.a[v >> 5] |= (1u << (v & 31));
      for (int it = 0; it < sz(es[v]); ++it) {
        int u = es[v][it];
        cur |= go[col[u]];
      }
    }

    for (int j1 = 0; j1 < m[!ist]; ++j1) {
      int s = a[!ist][j1][0];
      int t = a[!ist][j1][1];
      s ^= 1, t ^= 1;
      if (go[col[s]].get(s ^ 1) || go[col[s]].get(t ^ 1) || go[col[t]].get(s ^ 1) || go[col[t]].get(t ^ 1)) {
        continue;
      }

      es[s ^ 1].pb(s);
      es[t ^ 1].pb(t);
      assert(buildTopSort());
      for (int i = 0; i < n; ++i) {
        ans[i] = (col[2 * i] > col[2 * i + 1]);
        printf("%d%c", ans[i], " \n"[i == n - 1]);
        //eprintf("%d%c", ans[i], " \n"[i == n - 1]);
      }

#ifdef DEBUG
      for (int iter = 0; iter < 2; ++iter) {
        int res = 1;
        for (int i = 0; i < m[iter]; ++i) {
          int val = ((ans[a[iter][i][0] / 2] ^ (a[iter][i][0] & 1)) || (ans[a[iter][i][1] / 2] ^ (a[iter][i][1] & 1)));
          if (!val) {
            res = 0;
            break;
          }
        }
        //eprintf("%d: %d\n", iter, res);
        //eprintf("ist = %d\n", ist);
        assert(res == (iter == ist));
      }
#endif
      return;
    }
  }
  printf("SIMILAR\n");
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}