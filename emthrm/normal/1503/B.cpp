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
  int n; cin >> n;
  vector ans(n, vector(n, 0));
  auto query = [&](int b, int i, int j) -> void {
    cout << b << ' ' << i + 1 << ' ' << j + 1 << endl;
    ans[i][j] = b;
  };
  vector<pair<int, int>> p, q;
  REP(i, n) REP(j, n) ((i + j) & 1 ? p : q).emplace_back(i, j);
  while (!p.empty() && !q.empty()) {
    int a; cin >> a;
    if (a == 1) {
      auto [i, j] = q.back();
      q.pop_back();
      query(2, i, j);
    } else {
      auto [i, j] = p.back();
      p.pop_back();
      query(1, i, j);
    }
  }
  if (p.empty()) {
    while (!q.empty()) {
      int a; cin >> a;
      auto [i, j] = q.back();
      q.pop_back();
      query(a == 2 ? 3 : 2, i, j);
    }
  } else {
    while (!p.empty()) {
      int a; cin >> a;
      auto [i, j] = p.back();
      p.pop_back();
      query(a == 1 ? 3 : 1, i, j);
    }
  }
  return 0;
}