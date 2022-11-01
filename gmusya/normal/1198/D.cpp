#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> v3i;
typedef vector <v3i> v4i;

vvi mat;

int get(int x1, int y1, int x2, int y2) {
  x1--, y1--;
  int ans = mat[x2][y2];
  if (x1 >= 0)
    ans -= mat[x1][y2];
  if (y1 >= 0)
    ans -= mat[x2][y1];
  if (x1 >= 0 && y1 >= 0)
    ans += mat[x1][y1];
  return ans;
}

v4i dp;

int solve(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2)
    return 0;
  if (dp[x1][y1][x2][y2] != -1)
    return dp[x1][y1][x2][y2];
  dp[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
  for (int c = x1; c <= x2; c++) {
    int g = get(c, y1, c, y2);
    if (g)
      continue;
    dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], solve(x1, y1, c - 1, y2) + solve(c + 1, y1, x2, y2));
  }
  for (int r = y1; r <= y2; r++) {
    int g = get(x1, r, x2, r);
    if (g)
      continue;
    dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], solve(x1, y1, x2, r - 1) + solve(x1, r + 1, x2, y2));
  }
  return dp[x1][y1][x2][y2];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  mat.resize(n, vi(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == '#')
        mat[i][j] = 1;
    }
  for (int i = 1; i < n; i++)
    mat[0][i] += mat[0][i - 1];
  for (int i = 1; i < n; i++)
    mat[i][0] += mat[i - 1][0];
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++)
      mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
  dp.resize(n, v3i(n, vvi(n, vi(n, -1))));
  cout << solve(0, 0, n - 1, n - 1);
  return 0;
}