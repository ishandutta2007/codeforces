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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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

constexpr int M = 1000000000;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  if (k == n) {
    cout << M << '\n';
    return;
  }
  map<int, vector<int>> pos;
  REP(i, n) pos[a[i]].emplace_back(i);
  for (auto it = pos.begin(); it != pos.end(); it = pos.erase(it)) {
    if (static_cast<int>(it->second.size()) > k - 2) break;
    for (const int i : it->second) a[i] = M;
    k -= it->second.size();
  }
  int ans = 0;
  while (k >= 0 && !pos.empty()) {
    const int m = pos.begin()->first;
    chmax(ans, m);
    if (k >= 2) {
      chmax(ans, min(m * 2, M));
    } else {
      FOR(i, 1, n) {
        chmax(ans, min(min(a[i - 1], a[i]), m * 2));
        if (k >= 1) {
          chmax(ans, min(min(a[i - 1], M), m * 2));
          chmax(ans, min(min(M, a[i]), m * 2));
        }
      }
    }
    for (const int i : pos.begin()->second) a[i] = M;
    k -= pos.begin()->second.size();
    pos.erase(pos.begin());
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}