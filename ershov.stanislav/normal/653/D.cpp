#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

namespace Flow {
  const static long long inff = (ll) 1e18;
  struct Edge {
    int t;
    ll f, c;
 
    Edge() {}
    Edge(int _t, ll _f, ll _c) : t(_t), f(_f), c(_c) {}
  };
 
  struct Graph {
    vector<Edge> edges;
   
    int n;
    vector<vector<int> > es;
 
    Graph(int _n = 0, int _m = 0) : n(_n), es(_n) {
      edges.reserve(_m);
      edges.clear();
 
      st.reserve(n);
      dist.reserve(n);
      its.reserve(n);
    }
 
    void adde(int s, int t, ll c, ll c2 = 0) {
      assert(0 <= s && s < n);
      assert(0 <= t && t < n);
      es[s].pb(sz(edges));
      edges.pb(Edge(t, 0, c));
      es[t].pb(sz(edges));
      edges.pb(Edge(s, 0, c2));
    }
 
    vector<int> st, its;
    vector<ll> dist;
 
    ll dfs(int v, int T, ll maxPush) {
      if (v == T) {
        return maxPush;
      }
      ll res = 0;
      for (int &it = its[v]; it < sz(es[v]); ++it) {
        int eid = es[v][it];
        Edge &e = edges[eid];
        if (e.c == e.f) {
          continue;
        }
        int u = e.t;
        if (dist[u] != dist[v] + 1) {
          continue;
        }
        ll push = dfs(u, T, min(maxPush, e.c - e.f));
        if (push) {
          res += push;
          maxPush -= push;
          e.f += push;
          edges[eid ^ 1].f -= push;
          if (maxPush == 0) {
            break;
          }
        }
      }
      return res;
    }
 
    ll dinic(int S, int T) {
      its.resize(n);
      dist.resize(n);
 
      ll res = 0;
      while (1) {
        for (int i = 0; i < n; ++i) {
          dist[i] = inff;
        }
        dist[S] = 0;
        st.clear();
        st.pb(S);
        for (int l = 0; l < sz(st); ++l) {
          int v = st[l];
          for (int eid : es[v]) {
            Edge &e = edges[eid];
            if (e.f == e.c) {
              continue;
            }
            int u = e.t;
            if (dist[u] <= dist[v] + 1) {
              continue;
            }
            dist[u] = dist[v] + 1;
            st.pb(u);
          }
        }
 
        if (dist[T] == inff) {
          break;
        }
 
        for (int i = 0; i < n; ++i) {
          its[i] = 0;
        }
        while (1) {
          ll push = dfs(S, T, inff);
          if (!push) {
            break;
          }
          res += push;
        }
      }
      return res;
    }
  };
};

const int maxn = 5e5;
int n, m;
int x;
vector<pair<int, int> > graph;
vector<int> c;

bool read() {
  if (scanf("%d%d%d", &n, &m, &x) < 3) {
    return false;
  }
  graph = vector<pair<int, int> > ();
  c = vector<int> ();
  for (int i = 0; i < m; i++) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    graph.eb(a - 1, b - 1);
    c.pb(d);
  }
  return true;
}

void solve() {
  ld l = 0, r = inf;
  for (int it = 0; it < 100; it++) {
    ld mid = (l + r) / 2;
    Flow::Graph g(n);
    for (int i = 0; i < m; i++) {
      g.adde(graph[i].first, graph[i].second, (ll) floor(c[i] / (mid / x)));
    }
    if (g.dinic(0, n - 1) < x) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.18f\n", (double) l);
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}