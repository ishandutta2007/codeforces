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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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
  constexpr int B = 30;
  int n, q; cin >> n >> q;
  vector<int> is(q), js(q), x(q); REP(i, q) cin >> is[i] >> js[i] >> x[i], --is[i], --js[i];
  vector<int> a(n, 0), must(n, -1), is_fixed(q, false);
  vector<vector<pair<int, int>>> queries(n);
  queue<int> que;
  const auto action = [&]() -> void {
    while (!que.empty()) {
      const int i = que.front(); que.pop();
      if (must[i] == 1) {
        for (const auto& [id, j] : queries[i]) {
          is_fixed[id] = true;
        }
      } else {
        for (const auto& [id, j] : queries[i]) {
          is_fixed[id] = true;
          if (must[j] == -1) {
            must[j] = 1;
            que.emplace(j);
          }
        }
      }
    }
  };
  REP(bit, B) {
    fill(ALL(must), -1);
    fill(ALL(is_fixed), false);
    REP(i, n) queries[i].clear();
    REP(i, q) {
      if (x[i] >> bit & 1) {
        if (is[i] == js[i]) {
          must[is[i]] = 1;
          is_fixed[i] = true;
        } else {
          queries[is[i]].emplace_back(i, js[i]);
          queries[js[i]].emplace_back(i, is[i]);
        }
      } else {
        is_fixed[i] = true;
        must[is[i]] = must[js[i]] = 0;
      }
    }
    REP(i, n) {
      if (must[i] != -1) que.emplace(i);
    }
    action();
    REP(i, n) {
      if (must[i] == -1) {
        must[i] = 0;
        que.emplace(i);
        action();
      }
    }
    REP(i, n) a[i] |= must[i] << bit;
  }
  REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  return 0;
}