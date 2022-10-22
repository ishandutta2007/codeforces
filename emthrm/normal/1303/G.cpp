#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

using CostType = ll;
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost : dst != rhs.dst ? dst < rhs.dst : src < rhs.src;
  }
  inline bool operator<=(const Edge &rhs) const { return !(rhs < *this); }
  inline bool operator>(const Edge &rhs) const { return rhs < *this; }
  inline bool operator>=(const Edge &rhs) const { return !(*this < rhs); }
};

struct CentroidDecomposition {
  int root;
  vector<vector<int> > comp;
  vector<int> par;

  CentroidDecomposition(const vector<vector<Edge> > &graph) : graph(graph) {
    int n = graph.size();
    alive.assign(n, true);
    subtree.resize(n);
    comp.resize(n);
    par.assign(n, -1);
    root = build(0);
  }

private:
  const vector<vector<Edge> > graph;
  vector<bool> alive;
  vector<int> subtree;

  int build(int s) {
    int centroid = search_centroid(-1, s, calc_subtree(-1, s) / 2);
    alive[centroid] = false;
    for (const Edge &e : graph[centroid]) {
      if (alive[e.dst]) {
        comp[centroid].emplace_back(build(e.dst));
        par[e.dst] = centroid;
      }
    }
    alive[centroid] = true;
    return centroid;
  }

  int calc_subtree(int par, int ver) {
    subtree[ver] = 1;
    for (const Edge &e : graph[ver]) {
      if (e.dst != par && alive[e.dst]) subtree[ver] += calc_subtree(ver, e.dst);
    }
    return subtree[ver];
  }

  int search_centroid(int par, int ver, int half) {
    for (const Edge &e : graph[ver]) {
      if (e.dst != par && alive[e.dst]) {
        if (subtree[e.dst] > half) return search_centroid(ver, e.dst, half);
      }
    }
    return ver;
  }
};

template <typename T>
struct LiChaoTree {
  struct Line {
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    T f(T x) { return a * x + b; }
  };

  LiChaoTree(const vector<T> &xs_, const T TINF, bool is_minimized = true) : xs(xs_), TINF(TINF), is_minimized(is_minimized) {
    sort(ALL(xs));
    unique(xs);
    int sz = xs.size();
    while (n < sz) n <<= 1;
    xs.resize(n, TINF);
    Line unity(0, is_minimized ? TINF : -TINF);
    dat.assign(n << 1, unity);
  }

  void add(T a, T b) {
    Line line(a, b);
    add(line, 1, 0, n);
  }

  void add(T a, T b, T left, T right) {
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
    while (node >>= 1) {
      if (is_minimized) {
        chmin(res, dat[node].f(x));
      } else {
        chmax(res, dat[node].f(x));
      }
    }
    return res;
  }

private:
  const T TINF;
  bool is_minimized;
  int n = 1;
  vector<T> xs;
  vector<Line> dat;

  void add(Line &line, int node, int left, int right) {
    bool l = dat[node].f(xs[left]) <= line.f(xs[left]), r = dat[node].f(xs[right - 1]) <= line.f(xs[right - 1]);
    if (l && r) {
      if (!is_minimized) swap(dat[node], line);
      return;
    }
    if (!l && !r) {
      if (is_minimized) swap(dat[node], line);
      return;
    }
    int mid = (left + right) >> 1;
    bool m = line.f(xs[mid]) < dat[node].f(xs[mid]);
    if (is_minimized) {
      if (m) swap(dat[node], line);
    } else {
      if (!m) swap(dat[node], line);
    }
    if (line.f(xs[left]) <= dat[node].f(xs[left])) {
      if (is_minimized) {
        add(line, node << 1, left, mid);
      } else {
        add(line, (node << 1) + 1, mid, right);
      }
    } else {
      if (is_minimized) {
        add(line, (node << 1) + 1, mid, right);
      } else {
        add(line, node << 1, left, mid);
      }
    }
  }
};

int main() {
  int n; cin >> n;
  vector<vector<Edge> > graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(u, v);
    graph[v].emplace_back(v, u);
  }
  vector<int> a(n); REP(i, n) cin >> a[i];
  CentroidDecomposition cent(graph);
  vector<bool> visited(n, false);
  ll ans = 0;
  function<void(int)> dfs = [&](int root) {
    visited[root] = true;
    chmax(ans, a[root]);
    vector<vector<ll> > sum_a, psum_a;
    vector<vector<pair<ll, int> > > psum_b;
    function<void(int, int, int, ll, ll, ll, int)> dfs2 = [&](int par, int ver, int idx, ll sum, ll A, ll B, int len) {
      sum += a[ver];
      A += 1LL * a[ver] * len;
      B += sum - a[root];
      bool leaf = true;
      for (const Edge &e : graph[ver]) {
        if (e.dst == par || visited[e.dst]) continue;
        dfs2(ver, e.dst, idx, sum, A, B, len + 1);
        leaf = false;
      }
      if (leaf) {
        sum_a[idx].emplace_back(sum);
        psum_a[idx].emplace_back(A);
        psum_b[idx].emplace_back(B, len - 1);
      }
    };
    for (const Edge &e : graph[root]) {
      if (visited[e.dst]) continue;
      int sz = sum_a.size();
      sum_a.emplace_back();
      psum_a.emplace_back();
      psum_b.emplace_back();
      dfs2(-1, e.dst, sz, a[root], a[root], 0, 2);
    }
    int m = sum_a.size();
    vector<ll> xs;
    REP(i, m) {
      for (ll e : sum_a[i]) xs.emplace_back(e);
      for (ll e : psum_a[i]) chmax(ans, e);
      for (auto pr : psum_b[i]) chmax(ans, pr.first + 1LL * a[root] * (pr.second + 1));
    }
    if (!xs.empty()) {
      sort(ALL(xs));
      unique(xs);
      LiChaoTree<ll> lct1(xs, LINF, false);
      REP(i, m) {
        int sz = sum_a[i].size();
        REP(j, sz) chmax(ans, lct1.query(sum_a[i][j]) + psum_a[i][j]);
        REP(j, sz) lct1.add(psum_b[i][j].second, psum_b[i][j].first);
      }
      LiChaoTree<ll> lct2(xs, LINF, false);
      for (int i = m - 1; i >= 0; --i) {
        int sz = sum_a[i].size();
        REP(j, sz) chmax(ans, lct2.query(sum_a[i][j]) + psum_a[i][j]);
        REP(j, sz) lct2.add(psum_b[i][j].second, psum_b[i][j].first);
      }
    }
    for (int e : cent.comp[root]) dfs(e);
  };
  dfs(cent.root);
  cout << ans << '\n';
  return 0;
}