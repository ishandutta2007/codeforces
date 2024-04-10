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
  vector<int> b(n);
  vector<bool> exist(n * 2, false);
  REP(i, n) {
    cin >> b[i]; --b[i];
    exist[b[i]] = true;
  }
  vector<int> a;
  REP(i, n * 2) {
    if (!exist[i]) a.emplace_back(i);
  }
  vector<int> l(n, 0);
  REP(i, n) {
    if (i > 0) l[i] = l[i - 1];
    while (l[i] < n && a[l[i]] < b[i]) ++l[i];
  }
  vector<int> r(n, n - 1);
  for (int i = n - 1; i >= 0; --i) {
    if (i + 1 < n) r[i] = r[i + 1];
    while (r[i] >= 0 && a[r[i]] > b[i]) --r[i];
  }
  int ans_l = 0, ans_r = n;
  REP(i, n) {
    chmax(ans_l, max(i - r[i], 0));
    chmin(ans_r, n - max(l[i] - i, 0));
  }
  cout << max(ans_r - ans_l + 1, 0) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}