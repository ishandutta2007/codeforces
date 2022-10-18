#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005];
long long dp[2][100005];

int main() {
  int n, a;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    arr[a]++;
  }
  long long ans = 0;
  for (int i = 0; i <= 100000; ++i) {
    dp[0][i + 1] = max(dp[0][i + 1], max(dp[1][i], dp[0][i]));
    dp[1][i + 1] = max(dp[1][i + 1], max(dp[1][i], dp[0][i] + 1LL * (i + 1) * arr[i + 1]));
    ans = max(ans, max(dp[0][i + 1], dp[1][i + 1]));
  }
  cout << ans << endl;
  return 0;
}