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
  int n; cin >> n;
  vector<int> p(n); REP(i, n) cin >> p[i];
  vector<int> ans{p[0]};
  FOR(i, 1, n - 1) {
    if ((ans.back() < p[i] && p[i] > p[i + 1]) || (ans.back() > p[i] && p[i] < p[i + 1])) {
      ans.emplace_back(p[i]);
    }
  }
  ans.emplace_back(p[n - 1]);
  int m = ans.size();
  cout << m << '\n';
  REP(i, m) cout << ans[i] << " \n"[i + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}