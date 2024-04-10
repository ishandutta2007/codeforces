#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 35;

int dp[N][N][2];
int p2[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int d, m;
    cin >> d >> m;
    p2[0] = 1;
    for (int i = 1; i < N; ++i) {
      p2[i] = (ll)2 * p2[i - 1] % m;
    }

    int ans = 0;
    bool fl = false;
    for (int mb = 29; mb >= 0; --mb) {
      if ((1 << mb) > d) continue;

      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          dp[i][j][0] = dp[i][j][1] = 0;
        }
      }

      if (!fl) dp[mb][1][0] = 1;
      else dp[mb][1][1] = 1;
      
      fl = true;

      for (int b = mb - 1; b >= 0; --b) {
        for (int cnt = 1; cnt + 1 < N; ++cnt) {
          for (int f = 0; f < 2; ++f) {
            if (f == 1) {
              dp[b][cnt][1] += ((ll)dp[b + 1][cnt][1] * p2[cnt]) % m;
              dp[b][cnt][1] %= m;
              dp[b][cnt + 1][1] += ((ll)dp[b + 1][cnt][1] * p2[cnt]) % m;
              dp[b][cnt + 1][1] %= m;
            } else {  
              if (!(d & (1 << b))) {
                dp[b][cnt][0] += ((ll)dp[b + 1][cnt][0] * p2[cnt - 1]) % m;
                dp[b][cnt][0] %= m;
                dp[b][cnt + 1][0] += ((ll)dp[b + 1][cnt][0] * p2[cnt - 1]) % m;
                dp[b][cnt + 1][0] %= m;
              }

              if (d & (1 << b)) {
                dp[b][cnt][0] += ((ll)dp[b + 1][cnt][0] * p2[cnt - 1]) % m;
                dp[b][cnt][0] %= m;

                dp[b][cnt][1] += ((ll)dp[b + 1][cnt][0] * p2[cnt - 1]) % m;
                dp[b][cnt][1] %= m;

                dp[b][cnt + 1][0] += ((ll)dp[b + 1][cnt][0] * p2[cnt - 1]) % m;
                dp[b][cnt + 1][0] %= m;

                dp[b][cnt + 1][1] += ((ll)dp[b + 1][cnt][0] * p2[cnt - 1]) % m;
                dp[b][cnt + 1][1] %= m;

              }
            }
          }
        }
      }
      for (int cnt = 1; cnt < N; ++cnt) {
        ans += dp[0][cnt][0];
        ans %= m;
        ans += dp[0][cnt][1];
        ans %= m;
      }
    }
    cout << ans << '\n';
  }
}