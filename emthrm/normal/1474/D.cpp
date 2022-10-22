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
  vector<ll> l(n, -1), r(n, -1);
  auto calc_l = [&](int i) {
    if (i == 0) {
      l[i] = a[i];
    } else {
      l[i] = (l[i - 1] == -1 || a[i] < l[i - 1] ? -1 : a[i] - l[i - 1]);
    }
  };
  REP(i, n) calc_l(i);
  auto calc_r = [&](int i) {
    if (i + 1 == n) {
      r[i] = a[i];
    } else {
      r[i] = (r[i + 1] == -1 || a[i] < r[i + 1] ? -1 : a[i] - r[i + 1]);
    }
  };
  for (int i = n - 1; i >= 0; --i) calc_r(i);
  auto check = [&](int i) {
    if (i > 0 && l[i - 1] == -1) return false;
    if (i + 1 < n && r[i + 1] == -1) return false;
    return (i == 0 ? 0 : l[i - 1]) + (i + 1 == n ? 0 : r[i + 1]) == a[i];
  };
  REP(i, n) {
    if (check(i)) {
      cout << "YES\n";
      return;
    }
  }
  FOR(i, 1, n) {
    swap(a[i - 1], a[i]);
    calc_l(i - 1);
    calc_l(i);
    calc_r(i);
    calc_r(i - 1);
    if (check(i - 1) || check(i)) {
      cout << "YES\n";
      return;
    }
    swap(a[i - 1], a[i]);
    calc_l(i - 1);
    calc_l(i);
    calc_r(i);
    calc_r(i - 1);
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}