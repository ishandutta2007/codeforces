#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(2);
  for (int& x : a) {
    cin >> x;
  }
  cnt[0] = n / 2;
  cnt[1] = (n + 1) / 2;
  int const INF = n + 20;
  vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>
  (cnt[0]
  + 2,
          vector<vector<int>>(cnt[1] + 2, vector<int>(2, INF))));
  dp[0][0][0][0] = dp[0][0][0][1] = 0;
  auto relax = [&](int& x, int y) {
    if (y < x) {
      x = y;
      return true;
    }
    return false;
  };
  for (int i = 0; i < n; ++i) {
    for (int x = 0; x <= cnt[0]; ++x) {
      for (int y = 0; y <= cnt[1]; ++y) {
        for (int par : {0, 1}) {
          for (int new_par : {0, 1}) {
            if (dp[i][x][y][par] == INF) {
              continue;
            }
            auto new_x = x;
            auto new_y = y;
            int add = 0;
            if (a[i] > 0) {
              if (new_par != a[i] % 2) {
                continue;
              }
              if (a[i] % 2 == 0) {
                new_x++;
                add += par;
              } else {
                new_y++;
                add += !par;
              }
            } else {
              if (!new_par) {
                new_x++;
                add += par;
              } else {
                new_y++;
                add += !par;
              }
            }
            relax(dp[i + 1][new_x][new_y][new_par], dp[i][x][y][par] + add);
          }
        }
      }
    }
  }
  int ans = INF;
  for (int p : {0, 1}) {
    relax(ans, dp.back()[cnt[0]][cnt[1]][p]);
  }
  cout << ans << '\n';
  return 0;
}