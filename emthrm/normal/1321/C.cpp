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
  for (int i = 25; i >= 1; --i) {
    bool is_updated = true;
    while (is_updated) {
      is_updated = false;
      REP(j, s.length()) {
        if (s[j] == 'a' + i && ((j > 0 && s[j - 1] == 'a' + i - 1) || (j + 1 < s.length() && s[j + 1] == 'a' + i - 1))) {
          s.erase(s.begin() + j);
          is_updated = true;
          break;
        }
      }
    }
  }
  cout << n - s.length() << '\n';
  return 0;
}