#include <bits/stdc++.h>
using namespace std;

int n, edges[55];
vector<int> a[55];
vector<double> f[55];
double c[55][55];

void dfs(int x, int par)
{
  edges[x] = 0;
  f[x] = vector<double>(n, 0);
  f[x][0] = 1;

  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);

      // merge subtree y and edge (x, y)
      vector<double> fy(n, 0);
      for (int i = 0; i <= edges[y] + 1; i++) // the first i edges will be shrunk before (x, par)
        for (int j = 0; j <= edges[y]; j++) // (x, y) is the j-th shrunk edge
          if (j < i) fy[i] += f[y][i - 1] / (edges[y] + 1); // (x, y) doesn't matter
          else fy[i] += 0.5 * f[y][j] / (edges[y] + 1);

      // merge subtree y + (x, y) into subtree x
      vector<double> newF(n, 0);
      for (int i = 0; i <= edges[x]; i++)
        for (int j = 0; j <= edges[y] + 1; j++)
        {
          double ways = c[i + j][i] * c[edges[x] + edges[y] + 1 - i - j][edges[x] - i] / c[edges[x] + edges[y] + 1][edges[x]];
          newF[i + j] += f[x][i] * fy[j] * ways;
        }
      f[x] = newF;

      edges[x] += edges[y] + 1;
    }
}

int main()
{
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? c[i - 1][j - 1] + c[i - 1][j] : 1;

  for (int x = 1; x <= n; x++)
  {
    dfs(x, 0);
    cout << fixed << setprecision(12) << f[x][0] << endl;
  }
}