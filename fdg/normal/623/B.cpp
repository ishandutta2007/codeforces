#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, a, b;
int arr[1000006];

const long long inf = 2e+18;
long long ans = inf;

set<int> f;

void force(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      f.insert(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1)
      f.insert(x);
}  

long long dp[3][1000006];

inline void update(long long &r, long long a) {
  if (r > a) r = a;
}

void solve() {
  f.clear();
  force(arr[0] - 1);
  force(arr[0]);
  force(arr[0] + 1);

  for (int x : f) {
    int index = 0;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      index = i;
      long long mn = min(dp[0][i], min(dp[1][i], dp[2][i]));
      if (mn >= ans) break;
      
      int rem = arr[i] % x;
      for (int j = 0; j < 3; ++j) {
        if (dp[j][i] >= ans) continue;

        if (rem == 0) {
          update(dp[j == 0 ? 0 : 2][i + 1], dp[j][i]);
        }
        if (rem == 1 || rem == x - 1) {
          update(dp[j == 0 ? 0 : 2][i + 1], dp[j][i] + b);
        }
        if (j == 1 || j == 0) {
          update(dp[1][i + 1], dp[j][i] + a);
        }
      }
    }

    // cout << x << "  " << min(dp[0][n], min(dp[1][n], dp[2][n])) << endl;
    ans = min(ans, min(dp[0][n], min(dp[1][n], dp[2][n])));

    for (int i = 0; i <= index + 2; ++i) {
      dp[0][i] = dp[1][i] = dp[2][i] = inf;
    } 
  }
}

int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 3; ++j)
      dp[j][i] = inf;
  }

  solve();
  reverse(arr, arr + n);
  solve();

  cout << ans << endl;
  return 0;
}