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

const int Inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> p(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
      cin >> p[i];
    }
    vector <vector <vector <int>>> dp(n + 1, vector <vector <int>> (n + 1, vector <int> (2, Inf)));
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int who = 0; who < 2; ++who) {
          if (i + 1 <= n) {
            int x = p[i + j];
            if (who == 0) {
              dp[i + 1][j][who] = min(dp[i + 1][j][who], max(dp[i][j][who], x));
            } else {
              if (x > dp[i][j][who]) {
                dp[i + 1][j][who ^ 1] = min(dp[i + 1][j][who ^ 1], x);
              }
            }
          } 
          if (j + 1 <= n) {
            int x = p[i + j];
            if (who == 1) {
              dp[i][j + 1][who] = min(dp[i][j + 1][who], max(dp[i][j][who], x));
            } else {
              if (x > dp[i][j][who]) {
                dp[i][j + 1][who ^ 1] = min(dp[i][j + 1][who ^ 1], x);
              }
            }
          }
        }
      }
    }
    if (dp[n][n][0] != Inf || dp[n][n][1] != Inf) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}