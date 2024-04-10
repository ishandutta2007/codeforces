#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vvi a(n, vi(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 'W')
        a[i][j] = 1;
    }
  vi left(n, n), right(n, -1), up(n, n), down(n, -1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!a[i][j]) {
        left[i] = min(left[i], j);
        right[i] = max(right[i], j);
        up[j] = min(up[j], i);
        down[j] = max(down[j], i);
      }
  int ans = 0;
  vvi dp(n, vi(n));
  for (int i = 0; i < n; i++) {
    if (left[i] == n) {
      ans++;
    } else {
      int min_row = max(i - k + 1, 0);
      int max_row = min(i, n - 1);
      int min_col = max(right[i] - k + 1, 0);
      int max_col = min(left[i], n - 1);
      if (max_col < min_col)
        continue;
      dp[max_row][max_col]++;
      if (min_row)
        dp[min_row - 1][max_col]--;
      if (min_col)
        dp[max_row][min_col - 1]--;
      if (min_row && min_col)
        dp[min_row - 1][min_col - 1]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (up[i] == n) {
      ans++;
    } else {
      int min_col = max(i - k + 1, 0);
      int max_col = min(i, n - 1);
      int min_row = max(down[i] - k + 1, 0);
      int max_row = min(up[i], n - 1);
      if (max_row < min_row)
        continue;
      dp[max_row][max_col]++;
      if (min_row)
        dp[min_row - 1][max_col]--;
      if (min_col)
        dp[max_row][min_col - 1]--;
      if (min_row && min_col)
        dp[min_row - 1][min_col - 1]++;
    }
  }
  for (int i = n - 1; i >= 1; i--)
    for (int j = n - 1; j >= 0; j--)
      dp[i - 1][j] += dp[i][j];
  for (int i = n - 1; i >= 0; i--)
    for (int j = n - 1; j >= 1; j--)
      dp[i][j - 1] += dp[i][j];
  int answer = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      answer = max(answer, dp[i][j] + ans);
  cout << answer;
  return 0;
}