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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, a, b; cin >> n >> a >> b;
  vector<int> l{a}, r{b};
  for (int i = n; i > b; --i) {
    if (i != a) l.emplace_back(i);
  }
  FOR(i, 1, a) {
    if (i != b) r.emplace_back(i);
  }
  if (l.size() > n / 2 || r.size() > n / 2) {
    cout << "-1\n";
    return;
  }
  FOR(i, a + 1, b) (l.size() < n / 2 ? l : r).emplace_back(i);
  REP(i, n / 2) cout << l[i] << ' ';
  REP(i, n / 2) cout << r[i] << " \n"[i + 1 == n / 2];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}