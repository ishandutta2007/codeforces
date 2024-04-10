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
  int n, l, r; cin >> n >> l >> r;
  vector<int> left(n, 0), right(n, 0);
  REP(_, l) {
    int c; cin >> c; --c;
    ++left[c];
  }
  REP(_, r) {
    int c; cin >> c; --c;
    ++right[c];
  }
  REP(i, n) {
    int match = min(left[i], right[i]);
    left[i] -= match;
    right[i] -= match;
    l -= match;
    r -= match;
  }
  if (l < r) {
    swap(l, r);
    swap(left, right);
  }
  int ans = 0;
  REP(i, n) {
    int to_right = min(left[i] / 2, (l - r) / 2);
    left[i] -= to_right * 2;
    l -= to_right * 2;
    ans += to_right;
  }
  ans += (l - r) / 2;
  ans += (l + r) / 2;
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}