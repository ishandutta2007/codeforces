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
  vector<int> l, r, d;
  REP(i, n) {
    int pos = min_element(a.begin() + i, a.end()) - a.begin();
    rotate(a.begin() + i, a.begin() + pos, a.begin() + (pos + 1));
    if (pos > i) {
      l.emplace_back(i);
      r.emplace_back(pos);
      d.emplace_back(pos - i);
    }
  }
  const int k = l.size();
  cout << k << '\n';
  REP(i, k) cout << l[i] + 1 << ' ' << r[i] + 1 << ' ' << d[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}