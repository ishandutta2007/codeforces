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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  auto f = [&](auto &&f, int l, int r, int b) -> int {
    if (r <= l + 2) return 0;
    assert(b > 0);
    int p = a[l] >> b & 1, q = a[r - 1] >> b & 1;
    if (p == q) return f(f, l, r, b - 1);
    int lb = l, ub = r - 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (a[mid] >> b & 1 ? ub : lb) = mid;
    }
    return min(f(f, l, ub, b - 1) + (r - ub - 1), f(f, ub, r, b - 1) + (ub - l - 1));
  };
  cout << f(f, 0, n, 29) << '\n';
  return 0;
}