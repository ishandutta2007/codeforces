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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int q; cin >> q;
  int idx = 0;
  unordered_map<int, unordered_set<int>> pos;
  while (q--) {
    int type, x; cin >> type >> x;
    if (type == 1) {
      pos[x].emplace(idx++);
    } else if (type == 2) {
      int y; cin >> y;
      if (x != y && pos.count(x)) {
        if (pos[x].size() > pos[y].size()) swap(pos[x], pos[y]);
        copy(ALL(pos[x]), inserter(pos[y], pos[y].end()));
        pos.erase(x);
      }
    }
  }
  vector<int> ans(idx);
  for (const auto [num, poss] : pos) {
    for (int p : poss) ans[p] = num;
  }
  REP(i, idx) cout << ans[i] << " \n"[i + 1 == idx];
  return 0;
}