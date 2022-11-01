#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

mt19937 rnd(time(0));

int get(vvi &mat, int x1, int y1, int x2, int y2) {
  x1--, y1--;
  int res = 0;
  res += mat[x2][y2];
  if (x1 >= 0)
    res -= mat[x1][y2];
  if (y1 >= 0)
    res -= mat[x2][y1];
  if (x1 >= 0 && y1 >= 0)
    res += mat[x1][y1];
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi mat(n, vi(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      mat[i][j] = c - 'a';
    }
  vector <int> h(26);
  for (int i = 0; i < 26; i++)
    h[i] = rnd();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      mat[i][j] = h[mat[i][j]];
  vvi diag1(n + m, vi(n + m)), diag2(n + m, vi(n + m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if ((i + j) & 1)
        diag1[(i + j) / 2][(i + m - j - 1) / 2] = mat[i][j];
      else
        diag2[(i + j) / 2][(i + m - j - 1) / 2] = mat[i][j];
    }

  for (int i = 0; i < n + m; i++)
    for (int j = 1; j < n + m; j++)
      diag1[i][j] += diag1[i][j - 1], diag2[i][j] += diag2[i][j - 1];
  for (int j = 0; j < n + m; j++)
    for (int i = 1; i < n + m; i++)
      diag1[i][j] += diag1[i - 1][j], diag2[i][j] += diag2[i - 1][j];
  vvi ans(n, vi(m));
  for (int row = 0; row < n; row++)
    for (int col = 0; col < m; col++) {
      int L = 0, R = min({row, col, n - row - 1, m - col - 1});
      if (row) {
        L = max(L, ans[row - 1][col] - 1);
        R = min(R, ans[row - 1][col] + 1);
      }
      if (col) {
        L = max(L, ans[row][col - 1] - 1);
        R = min(R, ans[row][col - 1] + 1);
      }
      while (L < R) {
        int M = (L + R + 1) / 2;
        bool flag = true;
        int x1 = row - M, y1 = col;
        int x2 = row + M, y2 = col;
        int _x1 = (x1 + y1) / 2, _y1 = (x1 + m - y1 - 1) / 2;
        int _x2 = (x2 + y2) / 2, _y2 = (x2 + m - y2 - 1) / 2;
        int sum = get((x1 + y1) & 1 ? diag1 : diag2, _x1, _y1, _x2, _y2);
        if (sum != (_x2 - _x1 + 1) * (_y2 - _y1 + 1) * mat[row][col])
          flag = false;
        x1 = row - (M - 1), y1 = col;
        x2 = row + (M - 1), y2 = col;
        _x1 = (x1 + y1) / 2, _y1 = (x1 + m - y1 - 1) / 2;
        _x2 = (x2 + y2) / 2, _y2 = (x2 + m - y2 - 1) / 2;
        sum = get((x1 + y1) & 1 ? diag1 : diag2, _x1, _y1, _x2, _y2);
        if (sum != (_x2 - _x1 + 1) * (_y2 - _y1 + 1) * mat[row][col])
          flag = false;
        if (flag)
          L = M;
        else
          R = M - 1;
      }
      ans[row][col] = L;
    }
  int answer = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      answer += ans[i][j] + 1;
  cout << answer;
  return 0;
}