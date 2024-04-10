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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  sort(ALL(s));
  if (s[0] != s[k - 1]) {
    cout << s[k - 1] << '\n';
    return;
  }
  if (s.front() == s.back()) {
    REP(_, (n + k - 1) / k) cout << s.front();
    cout << '\n';
    return;
  }
  string t = s;
  t.erase(unique(ALL(t)), t.end());
  if (k < n && s[k - 1] != s[k] && t.length() == 2) {
    cout << s[0];
    REP(_, (n - k + k - 1) / k) cout << s[k];
  } else {
    cout << s.substr(k - 1);
  }
  cout << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}