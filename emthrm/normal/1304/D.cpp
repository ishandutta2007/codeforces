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
  int n; string s; cin >> n >> s;
  reverse(ALL(s));
  for (char &c : s) c = (c == '<' ? '>' : '<');
  vector<int> ans(n, -1);
  int now = 1;
  REP(i, n) {
    if ((i == n - 1 ? s[i - 1] : s[i]) == '<') ans[i] = now++;
  }
  for (int i = 0; i < n;) {
    if (ans[i] != -1) {
      ++i;
      continue;
    }
    int j = i + 1;
    while (j < n && ans[j] == -1) ++j;
    for (int k = j - 1; k >= i; --k) ans[k] = now++;
    i = j;
  }
  reverse(ALL(ans));
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
  for (char &c : s) c = (c == '<' ? '>' : '<');
  reverse(ALL(s));
  fill(ALL(ans), -1);
  now = 1;
  REP(i, n) {
    if ((i == n - 1 ? s[i - 1] : s[i]) == '<') ans[i] = now++;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (ans[i] == -1) ans[i] = now++;
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}