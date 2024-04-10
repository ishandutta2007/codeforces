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

void solve() {
  int n; string s, t; cin >> n >> s >> t;
  vector<int> s_i, t_j;
  REP(i, n) {
    if (s[i] != t[i]) {
      FOR(j, i + 1, n) {
        if (s[i] == t[j]) {
          s_i.emplace_back(j);
          t_j.emplace_back(j);
          swap(s[j], t[j]);
        }
        if (s[i] == s[j]) {
          s_i.emplace_back(j);
          t_j.emplace_back(i);
          swap(s[j], t[i]);
          break;
        }
      }
      if (s[i] != t[i]) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
  int m = s_i.size();
  cout << m << '\n';
  REP(i, m) cout << s_i[i] + 1 << ' ' << t_j[i] + 1 << '\n';
}

int main() {
  int k; cin >> k;
  while (k--) solve();
  return 0;
}