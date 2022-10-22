#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
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
  int n; cin >> n;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  vector<long long> c(n), k(n);
  REP(i, n) cin >> c[i];
  REP(i, n) cin >> k[i];
  struct Node {
    long long cost;
    int a, b;
    Node(long long cost, int a, int b = -1) : cost(cost), a(a), b(b) {}
    inline bool operator>(const Node &rhs) const {
      return cost != rhs.cost ? cost > rhs.cost : a != rhs.a ? a > rhs.a : b > rhs.b;
    }
  };
  priority_queue<Node, vector<Node>, greater<Node> > que;
  REP(i, n) que.emplace(c[i], i);
  REP(i, n) FOR(j, i + 1, n) {
    int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    que.emplace((k[i] + k[j]) * dist, i, j);
  }
  UnionFind uf(n);
  long long ans = 0;
  vector<int> stations;
  vector<int> wire_a, wire_b;
  vector<bool> elect(n, false);
  while (!que.empty()) {
    Node tp = que.top(); que.pop();
    if (tp.b == -1) {
      if (!elect[uf.root(tp.a)]) {
        ans += tp.cost;
        stations.emplace_back(tp.a);
        elect[uf.root(tp.a)] = true;
      }
    } else {
      if (elect[uf.root(tp.a)] && elect[uf.root(tp.b)]) continue;
      if (!uf.same(tp.a, tp.b)) {
        ans += tp.cost;
        wire_a.emplace_back(tp.a);
        wire_b.emplace_back(tp.b);
        int ra = uf.root(tp.a), rb = uf.root(tp.b);
        uf.unite(tp.a, tp.b);
        int r = uf.root(tp.a);
        if (elect[ra] || elect[rb]) elect[r] = true;
        if (r != ra) elect[ra] = false;
        if (r != rb) elect[rb] = false;
      }
    }
  }
  cout << ans << '\n';
  int sz = stations.size();
  cout << sz << '\n';
  sort(ALL(stations));
  REP(i, sz) cout << stations[i] + 1 << (i + 1 == sz ? '\n' : ' ');
  sz = wire_a.size();
  cout << sz << '\n';
  REP(i, sz) cout << wire_a[i] + 1 << ' ' << wire_b[i] + 1 << '\n';
  return 0;
}