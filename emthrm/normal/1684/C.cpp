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
  int n, m; cin >> n >> m;
  vector a(n, vector(m, 0)); REP(i, n) REP(j, m) cin >> a[i][j];
  REP(i, n) {
    vector<int> b = a[i];
    sort(ALL(b));
    vector<int> diff;
    REP(j, m) {
      if (a[i][j] != b[j]) diff.emplace_back(j);
    }
    if (diff.size() > 2) {
      cout << "-1\n";
      return;
    } else if (diff.size() == 2) {
      const int j1 = diff[0], j2 = diff[1];
      REP(i, n) {
        swap(a[i][j1], a[i][j2]);
        if (!is_sorted(ALL(a[i]))) {
          cout << "-1\n";
          return;
        }
      }
      cout << j1 + 1 << ' ' << j2 + 1 << '\n';
      return;
    }
  }
  cout << 1 << ' ' << 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}