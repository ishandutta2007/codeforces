#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int h, g; cin >> h >> g;
  int n = 1 << h;
  vector<int> a(n); FOR(i, 1, n) cin >> a[i];
  vector<int> ans;
  queue<pair<int, int>> que;
  que.emplace(1, 1);
  while (!que.empty()) {
    auto [root, height] = que.front(); que.pop();
    if (root >= n || height > g) continue;
    while (true) {
      int pos = root, mx = height;
      while (true) {
        int l = pos << 1, r = l + 1;
        if (l >= n || (a[l] == 0 && a[r] == 0)) break;
        ++mx;
        pos = a[l] > a[r] ? l : r;
      }
      if (mx == g) break;
      ans.emplace_back(root);
      pos = root;
      while (true) {
        int l = pos << 1, r = l + 1;
        if (l >= n || (a[l] == 0 && a[r] == 0)) {
          a[pos] = 0;
          break;
        }
        a[pos] = max(a[l], a[r]);
        pos = a[l] > a[r] ? l : r;
      }
      // REP(i, n) cout << a[i] << " \n"[i + 1 == n];
    }
    que.emplace(root << 1, height + 1);
    que.emplace((root << 1) + 1, height + 1);
  }
  cout << accumulate(ALL(a), 0LL) << '\n';
  int q = ans.size();
  REP(i, q) cout << ans[i] << " \n"[i + 1 == q];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}