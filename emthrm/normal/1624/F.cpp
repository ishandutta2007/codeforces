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

#ifndef ONLINE_JUDGE
int n, ans;
#endif

int added = 0, q = 0;

int query(int c) {
  added += c;
  ++q;
#ifndef ONLINE_JUDGE
  return (ans + added) / n;
#else
  cout << "+ " << c << endl;
  int x; cin >> x;
  return x;
#endif
}

int main() {
#ifndef ONLINE_JUDGE
  FOR(n_, 2, 1001) FOR(x_, 1, n_) {
  n = n_;
  ans = x_;
  added = q = 0;
#else
  int n; cin >> n;
#endif
  bool inc = true;
  int x = 0, prev = 0, lb = 0, ub = n - 1;
  while (ub - lb > 1) {
    const int mid = (lb + ub) / 2;
    if (inc) {
      if (query(mid - prev) > x) {
        ++x;
        inc = false;
        ub = mid;
      } else {
        lb = mid;
      }
      prev = mid;
    } else {
      if (query(n - (prev - mid)) > x) {
        ++x;
        ub = mid;
      } else {
        inc = true;
        lb = mid;
      }
      prev = mid;
    }
  }
#ifndef ONLINE_JUDGE
  if (n - ub != x_) {
    cout << n << ' ' << x_ << '\n';
    return 0;
  }
  }
#else
  cout << "! " << n - ub + added << endl;
#endif
  return 0;
}