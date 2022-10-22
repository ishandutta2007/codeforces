#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, x; cin >> n >> x;
  vector<int> a;
  bool is_x = false;
  while (n--) {
    int ai; cin >> ai;
    is_x |= ai == x;
    if (ai != x) a.emplace_back(ai);
  }
  n = a.size();
  sort(ALL(a));
  if (n == 0) {
    cout << 0 << '\n';
    return;
  }
  int diff = 0;
  REP(i, n) diff += x - a[i];
  cout << (is_x || diff == 0 ? 1 : 2) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}