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
  int n; cin >> n;
  vector<ll> k(n), h(n);
  REP(i, n) cin >> k[i];
  REP(i, n) cin >> h[i];
  reverse(ALL(k));
  reverse(ALL(h));
  ll ans = 0;
  for (int i = 0; i < n;) {
    ll cur = h[i];
    vector<ll> mana{cur};
    int j = i + 1;
    while (j < n && k[j - 1] - k[j] < cur) {
      cur = max(cur - (k[j - 1] - k[j]), h[j]);
      mana.emplace_back(cur);
      ++j;
    }
    for (int x = j - 2; x >= i; --x) {
      chmax(mana[x - i], mana[x + 1 - i] + (k[x] - k[x + 1]));
    }
    ans += mana.front() * (mana.front() + 1) / 2;
    i = j;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}