#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

struct Matrix {
  int m, n;
  vector<vector<long long>> a;

  Matrix(int m, int n): m(m), n(n)
  {
    a = vector<vector<long long>>(m, vector<long long>(n, 0));
  }

  Matrix operator+(const Matrix &u)
  {
    Matrix res(m, n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        res.a[i][j] = (a[i][j] + u.a[i][j]) % BASE;
    return res;
  }

  Matrix operator*(const Matrix &u)
  {
    Matrix res(m, u.n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < u.n; k++)
          res.a[i][k] = (res.a[i][k] + a[i][j] * u.a[j][k]) % BASE;
    return res;
  }
};

vector<Matrix> cells, sumCells(30, Matrix(64, 64));
int f[3][3];

Matrix computeCell(int f[])
{
  Matrix cell(64, 64);
  for (int i = 0; i < 64; i++)
  {
    int flag[4] = {0}, tmp = i;
    for (int j = 2; j >= 0; j--)
    {
      if (f[j])
        flag[tmp % 4] = 1;
      tmp /= 4;
    }

    int grundy = 0;
    while (flag[grundy])
      grundy++;

    int ii = i / 4 + grundy * 16;
    cell.a[i][ii]++;
  }
  return cell;
}

Matrix power(Matrix matrix, int p)
{
  for (int i = 0; i < 30; i++)
    if (p >> i & 1)
      matrix = matrix * sumCells[i];
  return matrix;
}

vector<long long> solveStrip(int length, vector<pair<int, int>> strip)
{
  sort(strip.begin(), strip.end());
  int last = 0;
  Matrix res(1, 64);
  res.a[0][3 + 3 * 4] = 3;
  for (auto u : strip)
    if (!u.first) res.a[0][3 + 3 * 4] = 1;
    else
    {
      res = power(res, u.first - last - 1);
      res = res * cells[u.second];
      last = u.first;
    }

  res = power(res, length - last);
  vector<long long> dp(4, 0);
  for (int i = 0; i < 64; i++)
    dp[i / 16] = (dp[i / 16] + res.a[0][i]) % BASE;
  return dp;
}

int main()
{
  int n, a[1010], m, x, y, c;
  vector<pair<int, int>> strips[1010];

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }

  cin >> m;
  while (m--)
  {
    cin >> x >> y >> c;
    strips[--x].push_back({--y, --c});
  }

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> f[i][j];

  for (int i = 0; i < 3; i++)
  {
    cells.push_back(computeCell(f[i]));
    sumCells[0] = sumCells[0] + cells.back();
  }
  for (int i = 1; i < 30; i++)
    sumCells[i] = sumCells[i - 1] * sumCells[i - 1];

  long long dp[1010][4] = {0};
  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
  {
    auto cur = solveStrip(a[i], strips[i]);
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        dp[i + 1][j] = (dp[i + 1][j] + cur[k] * dp[i][j ^ k]) % BASE;
  }

  cout << (dp[n][0]) % BASE << endl;
}