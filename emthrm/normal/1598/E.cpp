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
  int n, m, q; cin >> n >> m >> q;
  vector fr(n, vector(m, 1));
  ll ans = 0;
  for (int j = 0; j < m; j += 2) {
    int y = 0, x = j, len = 1;
    bool to_right = true;
    while (true) {
      if (to_right) {
        ++x;
        if (x == m) break;
      } else {
        ++y;
        if (y == n) break;
      }
      ++len;
      to_right = !to_right;
    }
    ans += len * (len + 1LL) / 2;
  }
  for (int i = 1; i < n; i += 2) {
    int y = i, x = 0, len = 1;
    bool to_right = false;
    while (true) {
      if (to_right) {
        ++x;
        if (x == m) break;
      } else {
        ++y;
        if (y == n) break;
      }
      ++len;
      to_right = !to_right;
    }
    ans += len * (len + 1LL) / 2;
  }
  for (int j = 1; j < m; j += 2) {
    int y = 0, x = j, len = 1;
    bool to_right = true;
    while (true) {
      if (to_right) {
        ++x;
        if (x == m) break;
      } else {
        ++y;
        if (y == n) break;
      }
      ++len;
      to_right = !to_right;
    }
    ans += len * (len + 1LL) / 2;
  }
  for (int i = 0; i < n; i += 2) {
    int y = i, x = 0, len = 1;
    bool to_right = false;
    while (true) {
      if (to_right) {
        ++x;
        if (x == m) break;
      } else {
        ++y;
        if (y == n) break;
      }
      ++len;
      to_right = !to_right;
    }
    ans += len * (len + 1LL) / 2;
  }
  ans -= n * m;
  while (q--) {
    int r, c; cin >> r >> c; --r; --c;
    {
      int y = r, x = c + 1, len1 = 0;
      bool to_right = false;
      while (0 <= y && y < n && 0 <= x && x < m && fr[y][x]) {
        ++len1;
        if (to_right) {
          ++x;
        } else {
          ++y;
        }
        to_right = !to_right;
      }
      y = r - 1; x = c;
      int len2 = 0;
      bool to_left = true;
      while (0 <= y && y < n && 0 <= x && x < m && fr[y][x]) {
        ++len2;
        if (to_left) {
          --x;
        } else {
          --y;
        }
        to_left = !to_left;
      }
      if (fr[r][c]) {
        ans -= (len1 + len2 + 1LL) * (len1 + len2 + 2) / 2;
        ans += len1 * (len1 + 1LL) / 2;
        ans += len2 * (len2 + 1LL) / 2;
      } else {
        ans -= len1 * (len1 + 1LL) / 2;
        ans -= len2 * (len2 + 1LL) / 2;
        ans += (len1 + len2 + 1LL) * (len1 + len2 + 2) / 2;
      }
    }
    {
      int y = r + 1, x = c, len1 = 0;
      bool to_right = true;
      while (0 <= y && y < n && 0 <= x && x < m && fr[y][x]) {
        ++len1;
        if (to_right) {
          ++x;
        } else {
          ++y;
        }
        to_right = !to_right;
      }
      y = r; x = c - 1;
      int len2 = 0;
      bool to_left = false;
      while (0 <= y && y < n && 0 <= x && x < m && fr[y][x]) {
        ++len2;
        if (to_left) {
          --x;
        } else {
          --y;
        }
        to_left = !to_left;
      }
      if (fr[r][c]) {
        ans -= (len1 + len2 + 1LL) * (len1 + len2 + 2) / 2;
        ans += len1 * (len1 + 1LL) / 2;
        ans += len2 * (len2 + 1LL) / 2;
      } else {
        ans -= len1 * (len1 + 1LL) / 2;
        ans -= len2 * (len2 + 1LL) / 2;
        ans += (len1 + len2 + 1LL) * (len1 + len2 + 2) / 2;
      }
    }
    if (fr[r][c]) {
      ++ans;
    } else {
      --ans;
    }
    cout << ans << '\n';
    fr[r][c] ^= 1;
  }
  return 0;
}