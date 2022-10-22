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
struct WarshallFloyd {
  vector<vector<T> > graph, dist;

  WarshallFloyd(const vector<vector<T> > &graph, T TINF) : graph(graph), TINF(TINF) {
    n = graph.size();
    dist = graph;
    internal.assign(n, vector<int>(n, -1));
    REP(k, n) REP(i, n) REP(j, n) {
      if (dist[i][k] != TINF && dist[k][j] != TINF && dist[i][j] > dist[i][k] + dist[k][j]) {
        dist[i][j] = dist[i][k] + dist[k][j];
        internal[i][j] = k;
      }
    }
  }

  void add(int src, int dst, T cost) {
    srcs.emplace_back(src);
    dsts.emplace_back(dst);
    costs.emplace_back(cost);
  }

  void calc() {
    set<int> ver;
    int sz = srcs.size();
    REP(i, sz) {
      int s = srcs[i], t = dsts[i];
      T cost = costs[i];
      graph[s][t] = min(graph[s][t], cost);
      if (dist[s][t] >= cost) {
        dist[s][t] = cost;
        internal[s][t] = -1;
      }
      ver.insert(s);
      ver.insert(t);
    }
    for (int v : ver) {
      REP(i, n) REP(j, n) {
        if (dist[i][v] != TINF && dist[v][j] != TINF && dist[i][j] > dist[i][v] + dist[v][j]) {
          dist[i][j] = dist[i][v] + dist[v][j];
          internal[i][j] = v;
        }
      }
    }
    srcs.clear();
    dsts.clear();
    costs.clear();
  }

  bool has_negative_cycle() {
    REP(i, n) if (dist[i][i] < 0) return true;
    return false;
  }

  vector<int> build_path(int s, int t) {
    vector<int> res;
    if (dist[s][t] != TINF) {
      build_path(s, t, res);
      res.emplace_back(t);
    }
    return res;
  }

private:
  const T TINF;
  int n;
  vector<vector<int> > internal;
  vector<int> srcs, dsts;
  vector<T> costs;

  void build_path(int s, int t, vector<int> &path) {
    int k = internal[s][t];
    if (k == -1) path.emplace_back(s);
    else {
      build_path(s, k, path);
      build_path(k, t, path);
    }
  }
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<vector<int> > graph(n, vector<int>(n, INF));
  REP(i, n) graph[i][i] = 0;
  REP(i, n) REP(j, n) {
    char c; cin >> c;
    if (c == '1') graph[i][j] = 1;
  }
  WarshallFloyd<int> wf(graph, INF);
  int m; cin >> m;
  vector<int> p(m);
  REP(i, m) {
    cin >> p[i]; --p[i];
  }
  vector<int> ans{p[0]};
  int now = 0;
  FOR(i, 2, m) {
    // cout << now << ' ' << i << '|' << wf.dist[p[now]][p[i]] << '\n';
    if (wf.dist[p[now]][p[i]] < i - now) {
      ans.emplace_back(p[i - 1]);
      now = i - 1;
    }
  }
  ans.emplace_back(p[m - 1]);
  cout << ans.size() << '\n';
  REP(i, ans.size()) cout << ans[i] + 1 << (i + 1 == ans.size() ? '\n' : ' ');
  return 0;
}