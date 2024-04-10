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
  int n, q; cin >> n >> q;
  vector<int> a(n, 0); REP(i, n) cin >> a[i];
  sort(ALL(a), greater<int>());
  a.emplace(a.begin(), 0);
  REP(i, n) a[i + 1] += a[i];
  while (q--) {
    int x; cin >> x;
    if (a.back() < x) {
      cout << "-1\n";
      continue;
    }
    int lb = 0, ub = n;
    while (ub - lb > 1) {
      const int mid = (lb + ub) / 2;
      (a[mid] < x ? lb : ub) = mid;
    }
    cout << ub << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}