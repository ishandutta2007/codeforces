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

int main() {
  int n; string s; cin >> n >> s;
  if ((n & 1) || count(ALL(s), '(') != n / 2) {
    cout << "-1\n";
    return 0;
  }
  vector<int> depth(n);
  depth[0] = s[0] == '(' ? 1 : -1;
  FOR(i, 1, n) depth[i] = depth[i - 1] + (s[i] == '(' ? 1 : -1);
  int ans = 0;
  for (int i = 0; i < n;) {
    if (depth[i] >= 0) {
      ++i;
      continue;
    }
    int j = i + 1;
    while (j < n && depth[j] < 0) ++j;
    ans += j - i + 1;
    i = j + 1;
  }
  cout << ans << '\n';
  return 0;
}