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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int l = 0, r = 1e9;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    vector <bool> good(n);
    for (int i = 0; i < n; ++i) good[i] = (a[i] <= m);
    int best = 0;
    for (int par = 0; par <= 1; ++par) {
      vector <vector <int>> dp(n + 1, vector <int> (2));
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
          dp[i][j] = dp[i - 1][j];
        }
        for (int j = 0; j <= 1; ++j) {
          if (good[i - 1]) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j ^ 1] + 1);
          } else {
            if (j == par) {
              dp[i][j] = max(dp[i][j], dp[i - 1][j ^ 1] + 1);
            }
          }
        }
      }   
      best = max(best, dp[n][0]);
      best = max(best, dp[n][1]);
    } 
    if (best >= k) r = m;
    else l = m;
  }
  cout << r << '\n';
}