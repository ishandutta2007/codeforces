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
struct UnionFind {
  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  void unite(int ver1, int ver2) {
    ver1 = root(ver1);
    ver2 = root(ver2);
    if (ver1 != ver2) {
      if (data[ver1] > data[ver2]) swap(ver1, ver2);
      data[ver1] += data[ver2];
      data[ver2] = ver1;
    }
  }

  bool same(int ver1, int ver2) { return root(ver1) == root(ver2); }

  int size(int ver) { return -data[root(ver)]; }

private:
  vector<int> data;
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  UnionFind uf(n);
  vector<vector<int> > graph(n);
  while (m--) {
    int a, b; cin >> a >> b; --a; --b;
    uf.unite(a, b);
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  if (uf.size(0) < n) {
    cout << -1 << '\n';
    return 0;
  }
  set<int> v1{0}, v2v3;
  for (int e : graph[0]) v2v3.emplace(e);
  if (v2v3.size() <= 1) {
    cout << -1 << '\n';
    return 0;
  }
  FOR(i, 1, n) {
    bool same = graph[i].size() == v2v3.size();
    for (int e : graph[i]) {
      if (v2v3.count(e) == 0) same = false;
    }
    if (same) v1.emplace(i);
  }
  set<int> v3;
  REP(i, n) {
    if (v2v3.count(i) == 1) {
      for (int e : graph[i]) {
        if (v1.count(e) == 0) v3.emplace(e);
      }
      break;
    }
  }
  if (v3.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> ans(n);
  REP(i, n) {
    if (v2v3.count(i) == 1 && v3.count(i) == 0) {
      ans[i] = 2;
      int cnt = 0;
      for (int e : graph[i]) {
        if (v3.count(e) == 1) {
          ++cnt;
        } else if (v1.count(e) == 0) {
          cout << -1 << '\n';
          return 0;
        }
      }
      if (cnt != v3.size()) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  for (int e : v3) {
    for (int dst : graph[e]) {
      if (v3.count(dst) == 1) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  for (int e : v1) ans[e] = 1;
  for (int e : v3) ans[e] = 3;
  REP(i, n) cout << ans[i] << (i + 1 == n ? '\n' : ' ');
  return 0;
}