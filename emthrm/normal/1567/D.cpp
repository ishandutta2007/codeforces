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

constexpr int B = 9, W = 100000000;

void solve() {
  int s, n; cin >> s >> n;
  if (n == 1) {
    cout << s << '\n';
    return;
  }
  vector ans(n, vector(B, 0));
  int zero = n;
  for (int b = B - 1, w = W; b >= 0; --b, w /= 10) {
    while (zero > 0 && s >= w + zero - 1) {
      ans[--zero][b] = 1;
      s -= w;
    }
    if (zero == 0) {
      REP(i, n) {
        int put = min(9 - ans[i][b], s / w);
        s -= put * w;
        ans[i][b] += put;
      }
    }
  }
  REP(i, n) {
    string t = "";
    REP(j, B) t += '0' + ans[i][j];
    reverse(ALL(t));
    cout << stoll(t) << " \n"[i + 1 == n];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}