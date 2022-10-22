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
  vector<int> cnt(3, 0);
  for (char c : s) {
    if (c == 'R') {
      ++cnt[0];
    } else if (c == 'S') {
      ++cnt[1];
    } else if (c == 'P') {
      ++cnt[2];
    }
  }
  int mx = max_element(ALL(cnt)) - cnt.begin();
  if (mx == 0) {
    REP(_, s.length()) cout << 'P';
  } else if (mx == 1) {
    REP(_, s.length()) cout << 'R';
  } else if (mx == 2) {
    REP(_, s.length()) cout << 'S';
  }
  cout << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}