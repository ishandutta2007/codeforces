#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename CostType>
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &x) const {
    return cost != x.cost ? cost < x.cost : dst != x.dst ? dst < x.dst : src < x.src;
  }
  inline bool operator<=(const Edge &x) const { return !(x < *this); }
  inline bool operator>(const Edge &x) const { return x < *this; }
  inline bool operator>=(const Edge &x) const { return !(*this < x); }
};

int main() {
  // 2
  // cf. https://atcoder.jp/contests/agc035/tasks/agc035_b
  int n; cin >> n;
  vector<pair<ll, ll>> slope1(n), slope2(n);
  REP(i, n) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    {
      ll x = 1LL * (a + b) * d, y = 1LL * b * c, g = gcd(x, y);
      slope1[i] = {x / g, y / g};
    }
    {
      ll x = 1LL * a * d, y = 1LL * b * (c + d), g = gcd(x, y);
      slope2[i] = {x / g, y / g};
    }
  }
  vector<pair<ll, ll>> slope(n * 2);
  copy(ALL(slope1), slope.begin());
  copy(ALL(slope2), slope.begin() + n);
  sort(ALL(slope));
  slope.erase(unique(ALL(slope)), slope.end());
  int m = slope.size();
  vector<vector<Edge<int>>> graph(m);
  REP(i, n) {
    int a = lower_bound(ALL(slope), slope1[i]) - slope.begin();
    int b = lower_bound(ALL(slope), slope2[i]) - slope.begin();
    graph[a].emplace_back(a, b, i);
    graph[b].emplace_back(b, a, i);
  }
  vector<int> a, b;
  vector<bool> visited(m, false), used(n, false);
  REP(s, m) {
    if (visited[s]) continue;
    visited[s] = true;
    auto f = [&](auto &&f, int ver) -> int {
      vector<int> edge;
      for (const Edge<int> &e : graph[ver]) {
        if (used[e.cost]) continue;
        used[e.cost] = true;
        if (visited[e.dst]) {
          edge.emplace_back(e.cost);
        } else {
          visited[e.dst] = true;
          int child = f(f, e.dst);
          if (child == -1) {
            edge.emplace_back(e.cost);
          } else {
            a.emplace_back(child);
            b.emplace_back(e.cost);
          }
        }
      }
      while (edge.size() >= 2) {
        a.emplace_back(edge.back());
        edge.pop_back();
        b.emplace_back(edge.back());
        edge.pop_back();
      }
      return edge.empty() ? -1 : edge.front();
    };
    f(f, s);
  }
  int c = a.size();
  cout << c << '\n';
  REP(i, c) cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
  return 0;
}