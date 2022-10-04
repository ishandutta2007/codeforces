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
  const int N = 100 * 200 + 1;
  vector <int> pr(N, 1);
  for (int i = 2; i < N; ++i) {
    if (pr[i]) {
      for (int j = 2 * i; j < N; j += i) {
        pr[j] = 0;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    vector <int> idx;
    const int K = 201;
    const int Inf = 1e9;
    vector <vector <int>> dp(n + 1, vector <int> (K, Inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < K; ++j) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        if (j + a[i] < K) {
          dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], dp[i][j] + 1);
        }
      }
    }
    int need = -1, cnt = -1;
    for (int x = 0; x < K; ++x) {
      if (sum - x > 1 && !pr[sum - x]) {
        int cur_cnt = n - dp[n][x];
        if (cur_cnt > cnt) {
          cnt = cur_cnt;
          need = x;
        }
      }
    }
    vector <int> tk(n, 1);
    for (int i = n; i > 0; --i) {
      if (a[i - 1] <= need && dp[i - 1][need - a[i - 1]] + 1 == dp[i][need]) {
        tk[i - 1] = 0;
        need -= a[i - 1];
      }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; ++i) {
      if (tk[i]) {
        cout << i + 1 << ' ';
      }
    }
    cout << '\n';
  }
}