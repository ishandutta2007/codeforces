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
  int n, m; cin >> n >> m;
  vector<vector<int>> s(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> s[i][j];
  auto out = [&]() {
    cout << "Yes\n";
    REP(j, m) cout << s[0][j] << " \n"[j + 1 == m];
    exit(0);
  };
  vector is_diff(n, vector(m, false));
  vector<vector<int>> diff(n);
  REP(i, n) REP(j, m) {
    if (s[i][j] != s[0][j]) {
      is_diff[i][j] = true;
      diff[i].emplace_back(j);
    }
  }
  auto change2 = [&](int j1, int s_j1, int j2, int s_j2) {
    REP(row, n) {
      int diff_size = diff[row].size();
      if (is_diff[row][j1]) --diff_size;
      diff_size += s[row][j1] != s_j1;
      if (is_diff[row][j2]) --diff_size;
      diff_size += s[row][j2] != s_j2;
      if (diff_size > 2) return;
    }
    s[0][j1] = s_j1;
    s[0][j2] = s_j2;
    out();
  };
  vector<vector<int>> pos3(m);
  vector<int> three;
  FOR(i, 1, n) {
    if (diff[i].size() >= 5) {
      cout << "No\n";
      return 0;
    }
    if (diff[i].size() == 4) {
      REP(x, diff[i].size()) FOR(y, x + 1, diff[i].size()) {
        int j1 = diff[i][x], j2 = diff[i][y];
        change2(j1, s[i][j1], j2, s[i][j2]);
      }
      cout << "No\n";
      return 0;
    }
    if (diff[i].size() == 3) {
      three.emplace_back(i);
      for (int e : diff[i]) pos3[e].emplace_back(i);
    }
  }
  if (three.empty()) out();
  REP(j, m) {
    if (pos3[j].size() != three.size()) continue;
    bool same = true;
    int val = s[pos3[j][0]][j];
    for (int e : pos3[j]) same &= s[e][j] == val;
    if (same) {
      bool ans = true;
      FOR(i, 1, n) {
        if (diff[i].size() == 2 && !is_diff[i][j]) {
          ans = false;
          break;
        }
      }
      if (ans) {
        s[0][j] = val;
        out();
      }
    }
  }
  REP(x, 3) FOR(y, x + 1, 3) {
    int j1 = diff[three[0]][x], j2 = diff[three[0]][y];
    change2(j1, s[three[0]][j1], j2, s[three[0]][j2]);
  }
  REP(x, 3) {
    int i1 = three[0], j1 = diff[i1][x];
    FOR(ot, 1, three.size()) {
      int i2 = three[ot], diff_size = 3;
      if (is_diff[i2][j1]) --diff_size;
      diff_size += s[i2][j1] != s[i1][j1];
      if (diff_size == 4) break;
      if (diff_size == 3) {
        REP(y, 3) {
          int j2 = diff[i2][y];
          if (j2 != j1) change2(j1, s[i1][j1], j2, s[i2][j2]);
        }
        break;
      }
    }
  }
  cout << "No\n";
  return 0;
}