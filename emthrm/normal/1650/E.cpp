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

void solve() {
  int n, d; cin >> n >> d;
  vector<int> a(n + 1, 0); FOR(i, 1, n + 1) cin >> a[i];
  int ub = (d - n) / n + 1, lb = ub - 1;
  FOR(i, 1, n + 1) chmin(lb, a[i] - a[i - 1] - 1);
  while (ub - lb > 1) {
    const int mid = (lb + ub) / 2;
    auto f = [&](int i) -> bool {
      assert(i > 0);
      if (i + 1 == n + 1) {
        if (d - a[i - 1] - 1 >= mid) return true;
      } else {
        if (a[i + 1] - a[i - 1] - 1 < mid) return false;
        if ((a[i + 1] - a[i - 1] - 2) / 2 >= mid || d - a.back() - 1 >= mid) return true;
      }
      FOR(j, 1, i) {
        if ((a[j] - a[j - 1] - 2) / 2 >= mid) return true;
      }
      FOR(j, i + 2, n + 1) {
        if ((a[j] - a[j - 1] - 2) / 2 >= mid) return true;
      }
      return false;
    };
    vector<int> bads;
    FOR(i, 1, n + 1) {
      if (a[i] - a[i - 1] - 1 < mid) bads.emplace_back(i);
    }
    assert(!bads.empty());
    if (bads.size() >= 3) {
      ub = mid;
    } else if (bads.size() == 2) {
      (bads[0] + 1 == bads[1] && f(bads[0]) ? lb : ub) = mid;
    } else {
      (f(bads[0]) || (bads[0] - 1 > 0 && f(bads[0] - 1)) ? lb : ub) = mid;
    }
  }
  cout << lb << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}