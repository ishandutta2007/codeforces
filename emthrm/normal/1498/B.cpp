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

constexpr int B = 20;

void solve() {
  int n, w; cin >> n >> w;
  vector<int> rect(B, 0);
  while (n--) {
    int wi; cin >> wi;
    ++rect[__builtin_ctz(wi)];
  }
  int h = 0;
  while (*max_element(ALL(rect)) > 0) {
    ++h;
    int width = w;
    for (int i = B - 1; i >= 0; --i) {
      while (rect[i] > 0 && width >= (1 << i)) {
        --rect[i];
        width -= 1 << i;
      }
    }
  }
  cout << h << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}