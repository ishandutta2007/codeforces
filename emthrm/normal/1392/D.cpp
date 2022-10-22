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

template <typename T = char, typename U = string>
vector<pair<T, int>> rle(const U &s) {
  int n = s.size();
  vector<pair<T, int>> res;
  T now = s[0];
  int cnt = 1;
  FOR(i, 1, n) {
    if (s[i] != now) {
      res.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  res.emplace_back(now, cnt);
  return res;
}

void solve() {
  int n; string s; cin >> n >> s;
  int pos = find(ALL(s), 'R') - s.begin();
  if (pos == n || count(ALL(s), 'L') == 0) {
    cout << (n + 2) / 3 << '\n';
    return;
  }
  rotate(s.begin(), s.begin() + pos, s.end());
  int pop = 0;
  while (s.back() == 'R') {
    ++pop;
    s.pop_back();
  }
  reverse(ALL(s));
  while (pop--) s += 'R';
  reverse(ALL(s));
  int ans = 0;
  for (auto pr : rle<>(s)) ans += pr.second / 3;
  // {
  //   int mn = INF;
  //   REP(i, 1 << n) {
  //     string t = s;
  //     REP(j, n) {
  //       if (i >> j & 1) t[j] = t[j] == 'L' ? 'R' : 'L';
  //     }
  //     bool ok = true;
  //     REP(j, n) {
  //       int cnt = 0;
  //       cnt += t[(j - 1 + n) % n] == 'R';
  //       cnt += t[(j + 1) % n] == 'L';
  //       if (cnt == 1) ok &= t[j] == 'R' ? t[(j + 1) % n] == 'L' : t[(j - 1 + n) % n] == 'R';
  //     }
  //     if (ok) {
  //       chmin(mn, __builtin_popcount(i));
  //       if (__builtin_popcount(i) == 5) cout << t << '\n';
  //     }
  //   }
  //   cout << mn << ' ';
  // }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}