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

int main() {
  string s; ll x, y; cin >> s >> x >> y;
  for (char &c : s) {
    if (c == '?') c = '2';
  }
  int n = s.length();
  vector r(n, vector(3, 0)), l(n, vector(3, 0));
  FOR(i, 1, n) {
    l[i] = l[i - 1];
    ++l[i][s[i - 1] - '0'];
  }
  for (int i = n - 2; i >= 0; --i) {
    r[i] = r[i + 1];
    ++r[i][s[i + 1] - '0'];
  }
  ll cost = 0;
  REP(i, n) {
    if (s[i] == '1') {
      cost += y * (r[i][0] + r[i][2]);
    } else {
      cost += x * r[i][1];
    }
  }
  vector<int> que;
  REP(i, n) {
    if (s[i] == '2') que.emplace_back(i);
  }
  ll ans = cost;
  for (int pos : que) {
    cost -= x * r[pos][1];
    cost -= y * (l[pos][1] + l[pos][2]);
    cost += y * (r[pos][0] + r[pos][2]);
    cost += x * l[pos][0];
    chmin(ans, cost);
  }
  for (int pos : que) {
    cost -= y * r[pos][0];
    cost -= x * (l[pos][0] + l[pos][2]);
    cost += x * (r[pos][1] + r[pos][2]);
    cost += y * l[pos][1];
    chmin(ans, cost);
  }
  cout << ans << '\n';
  return 0;
}