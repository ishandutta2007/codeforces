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
  vector<vector<int>> graph(n * 2);
  REP(_, n * 2) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  ll ans = 0;
  REP(l, n) FOR(r, l, n) ans += r - l + 1;
  ans = ans * n * (n + 1) / 2 * 2;
  vector<int> is_visited(n * 2, false);
  REP(i, n) {
    if (is_visited[i]) continue;
    vector<int> cycle{i};
    while (true) {
      is_visited[cycle.back()] = true;
      if (!is_visited[graph[cycle.back()][0]]) {
        const int nxt = graph[cycle.back()][0];
        cycle.emplace_back(nxt);
      } else if (!is_visited[graph[cycle.back()][1]]) {
        const int nxt = graph[cycle.back()][1];
        cycle.emplace_back(nxt);
      } else {
        break;
      }
    }
    const int len = cycle.size();
    assert(len % 2 == 0);
    REP(cent, len) {
      int min_l = n, max_l = -1, min_r = n * 2, max_r = n - 1;
      REP(i, len / 2) {
        if (const int ver = cycle[(cent - i + len) % len]; ver < n) {
          chmin(min_l, ver);
          chmax(max_l, ver);
        } else {
          chmin(min_r, ver);
          chmax(max_r, ver);
        }
        if (const int ver = cycle[(cent + i) % len]; ver < n) {
          chmin(min_l, ver);
          chmax(max_l, ver);
        } else {
          chmin(min_r, ver);
          chmax(max_r, ver);
        }
        int el1 = cycle[(cent - (i + 1) + len) % len];
        if (el1 < n) {
          if (min_l <= el1 && el1 <= max_l) continue;
        } else {
          if (min_r <= el1 && el1 <= max_r) continue;
        }
        int el2 = cycle[(cent + i + 1) % len];
        if (el2 < n) {
          if (min_l <= el2 && el2 <= max_l) continue;
        } else {
          if (min_r <= el2 && el2 <= max_r) continue;
        }
        if (el1 > el2) swap(el1, el2);
        int lb_l = 0, ub_l = n - 1, ways_l = 0;
        if (min_l == n) {
          if (el2 < n) {
            ways_l = el1 * (el1 + 1) / 2 +
                     (el2 - el1 - 1) * (el2 - el1) / 2 +
                     (n - el2 - 1) * (n - el2) / 2;
          } else if (el1 < n) {
            ways_l = el1 * (el1 + 1) / 2 + (n - el1 - 1) * (n - el1) / 2;
          } else {
            ways_l = n * (n + 1) / 2;
          }
        } else {
          if (el1 < n) {
            if (el1 < min_l) {
              chmax(lb_l, el1 + 1);
            } else {
              chmin(ub_l, el1 - 1);
            }
          }
          if (el2 < n) {
            if (el2 < min_l) {
              chmax(lb_l, el2 + 1);
            } else {
              chmin(ub_l, el2 - 1);
            }
          }
          ways_l = (min_l - lb_l + 1) * (ub_l - max_l + 1);
        }
        int lb_r = n, ub_r = n * 2 - 1, ways_r = 0;
        if (min_r == n * 2) {
          if (el1 >= n) {
            ways_r = (el1 - n) * (el1 - n + 1) / 2 +
                     (el2 - el1 - 1) * (el2 - el1) / 2 +
                     (n * 2 - el2 - 1) * (n * 2 - el2) / 2;
          } else if (el2 >= n) {
            ways_r = (el1 - n) * (el1 - n + 1) / 2 + (n * 2 - el1 - 1) * (n * 2 - el1) / 2;
          } else {
            ways_r = n * (n + 1) / 2;
          }
        } else {
          if (el1 >= n) {
            if (el1 < min_r) {
              chmax(lb_r, el1 + 1);
            } else {
              chmin(ub_r, el1 - 1);
            }
          }
          if (el2 >= n) {
            if (el2 < min_r) {
              chmax(lb_r, el2 + 1);
            } else {
              chmin(ub_r, el2 - 1);
            }
          }
          ways_r = (min_r - lb_r + 1) * (ub_r - max_r + 1);
        }
        ans -= 1LL * ways_l * ways_r;
      }
    }
  }
  cout << ans / 2 << '\n';
  return 0;
}