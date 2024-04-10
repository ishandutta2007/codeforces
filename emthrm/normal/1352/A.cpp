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
  vector<int> ans{n / 1000 * 1000};
  n %= 1000;
  ans.emplace_back(n / 100 * 100);
  n %= 100;
  ans.emplace_back(n / 10 * 10);
  n %= 10;
  ans.emplace_back(n);
  sort(ALL(ans), greater<int>());
  while (ans.back() == 0) ans.pop_back();
  int k = ans.size();
  cout << k << '\n';
  REP(i, k) cout << ans[i] << " \n"[i + 1 == k];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}