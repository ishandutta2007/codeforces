#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  string s; cin >> s;
  vector<char> ans(100, '.');
  int pos = 50;
  ans[pos] = s[0];
  vector<bool> used(26, false);
  used[s[0] - 'a'] = true;
  FOR(i, 1, s.length()) {
    if (s[i] != ans[pos + 1] && s[i] != ans[pos - 1]) {
      if (used[s[i] - 'a'] || (ans[pos + 1] != '.' && ans[pos - 1] != '.')) {
        cout << "NO\n";
        return;
      }
      used[s[i] - 'a'] = true;
      if (ans[pos + 1] == '.') {
        ans[pos + 1] = s[i];
        ++pos;
      } else {
        ans[pos - 1] = s[i];
        --pos;
      }
    } else if (s[i] == ans[pos - 1]) {
      --pos;
    } else {
      ++pos;
    }
  }
  while (ans.back() == '.') ans.pop_back();
  reverse(ALL(ans));
  while (ans.back() == '.') ans.pop_back();
  REP(i, 26) {
    if (!used[i]) ans.emplace_back('a' + i);
  }
  cout << "YES\n";
  REP(i, 26) cout << ans[i];
  cout << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}