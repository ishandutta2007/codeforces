#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, m, n, a[22][2020];
  cin >> test;
  while (test--)
  {
    cin >> m >> n;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];

    vector<int> f(1 << m, 0);
    for (int j = 0; j < n; j++)
    {
      vector<int> newF = f;
      for (int shift = 0; shift < m; shift++)
      {
        vector<int> sum(1 << m, 0);
        for (int mask = 1; mask < 1 << m; mask++)
          for (int i = 0; i < m; i++)
            if (mask >> i & 1)
              sum[mask] += a[(i + shift) % m][j];

        for (int mask = 1; mask < 1 << m; mask++)
          for (int submask = mask; submask; submask = (submask - 1) & mask)
            newF[mask] = max(newF[mask], f[mask ^ submask] + sum[submask]);
      }
      f = newF;
    }

    cout << f[(1 << m) - 1] << endl;
  }
}