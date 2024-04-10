#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n), pos(n);
    vector<vector<int>> id(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      a[i]--;
      pos[i] = size(id[a[i]]);
      id[a[i]].push_back(i);
    }

    vector<vector<int>> f(n, vector<int>(n));
    for (int len = 2; len <= n; len++)
      for (int i = 0; i + len <= n; i++)
      {
        int j = i + len - 1, x = a[i];
        f[i][j] = f[i + 1][j];
        for (int k = pos[i] + 1; k < size(id[x]); k++)
        {
          int ii = id[x][k];
          if (ii > j)
            break;
          f[i][j] = max(f[i][j], f[i + 1][ii - 1] + f[ii][j] + 1);
        }
      }

    cout << n - 1 - f[0][n - 1] << '\n';
  }
}