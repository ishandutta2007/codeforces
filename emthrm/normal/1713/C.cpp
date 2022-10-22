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

int main() {
  constexpr int N = 100000;
  set<int> sq;
  for (int i = 0; i * i <= (N - 1) * 2; ++i) {
    sq.emplace(i * i);
  }

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n, -1);
    for (int i = n - 1; i >= 0;) {
      const int target = *prev(sq.upper_bound(i * 2));
      FOR(j, target - i, i + 1) a[j] = target - j;
      i = target - i - 1;
    }
    REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  }
  return 0;

  // bool is_sq[(N - 1) * 2 + 1]{};
  // is_sq[0] = true;
  // for (int i = 1; i * i <= (N - 1) * 2; ++i) is_sq[i * i] = true;
  // for (int n = 2; n <= N; ++n) {
  //   vector<int> a(n);
  //   iota(ALL(a), 0);
  //   do {
  //     bool is_valid = true;
  //     REP(i, n) is_valid &= is_sq[a[i] + i];
  //     if (is_valid) {
  //       REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  //     }
  //   } while (next_permutation(ALL(a)));
  // }
}