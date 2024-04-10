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

int calc(int n) {
  int ans = 0;
  for (; n % 2 == 0; n /= 2) {
    ++ans;
  }
  return ans;
}

int main() {
  constexpr int N = 200000;
  int p2[N + 1]{};
  for (int i = 1; i <= N; ++i) {
    p2[i] = calc(i);
  }

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int rem = n;
    REP(i, n) {
      int a; cin >> a;
      if (a <= N) {
        rem -= p2[a];
      } else {
        rem -= calc(a);
      }
    }
    int ans = 0;
    if (rem > 0) {
      vector<int> b(n + 1);
      copy(p2, p2 + (n + 1), b.begin());
      sort(ALL(b), greater<int>());
      for (const int num : b) {
        ++ans;
        rem -= num;
        if (rem <= 0) break;
      }
    }
    cout << (rem > 0 ? -1 : ans) << '\n';
  }
  return 0;
}