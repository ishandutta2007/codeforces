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
  string s; cin >> s;
  int n = s.length();
  vector<int> dep(n);
  dep[0] = s[0] == '+' ? 1 : -1;
  FOR(i, 1, n) dep[i] = dep[i - 1] + (s[i] == '+' ? 1 : -1);
  vector<int> minus(n + 1, INF);
  for (int i = n - 1; i >= 0; --i) {
    if (dep[i] < 0) minus[-dep[i]] = i;
  }
  for (int i = n - 1; i > 0; --i) chmin(minus[i], minus[i + 1]);
  ll ans = 0;
  FOR(i, 1, n + 1) {
    if (minus[i] == INF) break;
    ans += minus[i] + 1;
  }
  cout << ans + n << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}