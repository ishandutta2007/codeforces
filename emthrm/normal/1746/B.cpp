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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  while (!a.empty() && a.back() == 1) a.pop_back();
  reverse(ALL(a));
  while (!a.empty() && a.back() == 0) a.pop_back();
  reverse(ALL(a));
  n = a.size();
  if (n == 0) {
    cout << 0 << '\n';
    return;
  }
  int lb = 0, ub = count(ALL(a), 1);
  while (ub - lb > 1) {
    const int mid = (lb + ub) / 2;
    vector<int> b = a;
    int rem = mid;
    REP(i, n) {
      if (b[i] == 1) {
        b[i] = 0;
        if (--rem == 0) break;
      }
    }
    rem = mid;
    for (int i = n - 1; i >= 0 && rem > 0; --i) {
      if (b[i] == 0) {
        b[i] = 1;
        --rem;
      }
    }
    (is_sorted(ALL(b)) ? ub : lb) = mid;
  }
  cout << ub << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}