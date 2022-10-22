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

int mn[]{0, -1, 1, 1, 2, 2}, mx[]{0, -1, 1, 1, 2, 2};

void solve() {
  ll n; cin >> n;
  if (n == 2 || n % 2 == 1) {
    cout << "-1\n";
    return;
  }
  n /= 2;
  ll a = 0, b = n / 3;
  while (a * 2 + b * 3 < n) {
    ++a;
    while (a * 2 + b * 3 > n) --b;
  }
  cout << a + b << ' ';
  a = (n + 1) / 2; b = 0;
  while (a * 2 + b * 3 > n) {
    --a;
    while (a * 2 + b * 3 < n) ++b;
  }
  cout << a + b << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}