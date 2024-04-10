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
  int n; string s; cin >> n >> s;
  int z = count(ALL(s), '0');
  if (equal(ALL(s), s.rbegin())) {
    if (n % 2 == 1 && s[n / 2] == '0') {
      cout << (z == 1 ? "BOB\n" : "ALICE\n");
    } else {
      cout << "BOB\n";
    }
  } else {
    // map<tuple<string, bool, bool>, int> dp;
    // auto f = [&](auto &&f, string t, bool rev, bool is_alice) -> int {
    //   if (dp.count({t, rev, is_alice}) == 1) return dp[{t, rev, is_alice}];
    //   if (count(ALL(t), '0') == 0) return 0;
    //   int &d = dp[{t, rev, is_alice}];
    //   if (is_alice) {
    //     d = INF;
    //     if (!rev && !equal(ALL(t), t.rbegin())) chmin(d, f(f, t, true, !is_alice));
    //     REP(i, n) {
    //       if (t[i] == '0') {
    //         t[i] = '1';
    //         chmin(d, f(f, t, false, !is_alice) + 1);
    //         t[i] = '0';
    //       }
    //     }
    //   } else {
    //     d = -INF;
    //     if (!rev && !equal(ALL(t), t.rbegin())) chmax(d, f(f, t, true, !is_alice));
    //     REP(i, n) {
    //       if (t[i] == '0') {
    //         t[i] = '1';
    //         chmax(d, f(f, t, false, !is_alice) - 1);
    //         t[i] = '0';
    //       }
    //     }
    //   }
    //   return d;
    // };
    // if (int res = f(f, s, false, true); res == 0) {
    //   assert(n == 3 && s[n / 2] == '0' && z == n - 1);
    // } else {
    //   assert(res < 0 && !(n == 3 && s[n / 2] == '0' && z == n - 1));
    // }
    cout << (n % 2 == 1 && s[n / 2] == '0' && z == 2 ? "DRAW\n" : "ALICE\n");
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}