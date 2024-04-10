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
  vector<int> a[2]{};
  for (int i = 14; a[0].size() + a[1].size() + 4 <= n; i += 4) {
    a[0].emplace_back(i);
    a[0].emplace_back(i + 1);
    a[1].emplace_back(i + 2);
    a[1].emplace_back(i + 3);
  }
  if (n % 4 == 1) {
    a[0].emplace_back(0);
  } else if (n % 4 == 2) {
    REP(j, 2) REP(_, 2) a[j].pop_back();
    a[0].emplace_back(2);
    a[0].emplace_back(3);
    a[0].emplace_back(4);
    a[1].emplace_back(1);
    a[1].emplace_back(8);
    a[1].emplace_back(12);
  } else if (n % 4 == 3) {
    a[0].emplace_back(2);
    a[0].emplace_back(3);
    a[1].emplace_back(1);
  }
  REP(i, n) {
    cout << a[i & 1].back() << " \n"[i + 1 == n];
    a[i & 1].pop_back();
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}