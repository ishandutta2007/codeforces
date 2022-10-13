#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int m, n;
vector<vector<int>> initialSum;
string a[N];

int getSum(int x, int y, int xx, int yy)
{
  return initialSum[xx][yy] + initialSum[x - 1][y - 1] - initialSum[x - 1][yy] - initialSum[xx][y - 1];
}

int isGood(int t)
{
  vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
  for (int i = t + 1; i + t <= m; i++)
    for (int j = t + 1; j + t <= n; j++)
      if (getSum(i - t, j - t, i + t, j + t) == (t * 2 + 1) * (t * 2 + 1))
      {
        sum[i - t][j - t]++;
        if (i + t < m)
          sum[i + t + 1][j - t]--;
        if (j + t < n)
          sum[i - t][j + t + 1]--;
        if (i + t < m && j + t < n)
          sum[i + t + 1][j + t + 1]++;
      }

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if ((sum[i][j] > 0) ^ (a[i][j] == 'X'))
        return 0;
    }

  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  initialSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++)
  {
    cin >> a[i];
    a[i] = " " + a[i];
    for (int j = 1; j <= n; j++)
    {
      initialSum[i][j] = initialSum[i - 1][j] + initialSum[i][j - 1] - initialSum[i - 1][j - 1];
      initialSum[i][j] += a[i][j] == 'X';
    }
  }

  int low = 1, high = min(m, n) / 2, ans = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (isGood(mid))
    {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }

  cout << ans << '\n';
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
      if (i > ans && i + ans <= m && j > ans && j + ans <= n &&
          getSum(i - ans, j - ans, i + ans, j + ans) == (ans * 2 + 1) * (ans * 2 + 1))  cout << 'X';
      else cout << '.';
    cout << '\n';
  }
}