#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 4040;
const int K = 888;
const int oo = 1 << 30;

int n, k, sum[N][N], f[K][N];

int getCost(int from, int to)
{
  return sum[to][to] + sum[from][from] - sum[from][to] - sum[to][from];
}

void calc(int i, int low, int high, int optL, int optR)
{
  if (low > high)
    return;

  int mid = (low + high) / 2, optM = -1;
  f[i][mid] = oo;
  for (int j = optL; j <= optR; j++)
  {
    int curF = f[i - 1][j] + getCost(j, mid) / 2;
    if (curF < f[i][mid])
    {
      f[i][mid] = curF;
      optM = j;
    }
  }

  calc(i, low, mid - 1, optL, optM);
  calc(i, mid + 1, high, optM, optR);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  char s[10000];
  gets(s);
  for (int i = 0; i < n; i++)
  {
    gets(s);
    for (int j = 0; j < n; j++)
      a[i][j] = s[j * 2] - '0';
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];

  for (int i = 1; i <= n; i++)
    f[0][i] = oo;
  for (int i = 1; i <= k; i++)
    calc(i, 1, n, 0, n);
  cout << f[k][n] << endl;
}