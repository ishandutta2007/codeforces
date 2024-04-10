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
  vector<int> t(n); REP(i, n) cin >> t[i];
  vector<int> carousel(t);
  sort(ALL(carousel));
  if (carousel.front() == carousel.back()) {
    cout << "1\n";
    REP(i, n) cout << '1' << " \n"[i + 1 == n];
  } else if (n % 2 == 0) {
    cout << "2\n";
    REP(i, n) cout << (i & 1 ? '1' : '2') << " \n"[i + 1 == n];
  } else {
    vector<int> ans(n, 0);
    bool yet = true;
    FOR(i, 1, n) {
      if (yet && t[i - 1] == t[i]) {
        ans[i] = ans[i - 1];
        yet = false;
      } else {
        ans[i] = ans[i - 1] ^ 1;
      }
    }
    if (yet && t[0] != t[n - 1]) ans[n - 1] = 2;
    cout << char('1' + *max_element(ALL(ans))) << '\n';
    REP(i, n) cout << char('0' + ans[i] + 1) << " \n"[i + 1 == n];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}