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

constexpr int M = 3;

void solve() {
  int n; cin >> n;
  string s[M]; REP(i, M) cin >> s[i];
  int cnt[M][2]{};
  REP(i, M) {
    cnt[i][0] = count(ALL(s[i]), '0');
    cnt[i][1] = n * 2 - cnt[i][0];
  }
  REP(i, M) FOR(j, i + 1, M) REP(k, 2) {
    if (min(cnt[i][k], cnt[j][k]) >= n) {
      vector<int> pos_i, pos_j;
      REP(x, n * 2) {
        if (pos_i.size() < n && s[i][x] == '0' + k) pos_i.emplace_back(x);
        if (pos_j.size() < n && s[j][x] == '0' + k) pos_j.emplace_back(x);
      }
      vector<string> sub_i(n + 1, ""), sub_j(n + 1, "");
      sub_i[0] = s[i].substr(0, pos_i[0]);
      sub_j[0] = s[j].substr(0, pos_j[0]);
      FOR(x, 1, n) {
        sub_i[x] = s[i].substr(pos_i[x - 1] + 1, pos_i[x] - pos_i[x - 1] - 1);
        sub_j[x] = s[j].substr(pos_j[x - 1] + 1, pos_j[x] - pos_j[x - 1] - 1);
      }
      sub_i[n] = s[i].substr(pos_i[n - 1] + 1);
      sub_j[n] = s[j].substr(pos_j[n - 1] + 1);
      REP(x, n + 1) {
        cout << sub_i[x] << sub_j[x];
        if (x == n) {
          cout << '\n';
        } else {
          cout << char('0' + k);
        }
      }
      return;
    }
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}