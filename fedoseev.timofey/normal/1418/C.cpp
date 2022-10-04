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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector <vector <int>> dp(n + 1, vector <int> (2, n));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int t = 0; t < 2; ++t) {
        if (t == 1) {
          if (i + 1 <= n) dp[i + 1][t ^ 1] = min(dp[i + 1][t ^ 1], dp[i][t]);
          if (i + 2 <= n) dp[i + 2][t ^ 1] = min(dp[i + 2][t ^ 1], dp[i][t]);
        } else {
          if (i + 1 <= n) dp[i + 1][t ^ 1] = min(dp[i + 1][t ^ 1], dp[i][t] + a[i]);
          if (i + 2 <= n) dp[i + 2][t ^ 1] = min(dp[i + 2][t ^ 1], dp[i][t] + a[i] + a[i + 1]);
        }   
      }
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
  }
}