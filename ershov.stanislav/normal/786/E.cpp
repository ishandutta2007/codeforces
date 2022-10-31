#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

void precalc() {
}

struct Edge {
  int from, to;
  int f, c;

  Edge() {}
  Edge(int from, int to, int f, int c) : from(from), to(to), f(f), c(c) {}
};

struct Graph {
  vector<Edge> edges;
  vector<vector<int> > es;
  int n, m;

  Graph(int _n = 0, int _m = 0) : n(_n), m(_m) {
    es = vector<vector<int> > (n);
    edges.clear();
    edges.reserve(m);
  }

  void adde(int from, int to, int c) {
    eprintf("from = %d, to = %d, c = %d\n", from, to, c);
    es[from].pb(sz(edges));
    edges.pb(Edge(from, to, 0, c));
    es[to].pb(sz(edges));
    edges.pb(Edge(to, from, 0, 0));
  }

  vector<int> its, dist;

  int dfs(int v, int T, int maxpush) {
    if (v == T) {
      return maxpush;
    }
    int sum = 0;
    for (int & i = its[v]; i < sz(es[v]); i++) {
      Edge & e = edges[es[v][i]];
      if (e.f == e.c || dist[e.to] != dist[e.from] + 1) {
        continue;
      }
      int got = dfs(e.to, T, min(maxpush, e.c - e.f));
      if (!got) {
        continue;
      }
      sum += got;
      e.f += got;
      edges[es[v][i] ^ 1].f -= got;
      maxpush -= got;
      if (!maxpush) {
        break;
      }
    }
    return sum;
  }

  ll dinic(int S, int T) {
    ll res = 0;
    while (true) {
      dist = vector<int> (n, inf);
      dist[S] = 0;
      vector<int> st(1, S);
      for (int l = 0; l < sz(st); l++) {
        int cur = st[l];
        for (int i = 0; i < sz(es[cur]); i++) {
          Edge & e = edges[es[cur][i]];
          if (e.f == e.c) {
            continue;
          }
          if (dist[e.to] > dist[cur] + 1) {
            dist[e.to] = dist[cur] + 1;
            st.pb(e.to);
          }
        }
      }

      if (dist[T] == inf) {
        break;
      }

      its = vector<int> (n);
      while (true) {
        int got = dfs(S, T, inf);
        if (!got) {
          break;
        }
        res += got;
      }
    }
    return res;
  }
} g;

const int maxn = 3e4;

int n, m;
vector<vector<int> > tree;
vector<vector<int> > ids;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  tree.clear();
  tree.resize(n);
  ids.clear();
  ids.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
    ids[u].pb(i);
    ids[v].pb(i);
  }
  return true;
}

int id[maxn];
int tin[maxn], tout[maxn], curt;
const int maxk = 15;
int up[maxk][maxn];

void dfs(int v, int par) {
  tin[v] = curt++;
  up[0][v] = par;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    id[to] = ids[v][i];
    dfs(to, v);
  }
  tout[v] = curt;
}

bool isanc(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

void solve() {
  curt = 0;
  dfs(0, 0);
  g = Graph(2 + m + maxk * n);
  for (int i = 0; i < m; i++) {
    g.adde(0, 2 + i, 1);
  }
  for (int i = 0; i < n; i++) {
    g.adde(2 + m + i, 1, 1);
  }
  for (int i = 0; i + 1 < maxk; i++) {
    for (int j = 0; j < n; j++) {
      up[i + 1][j] = up[i][up[i][j]];
      g.adde(2 + m + (i + 1) * n + j, 2 + m + i * n + j, inf);
      g.adde(2 + m + (i + 1) * n + j, 2 + m + i * n + up[i][j], inf);
    }
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    for (int it = 0; it < 2; it++) {
      for (int j = maxk - 1; j >= 0; j--) {
        if (!isanc(up[j][x], y)) {
          g.adde(i + 2, 2 + m + j * n + x, inf);
          x = up[j][x];
        }
      }
      if (!isanc(x, y)) {
        g.adde(i + 2, 2 + m + x, inf);
        x = up[0][x];
      }
      swap(x, y);
    }
  }
  int res = g.dinic(0, 1);
  vector<int> edges;
  vector<int> citizens;
  for (int i = 0; i < m; i++) {
    if (g.dist[i + 2] == inf) {
      citizens.pb(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (g.dist[2 + m + i] < inf) {
      assert(i);
      edges.pb(id[i]);
    }
  }
  printf("%d\n", res);
  printf("%d ", sz(citizens));
  for (int i = 0; i < sz(citizens); i++) {
    printf("%d%c", citizens[i] + 1, " \n"[i == sz(citizens) - 1]);
  }
  printf("%d ", sz(edges));
  for (int i = 0; i < sz(edges); i++) {
    printf("%d%c", edges[i] + 1, " \n"[i == sz(edges) - 1]);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}