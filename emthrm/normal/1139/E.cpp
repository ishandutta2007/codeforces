#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
template <typename T>
struct Dinic {
  struct Edge {
    int dst, rev;
    T cap;
    Edge(int dst, T cap, int rev) : dst(dst), cap(cap), rev(rev) {}
  };

  vector<vector<Edge> > graph;

  Dinic(int n) : graph(n), level(n), itr(n) {}

  void add_edge(int src, int dst, T cap) {
    graph[src].emplace_back(Edge(dst, cap, graph[dst].size()));
    graph[dst].emplace_back(Edge(src, 0, graph[src].size() - 1));
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
      for (Edge e : graph[ver]) if (level[e.dst] == -1 && e.cap > 0) {
        level[e.dst] = level[ver] + 1;
        que.emplace(e.dst);
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

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<int> p(n), c(n);
  REP(i, n) cin >> p[i];
  REP(i, n) {
    cin >> c[i]; --c[i];
  }
  vector<bool> can(n, true);
  int d; cin >> d;
  vector<int> k(d);
  REP(i, d) {
    cin >> k[i]; --k[i];
    can[k[i]] = false;
  }
  Dinic<int> dinic(m + 5001 + 2);
  REP(i, m) dinic.add_edge(m + 5001, i, 1);
  REP(i, n) if (can[i]) {
    dinic.add_edge(c[i], m + p[i], 1);
  }
  dinic.add_edge(m, m + 5001 + 1, 1);
  vector<int> ans(d);
  for (int i = d - 1; i >= 0; --i) {
    ans[i] = (i + 1 == d ? 0 : ans[i + 1]);
    while (dinic.maximum_flow(m + 5001, m + 5001 + 1, 1) == 1) {
      ++ans[i];
      dinic.add_edge(m + ans[i], m + 5001 + 1, 1);
    }
    dinic.add_edge(c[k[i]], m + p[k[i]], 1);
  }
  REP(i, d) cout << ans[i] << '\n';
  return 0;
}