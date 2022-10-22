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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<vector<tuple<int, int, int>>> graph(n);
  FOR(i, 1, n) {
    int p, a, b; cin >> p >> a >> b; --p;
    graph[p].emplace_back(i, a, b);
  }
  vector<int> r(n, -1);
  map<ll, int> path;
  const auto f = [&](auto&& f, const int node, const ll blue, const ll red) -> void {
    const auto it = path.upper_bound(blue);
    r[node] = (it == path.end() ? path.size() : it->second);
    for (const auto& [child, a, b] : graph[node]) {
      const int size = path.size();
      path[red + b] = size;
      f(f, child, blue + a, red + b);
      path.erase(prev(path.end()));
    }
  };
  f(f, 0, 0, 0);
  FOR(i, 1, n) cout << r[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}