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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int l, r, k; cin >> l >> r >> k;
  if (l == r) {
    cout << (l == 1 ? "NO\n" : "YES\n");
    return;
  }
  int odd = 0;
  if (l & 1) {
    ++l;
    ++odd;
  }
  if (l <= r && (r & 1)) {
    --r;
    ++odd;
  }
  if (l <= r) odd += (r + 1 - l) / 2;
  cout << (odd <= k ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}