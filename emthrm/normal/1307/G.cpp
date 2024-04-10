#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T, typename U>
struct PrimalDual {
  using Pui = pair<U, int>;

  struct Edge {
    int dst, rev;
    T cap;
    U cost;
    Edge(int dst, T cap, U cost, int rev) : dst(dst), cap(cap), cost(cost), rev(rev) {}
  };

  vector<vector<Edge> > graph;

  PrimalDual(int n, const T TINF, const U UINF) : n(n), TINF(TINF), UINF(UINF), graph(n), prev_v(n, -1), prev_e(n, -1), potential(n, 0), dist(n) {}

  void add_edge(int src, int dst, T cap, U cost) {
    has_negative_edge |= cost < 0;
    graph[src].emplace_back(dst, cap, cost, graph[dst].size());
    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);
  }

  U minimum_cost_flow(int s, int t, T flow) {
    U res = 0;
    if (has_negative_edge) {
      bellman_ford(s);
      if (dist[t] == UINF) return UINF;
      res += calc(s, t, flow);
    }
    while (flow > 0) {
      dijkstra(s);
      if (dist[t] == UINF) return UINF;
      res += calc(s, t, flow);
    }
    return res;
  }

  U minimum_cost_flow(int s, int t) {
    U res = 0;
    bellman_ford(s);
    if (potential[t] >= 0 || dist[t] == UINF) return res;
    T tmp = TINF;
    res += calc(s, t, tmp);
    while (true) {
      dijkstra(s);
      if (potential[t] >= 0 || dist[t] == UINF) return res;
      res += calc(s, t, tmp);
    }
  }

  pair<T, U> min_cost_max_flow(int s, int t, T flow) {
    T mx = flow;
    U cost = 0;
    if (has_negative_edge) {
      bellman_ford(s);
      if (dist[t] == UINF) return {mx - flow, cost};
      cost += calc(s, t, flow);
    }
    while (flow > 0) {
      dijkstra(s);
      if (dist[t] == UINF) return {mx - flow, cost};
      cost += calc(s, t, flow);
    }
    return {mx - flow, cost};
  }

// private:
  int n;
  const T TINF;
  const U UINF;
  bool has_negative_edge = false;
  vector<int> prev_v, prev_e;
  vector<U> potential, dist;
  priority_queue<Pui, vector<Pui>, greater<Pui> > que;

  void bellman_ford(int s) {
    fill(ALL(dist), UINF);
    dist[s] = 0;
    bool is_updated = true;
    REP(step, n) {
      is_updated = false;
      REP(i, n) if (dist[i] != UINF) {
        REP(j, graph[i].size()) {
          Edge e = graph[i][j];
          if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {
            dist[e.dst] = dist[i] + e.cost;
            prev_v[e.dst] = i;
            prev_e[e.dst] = j;
            is_updated = true;
          }
        }
      }
      if (!is_updated) break;
    }
    assert(!is_updated);
    REP(i, n) {
      if (dist[i] != UINF) potential[i] += dist[i];
    }
  }

  void dijkstra(int s) {
    fill(ALL(dist), UINF);
    dist[s] = 0;
    que.emplace(0, s);
    while (!que.empty()) {
      Pui pr = que.top(); que.pop();
      int ver = pr.second;
      if (dist[ver] < pr.first) continue;
      REP(i, graph[ver].size()) {
        Edge e = graph[ver][i];
        U nx = dist[ver] + e.cost + potential[ver] - potential[e.dst];
        if (e.cap > 0 && dist[e.dst] > nx) {
          dist[e.dst] = nx;
          prev_v[e.dst] = ver;
          prev_e[e.dst] = i;
          que.emplace(dist[e.dst], e.dst);
        }
      }
    }
    REP(i, n) {
      if (dist[i] != UINF) potential[i] += dist[i];
    }
  }

  U calc(int s, int t, T &flow) {
    T f = flow;
    for (int v = t; v != s; v = prev_v[v]) f = min(f, graph[prev_v[v]][prev_e[v]].cap);
    flow -= f;
    for (int v = t; v != s; v = prev_v[v]) {
      Edge &e = graph[prev_v[v]][prev_e[v]];
      e.cap -= f;
      graph[v][e.rev].cap += f;
    }
    return potential[t] * f;
  }
};

template <typename T>
struct LiChaoTree {
  struct Line {
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    T f(T x) { return a * x + b; }
  };

  LiChaoTree(const vector<T> &xs_, const T TINF, bool is_minimized = true) : xs(xs_), is_minimized(is_minimized) {
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    int sz = xs.size();
    assert(sz > 0);
    while (n < sz) n <<= 1;
    xs.resize(n, xs.back());
    Line unity(0, TINF);
    dat.assign(n << 1, unity);
  }

  void add(T a, T b) {
    if (!is_minimized) {
      a = -a;
      b = -b;
    }
    Line line(a, b);
    add(line, 1, 0, n);
  }

  void add(T a, T b, T left, T right) {
    if (!is_minimized) {
      a = -a;
      b = -b;
    }
    int l = lower_bound(ALL(xs), left) - xs.begin(), r = lower_bound(ALL(xs), right) - xs.begin();
    int len, node_l = l, node_r = r;
    for (l += n, r += n, len = 1; l < r; l >>= 1, r >>= 1, len <<= 1) {
      if (l & 1) {
        Line line(a, b);
        add(line, l++, node_l, node_l + len);
        node_l += len;
      }
      if (r & 1) {
        Line line(a, b);
        node_r -= len;
        add(line, --r, node_r, node_r + len);
      }
    }
  }

  T query(T x) {
    int node = lower_bound(ALL(xs), x) - xs.begin();
    node += n;
    T res = dat[node].f(x);
    while (node >>= 1) chmin(res, dat[node].f(x));
    return is_minimized ? res : -res;
  }

private:
  bool is_minimized;
  int n = 1;
  vector<T> xs;
  vector<Line> dat;

  void add(Line &line, int node, int left, int right) {
    bool l = dat[node].f(xs[left]) <= line.f(xs[left]), r = dat[node].f(xs[right - 1]) <= line.f(xs[right - 1]);
    if (l && r) return;
    if (!l && !r) {
      swap(dat[node], line);
      return;
    }
    int mid = (left + right) >> 1;
    if (line.f(xs[mid]) < dat[node].f(xs[mid])) swap(dat[node], line);
    if (line.f(xs[left]) <= dat[node].f(xs[left])) {
      add(line, node << 1, left, mid);
    } else {
      add(line, (node << 1) + 1, mid, right);
    }
  }
};

int main() {
  int n, m; cin >> n >> m;
  PrimalDual<int, ll> pd(n, INF, LINF);
  while (m--) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    pd.add_edge(u, v, 1, w);
  }
  int q; cin >> q;
  vector<double> x(q); REP(i, q) cin >> x[i];
  LiChaoTree<double> lct(x, LINF);
  int flow = 0;
  ll cost = 0;
  while (true) {
    pd.dijkstra(0);
    if (pd.dist[n - 1] == LINF) break;
    int nx = INF;
    cost += pd.calc(0, n - 1, nx);
    flow += INF - nx;
    lct.add(1.0 / flow, 1.0 * cost / flow);
  }
  REP(i, q) cout << lct.query(x[i]) << '\n';
  return 0;
}