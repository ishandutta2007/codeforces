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

int main() {
  int n; cin >> n;
  vector<int> v(n); REP(i, n) cin >> v[i];
  vector<ll> ans(n, 0);
  ll pre = 0;
  FOR(i, 1, n) {
    ans[i] = ans[i - 1];
    pre += v[i - 1];
    chmax(ans[i], (pre + i - 1) / i);
  }
  const ll s = accumulate(ALL(v), 0LL);
  REP(i, n) chmax(ans[i], (s + i + 1 - 1) / (i + 1));
  reverse(ALL(ans));
  int q; cin >> q;
  while (q--) {
    int t; cin >> t;
    if (ans.front() > t) {
      cout << "-1\n";
      continue;
    }
    cout << n - (prev(upper_bound(ALL(ans), t)) - ans.begin()) << '\n';
  }
  return 0;
}