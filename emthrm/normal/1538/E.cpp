#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

const string HAHA = "haha";

string trim(const string &s) {
  int n = s.length();
  return n >= 6 ? s.substr(0, 3) + '*' + s.substr(n - 3) : s;
}

void solve() {
  int n; cin >> n;
  map<string, pair<ll, string>> variable;
  ll ans = 0;
  REP(i, n) {
    string var, op; cin >> var >> op;
    if (op == ":=") {
      string hello; cin >> hello;
      int len = hello.length(), haha = 0;
      for (int i = 0; i + HAHA.length() <= len; ++i) {
        haha += hello.substr(i, HAHA.length()) == HAHA;
      }
      ans = haha;
      variable[var] = {haha, trim(hello)};
    } else if (op == "=") {
      string a, b; cin >> a >> op >> b;
      ll haha = variable[a].first + variable[b].first;
      string s = variable[a].second + variable[b].second;
      for (int i = max(int(variable[a].second.length()) - 3, 0);
           i + HAHA.length() <= s.length() && i < variable[a].second.length(); ++i) {
        haha += s.substr(i, HAHA.length()) == HAHA;
      }
      ans = haha;
      variable[var] = {haha, trim(s)};
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}