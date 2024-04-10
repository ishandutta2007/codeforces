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
#include <numeric>
#include <queue>
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
struct SCC {
  vector<int> id;
  // vector<vector<int> > vertices, comp;

  SCC(const vector<vector<int> > &graph) : graph(graph) {
    n = graph.size();
    rev_graph.resize(n);
    REP(i, n) for (int e : graph[i]) {
      rev_graph[e].emplace_back(i);
    }
    used.assign(n, false);
    id.assign(n, -1);
    REP(i, n) {
      if (!used[i]) dfs(i);
    }
    int now = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (id[order[i]] == -1) {
        // vertices.emplace_back();
        rev_dfs(order[i], now++);
      }
    }
    // comp.resize(now);
    // REP(i, n) for (int e : graph[i]) {
    //   if (id[i] != id[e]) comp[id[i]].emplace_back(id[e]);
    // }
    // REP(i, now) sort(ALL(vertices[i]));
  }

private:
  int n;
  vector<vector<int> > graph, rev_graph;
  vector<bool> used;
  vector<int> order;

  void dfs(int ver) {
    used[ver] = true;
    for (int e : graph[ver]) {
      if (!used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    // vertices[now].emplace_back(ver);
    for (int e : rev_graph[ver]) {
      if (id[e] == -1) rev_dfs(e, now);
    }
  }
};

struct TwoSat {
  TwoSat(int n) : n(n) { graph.resize(n * 2); }

  int negate(int x) { return (n + x) % (n * 2); }

  void add_or(int x, int y) {
    graph[negate(x)].emplace_back(y);
    graph[negate(y)].emplace_back(x);
  }

  void add_if(int x, int y) { add_or(negate(x), y); }

  void add_nand(int x, int y) { add_or(negate(x), negate(y)); }

  void set_true(int x) { add_or(x, x); }

  void set_false(int x) { set_true(negate(x)); }

  vector<bool> build() {
    SCC scc(graph);
    vector<bool> res(n);
    REP(i, n) {
      if (scc.id[i] == scc.id[negate(i)]) return {};
      res[i] = scc.id[negate(i)] < scc.id[i];
    }
    return res;
  }

private:
  int n;
  vector<vector<int> > graph;
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<vector<int> > squ(n, vector<int>(n));
  REP(i, n) REP(j, n) {
    char c; cin >> c;
    squ[i][j] = c - '0';
  }
  REP(i, n) REP(j, n) {
    char c; cin >> c;
    squ[i][j] ^= c - '0';
  }
  vector<int> bar(n);
  REP(i, n) {
    char c; cin >> c;
    bar[i] = c - '0';
  }
  TwoSat ts(n + n);
  REP(i, n) REP(j, n) {
    if (squ[i][j] == 0) {
      if (bar[j] == 0 && bar[i] == 0) {
      } else if (bar[j] == 0 && bar[i] == 1) {
        ts.set_false(n + j);
      } else if (bar[j] == 1 && bar[i] == 0) {
        ts.set_false(i);
      } else {
        ts.add_if(i, n + j);
        ts.add_if(ts.negate(i), ts.negate(n + j));
      }
    } else if (squ[i][j] == 1) {
      if (bar[j] == 0 && bar[i] == 0) {
        cout << -1 << '\n';
        return 0;
      } else if (bar[j] == 0 && bar[i] == 1) {
        ts.set_true(n + j);
      } else if (bar[j] == 1 && bar[i] == 0) {
        ts.set_true(i);
      } else {
        ts.add_or(i, n + j);
        ts.add_nand(i, n + j);
      }
    }
  }
  vector<bool> on = ts.build();
  if (on.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  vector<string> s;
  vector<int> ans;
  REP(i, n) {
    if (on[i]) {
      s.emplace_back("row");
      ans.emplace_back(i);
    }
  }
  REP(j, n) {
    if (on[n + j]) {
      s.emplace_back("col");
      ans.emplace_back(j);
    }
  }
  int sz = s.size();
  cout << sz << '\n';
  REP(i, sz) cout << s[i] << ' ' << ans[i] << '\n';
  return 0;
}