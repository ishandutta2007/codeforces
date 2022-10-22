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

int main() {
  ll k, l, r, t, x, y; cin >> k >> l >> r >> t >> x >> y;
  r -= l;
  k -= l;
  if (y > r) {
    cout << (k / x >= t ? "Yes\n" : "No\n");
    return 0;
  }
  if (x > y) {
    if (k > r - y) {
      ll d = (k - (r - y) + x - 1) / x;
      if (t < d) {
        cout << "Yes\n";
        return 0;
      }
      k -= d * x;
      if (k < 0) {
        cout << "No\n";
        return 0;
      }
      t -= d;
    }
    cout << (k / (x - y) >= t ? "Yes\n" : "No\n");
    return 0;
  }
  ll d = (k - (x - 1) + x - 1) / x;
  if (t <= d) {
    cout << "Yes\n";
    return 0;
  }
  k -= d * x;
  assert(0 <= k && k < x);
  t -= d;
  vector<bool> reached(x, false);
  while (!reached[k] && t > 0) {
    reached[k] = true;
    k += y;
    if (k > r) {
      cout << "No\n";
      return 0;
    }
    d = (k - (x - 1) + x - 1) / x;
    k -= d * x;
    t -= d;
  }
  cout << "Yes\n";
  return 0;
}