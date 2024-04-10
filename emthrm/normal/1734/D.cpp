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

void solve() {
  int n, k; cin >> n >> k; --k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  if (k == 0 || k + 1 == n) {
    cout << "YES\n";
    return;
  }
  ll hp = a[k];
  int l = k - 1, r = k + 1;
  ll least_l = LINF, least_r = LINF, add_l = 0, add_r = 0;
  while (true) {
    if (least_l == LINF) {
      add_l = a[l--];
      least_l = add_l;
      for (; l >= 0 && add_l < 0; --l) {
        add_l += a[l];
        chmin(least_l, add_l);
      }
    }
    if (least_r == LINF) {
      add_r = a[r++];
      least_r = add_r;
      for (; r < n && add_r < 0; ++r) {
        add_r += a[r];
        chmin(least_r, add_r);
      }
    }
    if (hp + least_l >= 0) {
      least_l = LINF;
      hp += add_l;
      if (l < 0) break;
    } else if (hp + least_r >= 0) {
      least_r = LINF;
      hp += add_r;
      if (r >= n) break;
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}