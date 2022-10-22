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
  int n; ll l, r; cin >> n >> l >> r;
  ll v = 1;
  FOR(i, 1, n + 1) {
    if (v <= l && l < v + (n - i) * 2) {
      vector<int> ans;
      ll diff = l - v;
      int j = i + 1 + (diff + 1) / 2;
      if (diff & 1) ans.emplace_back(j - 1);
      if (j > n) {
        ++i;
        j = i + 1;
      }
      while (i < n && ans.size() < r - l + 1) {
        ans.emplace_back(i);
        if (ans.size() == r - l + 1) break;
        ans.emplace_back(j++);
        if (j > n) {
          ++i;
          j = i + 1;
        }
      }
      if (ans.size() < r - l + 1) ans.emplace_back(1);
      REP(i, r - l + 1) cout << ans[i] << " \n"[i + 1 == r - l + 1];
      return;
    }
    v += (n - i) * 2;
  }
  cout << "1\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}