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
  string s; cin >> s;
  int n = s.length();
  int fr = 0, ba = n - 1;
  vector<int> ans;
  while (fr < ba) {
    while (fr < ba && s[fr] == ')') ++fr;
    while (fr < ba && s[ba] == '(') --ba;
    if (fr < ba) {
      ans.emplace_back(fr++);
      ans.emplace_back(ba--);
    }
  }
  if (ans.empty()) {
    cout << "0\n";
  } else {
    sort(ALL(ans));
    cout << "1\n" << ans.size() << '\n';
    REP(i, ans.size()) cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
  }
  return 0;
}