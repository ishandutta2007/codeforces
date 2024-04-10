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

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  const int m = *max_element(ALL(a));
  vector<int> exists(m + 1, false);
  REP(i, n) exists[a[i]] = true;
  for (int i = m / 2; i >= 1; --i) {
    if (exists[i]) continue;
    const int l = m / i;
    int cnt = 0;
    vector<int> b(l + 1, true);
    for (int j = 2; j <= l; ++j) {
      if (!b[j]) continue;
      if (exists[i * j]) {
        if (++cnt == 2) break;
        for (int k = j * 2; k <= l; k += j) b[k] = false;
      }
    }
    if (cnt == 2) exists[i] = true;
  }
  cout << count(ALL(exists), true) - n << '\n';
  return 0;
}