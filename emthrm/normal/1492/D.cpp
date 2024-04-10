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
  int a, b, k; cin >> a >> b >> k;
  if (a == 0 || b == 1) {
    if (k == 0) {
      string x = string(b, '1') + string(a, '0');
      cout << "Yes\n" << x << '\n' << x << '\n';
    } else {
      cout << "No\n";
    }
  } else {
    string x = string(b, '1') + string(a, '0'), y = x;
    swap(y[1], y[a + b - 1]);
    int cur = a + b - 2;
    if (k > cur) {
      cout << "No\n";
    } else {
      for (int i = 1; i + 1 < b; ++i) {
        if (cur > k) {
          --cur;
          swap(y[i], y[i + 1]);
        }
      }
      FOR(i, b, a + b) {
        if (cur > k) {
          --cur;
          swap(x[i - 1], x[i]);
        }
      }
      cout << "Yes\n" << x << '\n' << y << '\n';
    }
  }
  return 0;
}