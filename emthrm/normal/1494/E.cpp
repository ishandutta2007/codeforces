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

int main() {
  int n, m; cin >> n >> m;
  set<pair<int, int>> same, diff;
  map<pair<int, int>, char> mp;
  while (m--) {
    char type; cin >> type;
    if (type == '+') {
      int u, v; char c; cin >> u >> v >> c;
      if (mp.count({v, u}) == 1) (mp[{v, u}] == c ? same : diff).emplace(minmax(u, v));
      mp[{u, v}] = c;
    } else if (type == '-') {
      int u, v; cin >> u >> v;
      same.erase(minmax(u, v));
      diff.erase(minmax(u, v));
      mp.erase({u, v});
    } else if (type == '?') {
      int k; cin >> k;
      if (k & 1) {
        cout << (same.empty() && diff.empty() ? "NO\n" : "YES\n");
      } else {
        cout << (same.empty() ? "NO\n" : "YES\n");
      }
    }
  }
  return 0;
}