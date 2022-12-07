#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

long long n;
int m;
int dig[10], d[10];
int digm[10];
long long dp[100000][100];
int dpp[100000];
int p[20];

int main()
{
  cin >> n >> m;
  for (int i = 0; i < 10; ++i)
    dig[i] = 0;
  while (n) {
    ++dig[n % 10];
    n /= 10;
  }
  digm[0] = 1;
  for (int i = 1; i < 10; ++i)
    digm[i] = digm[i - 1] * (dig[i - 1] + 1);
  int start = 0;
  for (int i = 0; i < 10; ++i)
    start += dig[i] * digm[i];
  for (int i = 0; i <= start; ++i)
    for (int j = 0; j < m; ++j)
      dp[i][j] = 0;
  dp[start][0] = 1;
  dpp[start] = 0;
  p[0] = 1;
  for (int i = 1; i <= 18; ++i)
    p[i] = (p[i - 1] * 10) % m;
  int newj, nz, newi;
  for (int i = start; i > 0; --i) {
    nz = 0;
    for (int j = 0; j < 10; ++j) {
      d[j] = (i / digm[j]) % (dig[j] + 1);
      if (j)
        nz += d[j];
    }
    if ((nz < 2) && d[0])
      nz = 1;
    else
      nz = 10;
    for (int j = 0; j < m; ++j) if (dp[i][j]) {
      for (int k = 0; k < nz; ++k)
        if (d[k]) {
          newj = (j + p[dpp[i]] * k) % m;
          newi = i - digm[k];
          dp[newi][newj] += dp[i][j];
          dpp[newi] = dpp[i] + 1;
        }
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}