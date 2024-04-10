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
  map<char, int> mp;
  mp['S'] = 0; mp['W'] = 1; mp['N'] = 2; mp['E'] = 3;
  string s; cin >> s;
  set<pair<pair<int, int>, pair<int, int>>> st;
  int y = 0, x = 0, ans = 0;
  for (char c : s) {
    int ny = y + dy[mp[c]], nx = x + dx[mp[c]];
    ans += st.count(make_pair(make_pair(y, x), make_pair(ny, nx))) == 1 ? 1 : 5;
    st.emplace(make_pair(y, x), make_pair(ny, nx));
    st.emplace(make_pair(ny, nx), make_pair(y, x));
    y = ny;
    x = nx;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}