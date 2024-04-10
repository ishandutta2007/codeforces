#include <bits/stdc++.h>
using namespace std;

int m, n, bestCol[300300], bestRow[300300];
string a[300300];

int solveRow(string pattern)
{
  int res = 0;
  for (int i = 0; i < m; i++)
  {
    int cost[2] = {0};
    for (int j = 0; j < n; j++)
      for (int k = 0; k < 2; k++)
      {
        char expectedChar = pattern[(i % 2) * 2 + (j % 2 ^ k)];
        cost[k] += a[i][j] != expectedChar;
      }
    bestRow[i] = cost[1] < cost[0];
    res += cost[bestRow[i]];
  }
  return res;
}

int solveCol(string pattern)
{
  int res = 0;
  for (int j = 0; j < n; j++)
  {
    int cost[2] = {0};
    for (int i = 0; i < m; i++)
      for (int k = 0; k < 2; k++)
      {
        char expectedChar = pattern[(j % 2) * 2 + (i % 2 ^ k)];
        cost[k] += a[i][j] != expectedChar;
      }
    bestCol[j] = cost[1] < cost[0];
    res += cost[bestCol[j]];
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  int ans = m * n + 1, direction = 0;
  string pattern = "ACGT", bestPattern;
  do {
    int costRow = solveRow(pattern);
    if (costRow < ans)
    {
      ans = costRow;
      bestPattern = pattern;
      direction = 0;
    }

    int costCol = solveCol(pattern);
    if (costCol < ans)
    {
      ans = costCol;
      bestPattern = pattern;
      direction = 1;
    }
  } while (next_permutation(pattern.begin(), pattern.end()));

  if (!direction)
  {
    solveRow(bestPattern);
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        cout << bestPattern[(i % 2) * 2 + (j % 2 ^ bestRow[i])];
      cout << '\n';
    }
  }
  else
  {
    solveCol(bestPattern);
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        cout << bestPattern[(j % 2) * 2 + (i % 2 ^ bestCol[j])];
      cout << '\n';
    }
  }
}