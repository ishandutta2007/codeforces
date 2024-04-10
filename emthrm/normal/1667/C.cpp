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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  if (n >= 5) {
    const int sec = (n - 5) / 3;
    if (n % 3 == 2) {
      cout << sec * 2 + 3 << '\n';
      REP(i, sec + 2) cout << i + 1 << ' ' << i * 2 + 1 << '\n';
      REP(i, sec + 1) cout << i + sec + 2 + 1 << ' ' << i * 2 + 1 + 1 << '\n';
    } else if (n % 3 == 0) {
      cout << sec * 2 + 4 << '\n';
      cout << 1 << ' ' << 1 << '\n';
      REP(i, sec + 2) cout << i + 1 + 1 << ' ' << i * 2 + 1 + 1 << '\n';
      REP(i, sec + 1) cout << i + sec + 2 + 1 + 1 << ' ' << i * 2 + 1 + 1 + 1 << '\n';
    } else {
      cout << sec * 2 + 5 << '\n';
      cout << 1 << ' ' << 1 << '\n';
      REP(i, sec + 2) cout << i + 1 << ' ' << i * 2 + 1 + 1 << '\n';
      REP(i, sec + 2) cout << i + sec + 2 + 1 << ' ' << i * 2 + 1 << '\n';
    }
    return 0;
  }

  int ans = 1;
  // FOR(n, 1, N) {
    auto is_valid = [&](vector<pair<int, int>>& queens) -> bool {
      set<int> row, col, diag;
      for (const auto [i, j] : queens) {
        row.emplace(i);
        col.emplace(j);
        diag.emplace(i - j);
      }
      REP(i, n) REP(j, n) {
        if (!row.count(i) && !col.count(j) && !diag.count(i - j)) return false;
      }
      // vector s(n, string(n, '.'));
      // for (const auto [i, j] : queens) s[i][j] = '*';
      // REP(i, n) cout << s[i] << '\n';
      cout << queens.size() << '\n';
      for (const auto [i, j] : queens) {
        cout << i + 1 << ' ' << j + 1 << '\n';
      }
      return true;
    };
    for (; ans <= n * n; ++ans) {
      auto f = [&](auto&& f, int i, int j, vector<pair<int, int>>& queens) -> bool {
        if (queens.size() == ans) return is_valid(queens);
        if (i == n && j == 0) return false;
        const auto [ni, nj] = [&]() -> pair<int, int> {
          return j + 1 == n ? make_pair(i + 1, 0) : make_pair(i, j + 1);
        } ();
        queens.emplace_back(i, j);
        const bool res = f(f, ni, nj, queens);
        queens.pop_back();
        if (res) return true;
        return f(f, ni, nj, queens);
      };
      vector<pair<int, int>> queens;
      if (f(f, 0, 0, queens)) break;
    }
  // }
  return 0;
}