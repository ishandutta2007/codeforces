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

  string s; cin >> s;
  int n = s.length();
  vector<vector<long long> > ans(10, vector<long long>(10));
  REP(i, 10) FOR(j, i, 10) {
    vector<vector<long long> > graph(10, vector<long long>(10, LINF));
    REP(k, 10) {
      string str = to_string(k + i);
      graph[k][str.back() - '0'] = 1;
      str = to_string(k + j);
      graph[k][str.back() - '0'] = 1;
    }
    WarshallFloyd<long long> wf(graph, LINF);
    long long cost = 0;
    REP(i, n - 1) {
      if (wf.dist[s[i] - '0'][s[i + 1] - '0'] == LINF) {
        cost = -1;
        break;
      }
      cost += wf.dist[s[i] - '0'][s[i + 1] - '0'] - 1;
    }
    ans[i][j] = ans[j][i] = cost;
  }
  REP(i, 10) {
    REP(j, 10) cout << ans[i][j] << (j == 9 ? '\n' : ' ');
  }
  return 0;
}