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

template <typename T>
struct Dinic {
  struct Edge {
    int dst, rev;
    T cap;
    Edge(int dst, T cap, int rev) : dst(dst), cap(cap), rev(rev) {}
  };

  vector<vector<Edge>> graph;

  Dinic(int n) : graph(n), level(n), itr(n) {}

  void add_edge(int src, int dst, T cap) {
    graph[src].emplace_back(dst, cap, graph[dst].size());
    graph[dst].emplace_back(src, 0, graph[src].size() - 1);
  }

  T maximum_flow(int s, int t, T limit) {
    T res = 0;
    while (true) {
      bfs(s);
      if (level[t] == -1) return res;
      fill(ALL(itr), 0);
      T tmp;
      while ((tmp = dfs(s, t, limit)) > 0) res += tmp;
    }
  }

private:
  vector<int> level, itr;

  void bfs(int s) {
    fill(ALL(level), -1);
    queue<int> que;
    level[s] = 0;
    que.emplace(s);
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      for (const Edge &e : graph[ver]) {
        if (level[e.dst] == -1 && e.cap > 0) {
          level[e.dst] = level[ver] + 1;
          que.emplace(e.dst);
        }
      }
    }
  }

  T dfs(int ver, int t, T flow) {
    if (ver == t) return flow;
    for (; itr[ver] < graph[ver].size(); ++itr[ver]) {
      Edge &e = graph[ver][itr[ver]];
      if (level[ver] < level[e.dst] && e.cap > 0) {
        T tmp = dfs(e.dst, t, min(flow, e.cap));
        if (tmp > 0) {
          e.cap -= tmp;
          graph[e.dst][e.rev].cap += tmp;
          return tmp;
        }
      }
    }
    return 0;
  }
};

template <template <typename> class C, typename T>
struct ProjectSelectionProblem {
  ProjectSelectionProblem(int n, const T TINF) : n(n), TINF(TINF) {}

  void add_diff(int u, int v, T cost) {
    assert(cost >= 0);
    diff_u.emplace_back(u);
    diff_v.emplace_back(v);
    diff_cost.emplace_back(cost);
  }

  void add_same(int u, int v, int group, T cost) {
    assert(cost <= 0);
    cost = -cost;
    res += cost;
    add(n, group ^ 1, cost);
    if (group == 0) {
      add_diff(n, u, TINF);
      add_diff(n, v, TINF);
    } else if (group == 1) {
      add_diff(u, n, TINF);
      add_diff(v, n, TINF);
    }
    ++n;
  }

  void add(int ver, int group, T cost) {
    if (cost < 0) {
      cost = -cost;
      res += cost;
      add(ver, group ^ 1, cost);
    } else {
      if (group == 0) {
        add_diff(ver, -1, cost);
      } else {
        add_diff(-2, ver, cost);
      }
    }
  }

  T solve() {
    C<T> flow(n + 2);
    int sz = diff_u.size();
    REP(i, sz) {
      if (diff_u[i] < 0) diff_u[i] += n + 2;
      if (diff_v[i] < 0) diff_v[i] += n + 2;
      flow.add_edge(diff_u[i], diff_v[i], diff_cost[i]);
    }
    sz = same_u.size();
    REP(i, sz) {
      if (same_u[i] < 0) same_u[i] += n + 2;
      if (same_v[i] < 0) same_v[i] += n + 2;
      flow.add_edge(same_u[i], same_v[i], same_cost[i]);
    }
    return flow.maximum_flow(n, n + 1, TINF) - res;
  }

private:
  int n;
  const T TINF;
  T res = 0;
  vector<int> diff_u, diff_v, same_u, same_v;
  vector<T> diff_cost, same_cost;
};

int main() {
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector idx(n, vector(m, -1));
  int x = 0;
  REP(i, n) REP(j, m) {
    if (s[i][j] == '#') idx[i][j] = x++;
  }
  ProjectSelectionProblem<Dinic, int> psp(x, INF);
  REP(i, n) REP(j, m) {
    if (idx[i][j] == -1) continue;
    if (i + 1 < n && idx[i + 1][j] != -1) psp.add_same(idx[i][j], idx[i + 1][j], 0, -1);
    if (j + 1 < m && idx[i][j + 1] != -1) psp.add_same(idx[i][j], idx[i][j + 1], 1, -1);
  }
  cout << x + psp.solve() << '\n';
  return 0;
}