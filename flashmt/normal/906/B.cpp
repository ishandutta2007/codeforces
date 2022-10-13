#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  if (m <= 3 && n <= 3)
  {
    vector<vector<int>> bad(n * m, vector<int>(n * m));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
      {
        int u = i * n + j;
        if (i + 1 < m)
          bad[u][u + n] = bad[u + n][u] = 1;
        if (j + 1 < n)
          bad[u][u + 1] = bad[u + 1][u] = 1;
      }

    vector<int> a(m * n);
    iota(begin(a), end(a), 0);
    int found = 0;
    do
    {
      int isGood = 1;
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
          int u = i * n + j;
          if (i + 1 < m && bad[a[u]][a[u + n]])
            isGood = 0;
          if (j + 1 < n && bad[a[u]][a[u + 1]])
            isGood = 0;
        }

      if (isGood)
      {
        found = 1;
        break;
      }
    } while (next_permutation(begin(a), end(a)));

    if (!found) cout << "NO" << endl;
    else
    {
      cout << "YES" << endl;
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          cout << a[i * n + j] + 1 << " \n"[j == n - 1];
    }
  }
  else if (n >= 4)
  {
    cout << "YES" << endl;
    for (int i = 0; i < m; i++)
    {
      vector<int> even, odd;
      for (int j = n - 1; j >= 0; j--)
        if (j % 2) odd.push_back(i * n + j);
        else even.push_back(i * n + j);

      if (i % 2)
      {
        rotate(begin(even), begin(even) + 1, end(even));
        rotate(begin(odd), begin(odd) + 1, end(odd));
        if (n % 2 == 0)
          swap(even, odd);
      }

      for (int x : even)
        cout << x + 1 << ' ';
      for (int x : odd)
        cout << x + 1 << ' ';
      cout << '\n';
    }
  }
  else
  {
    cout << "YES" << endl;
    vector<vector<int>> a(m, vector<int>(n));
    for (int j = 0; j < n; j++)
    {
      vector<int> even, odd;
      for (int i = m - 1; i >= 0; i--)
        if (i % 2) odd.push_back(i * n + j);
        else even.push_back(i * n + j);

      if (j % 2)
      {
        rotate(begin(even), begin(even) + 1, end(even));
        rotate(begin(odd), begin(odd) + 1, end(odd));
        if (m % 2 == 0)
          swap(even, odd);
      }

      int i = 0;
      for (int x : even)
        a[i++][j] = x;
      for (int x : odd)
        a[i++][j] = x;
    }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cout << a[i][j] + 1 << " \n"[j == n - 1];
  }
}