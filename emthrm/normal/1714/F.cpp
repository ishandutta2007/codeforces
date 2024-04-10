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
  int n, d12, d23, d31; cin >> n >> d12 >> d23 >> d31;
  int id = 4;
  FOR(a, 1, d12) {
    if (a > d31) break;
    const int b = d31 - a;
    if (d12 - a + b == d23 && d12 + 1 + b <= n) {
      cout << "YES\n";
      vector<int> path{1};
      FOR(i, 1, d12) path.emplace_back(i == a && b == 0 ? 3 : id++);
      path.emplace_back(2);
      if (b > 0) {
        vector<int> path2{path[a]};
        FOR(_, 1, b) path2.emplace_back(id++);
        path2.emplace_back(3);
        FOR(i, 1, path2.size()) cout << path2[i - 1] << ' ' << path2[i] << '\n';
      }
      FOR(i, 1, path.size()) cout << path[i - 1] << ' ' << path[i] << '\n';
      while (id <= n) cout << 1 << ' ' << id++ << '\n';
      return ;
    }
  }
  if (d12 + d31 == d23) {
    vector<int> path{3};
    FOR(_, 1, d31) path.emplace_back(id++);
    path.emplace_back(1);
    FOR(_, 1, d12) path.emplace_back(id++);
    path.emplace_back(2);
    cout << "YES\n";
    FOR(i, 1, path.size()) cout << path[i - 1] << ' ' << path[i] << '\n';
    while (id <= n) cout << 1 << ' ' << id++ << '\n';
  } else if (d12 + d23 == d31) {
    vector<int> path{1};
    FOR(_, 1, d12) path.emplace_back(id++);
    path.emplace_back(2);
    FOR(_, 1, d23) path.emplace_back(id++);
    path.emplace_back(3);
    cout << "YES\n";
    FOR(i, 1, path.size()) cout << path[i - 1] << ' ' << path[i] << '\n';
    while (id <= n) cout << 1 << ' ' << id++ << '\n';
  } else {
    cout << "NO\n";
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}