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
  int n, m; cin >> n >> m;
  vector<int> x(n); REP(i, n) cin >> x[i];
  vector<string> s(n); REP(i, n) cin >> s[i];
  ll surprise = -LINF;
  vector<int> ans;
  REP(bit, 1 << n) {
    ll value = 0;
    REP(i, n) {
      if (bit >> i & 1) {
        value += x[i];
      } else {
        value -= x[i];
      }
    }
    vector<int> coef(m, 0);
    REP(j, m) {
      REP(i, n) {
        if (s[i][j] == '1') {
          if (bit >> i & 1) {
            --coef[j];
          } else {
            ++coef[j];
          }
        }
      }
    }
    vector<int> ord(m);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](int l, int r) -> bool { return coef[l] < coef[r]; });
    vector<int> p(m);
    REP(i, m) {
      p[ord[i]] = i + 1;
      value += coef[ord[i]] * (i + 1);
    }
    if (chmax(surprise, value)) ans = p;
  }
  REP(i, m) cout << ans[i] << " \n"[i + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}