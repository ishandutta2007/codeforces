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

void solve() {
  int n; cin >> n;
  vector<int> note(n * 2 + 1, 0);
  REP(_, n) {
    int x; cin >> x; --x;
    ++note[x];
  }
  vector<int> ans(n * 2 + 1, 0);
  if (note[0] > 0) {
    ans[0] = 1;
    --note[0];
  }
  FOR(i, 1, n * 2 + 1) {
    if (note[i - 1] > 0) {
      ans[i] = note[i - 1];
    } else if (note[i] > 0) {
      ans[i] = 1;
      --note[i];
    }
  }
  cout << n * 2 + 1 - count(ALL(ans), 0) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}