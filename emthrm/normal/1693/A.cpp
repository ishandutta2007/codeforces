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
  int n; cin >> n;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  while (!a.empty() && a.back() == 0) a.pop_back();
  n = a.size();
  if (n == 0) {
    cout << "Yes\n";
    return;
  }
  if (a.front() <= 0 || a.back() > 0 || accumulate(ALL(a), 0LL) != 0) {
    cout << "No\n";
    return;
  }
  ll ad = a.front();
  FOR(i, 1, n - 1) {
    ad += a[i];
    if (ad <= 0) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}