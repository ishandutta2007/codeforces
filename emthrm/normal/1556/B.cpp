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

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> parity[2]{};
  REP(i, n) parity[a[i] & 1].emplace_back(i);
  if (n & 1) {
    if (parity[0].size() > parity[1].size()) swap(parity[0], parity[1]);
    if (parity[0].size() != n / 2) {
      cout << "-1\n";
    } else {
      int ans = 0;
      REP(i, n / 2) ans += abs(i * 2 + 1 - parity[0][i]);
      cout << ans << '\n';
    }
  } else {
    if (parity[0].size() != parity[1].size()) {
      cout << "-1\n";
    } else {
      int ans1 = 0, ans2 = 0;
      REP(i, n / 2) ans1 += abs(i * 2 - parity[0][i]);
      REP(i, n / 2) ans2 += abs(i * 2 + 1 - parity[0][i]);
      cout << min(ans1, ans2) << '\n';
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}