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
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int INF = (int)1e9 + 1;
const ld EPS = 1e-9;

struct Graph {
  vector<vector<int> > es, fs, cs, inv;
  int n;

  Graph(int _n = 0) : n(_n) {
    es = inv = fs = cs = vector<vector<int> >(n);
    its = dist = st = vector<int>(n);
  }

  void reset() {
    for (int i = 0; i < n; ++i) {
      memset(&(fs[i][0]), 0, sizeof(fs[i][0]) * sz(fs[i]));
    }
  }

  void adde(int s, int t, int c) {
    es[s].pb(t), es[t].pb(s);
    inv[s].pb(sz(es[t]) - 1), inv[t].pb(sz(es[s]) - 1);
    fs[s].pb(0), fs[t].pb(0);
    cs[s].pb(c), cs[t].pb(c);
  }

  vector<int> its, dist, st;

  int dfs(int v, int T, int cur = INF) {
    if (v == T) {
      return cur;
    }
    int ans = 0;
    for (int &it = its[v]; it < sz(es[v]); ++it) {
      int u = es[v][it];
      if (dist[u] == dist[v] + 1 && cs[v][it] - fs[v][it]) {
        int value = dfs(u, T, min(cur, cs[v][it] - fs[v][it]));
        if (value > 0) {
          fs[v][it] += value;
          fs[u][inv[v][it]] -= value;
          ans += value;
          cur -= value;
          if (cur == 0) {
            break;
          }
        }
      }
    }
    return ans;
  }

  int flow(int S, int T) {
    int res = 0;
    while (1) {
      for (int i = 0; i < n; ++i) {
        dist[i] = INF;
      }

      st[0] = S;
      dist[S] = 0;

      for (int l = 0, r = 1; l < r; ++l) {
        int v = st[l];
        for (int it = 0; it < sz(es[v]); ++it) {
          int u = es[v][it];
          if (dist[u] > dist[v] + 1 && cs[v][it] - fs[v][it]) {
            dist[u] = dist[v] + 1;
            st[r++] = u;
          }
        }
      }

      if (dist[T] == INF) {
        break;
      }

      memset(&(its[0]), 0, sizeof(int) * n);
      while (1) {
        int tmp;
        if ((tmp = dfs(S, T)) == 0) {
          break;
        }
        res += tmp;
      }
    }
    return res;
  }

  vector<vector<int> > prec;

  void buildTree() {
    vector<int> p(n, 0);
    prec = vector<vector<int> > (n, vector<int> (n, INF));
    for (int i = 1; i < n; i++) {
      auto wasfs = fs;
      int f = flow(i, p[i]);
      /*eprintf("i = %d p[i] = %d f = %d\n", i, p[i], f);
      for (int j = 0; j < n; j++) {
        eprintf("%d%c", p[j], " \n"[j == n - 1]);
      }*/
      for (int j = i + 1; j < n; j++) {
        if (dist[j] < INF && p[j] == p[i]) {
          p[j] = i;
        }
      }
      prec[p[i]][i] = prec[i][p[i]] = f;
      for (int j = 0; j < i; j++) {
        prec[i][j] = prec[j][i] = min(prec[j][p[i]], f);
      }
      fs = wasfs;
    }
    for (int i = 0; i < n; i++) {
      prec[i][i] = 0;
    }
    /*for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        eprintf("%d%c", prec[i][j], " \n"[j == n - 1]);
      }
    }*/
  }

  int fastFlow(int S, int T) {
    return prec[S][T];
  }
};

const int maxn = 200 + 10;
int dist[maxn][maxn];
int used[maxn];


bool solve() {
  int n, m;
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }

  Graph g(n);

  for (int i = 0; i < m; ++i) {
    int s, t, c;
    scanf("%d%d%d", &s, &t, &c);
    --s, --t;
    g.adde(s, t, c);
  }

  g.buildTree();

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      dist[j][i] = dist[i][j] = g.fastFlow(i, j);
      //eprintf("dist[%d][%d] = %d\n", i, j, dist[i][j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    used[i] = 0;
  }
  vector<int> ans;
  int res = 0;
  for (int v = 0, iter = 0; iter < n; ++iter) {
    ans.pb(v);
    used[v] = 1;
    if (iter == n - 1) {
      break;
    }
    int best = -1, bestv = -1;
    for (int u = 0; u < n; ++u) {
      if (!used[u] && best < dist[v][u]) {
        best = dist[v][u];
        bestv = u;
      }
    }
    assert(bestv != -1);
    res += best;
    v = bestv;
  }

  printf("%d\n", res);
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
  }
  return 1;
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  while (1) {
    if (!solve()) {
      break;
    }
#ifdef DEBUG
    eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}