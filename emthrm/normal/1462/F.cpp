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
  vector<int> l(n), r(n); REP(i, n) cin >> l[i] >> r[i];
  vector<int> x = l;
  copy(ALL(r), back_inserter(x));
  sort(ALL(x));
  x.erase(unique(ALL(x)), x.end());
  int m = x.size();
  vector<int> right(m, -1), ins(m, 0), era(m, 0), ps(m + 1, 0), rs(m + 1, 0);
  REP(i, n) {
    l[i] = lower_bound(ALL(x), l[i]) - x.begin();
    ++ins[l[i]];
    r[i] = lower_bound(ALL(x), r[i]) - x.begin();
    ++era[r[i]];
    chmax(right[l[i]], r[i]);
    ++ps[l[i] + 1];
    ++ps[r[i] + 1];
    ++rs[r[i] + 1];
  }
  FOR(i, 1, m + 1) ps[i] += ps[i - 1];
  FOR(i, 1, m + 1) rs[i] += rs[i - 1];
  int ans = n - 1, left = 0;
  REP(i, m) {
    if (right[i] != -1) {
      int seg = (ps[right[i] + 1] - ps[i]) - (rs[right[i] + 1] - rs[i]) + left;
      chmin(ans, n - seg);
    }
    left += ins[i] - era[i];
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}