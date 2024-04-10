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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int ans = 2;
  REP(s, n) {
    if (n - s < ans) break;
    int num = 1, i = s + 1;
    if (a[s] == a[s + 1]) {
      i = upper_bound(a.begin() + (s + 2), a.end(), a[s]) - a.begin() - 1;
      num = i - s;
    }
    while (i < n && num + n - i >= ans) {
      ++num;
      i = lower_bound(a.begin() + (i + 1), a.end(), (a[i] << 1) - a[s]) - a.begin();
    }
    chmax(ans, num);
  }
  cout << n - ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}