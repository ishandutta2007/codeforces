#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, m, n, a[22][2020];
  vector<int> parMasks[1 << 12];
  cin >> test;
  while (test--)
  {
    cin >> m >> n;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];

    for (int mask = 1; mask < 1 << m; mask++)
    {
      parMasks[mask].clear();
      for (int submask = mask; submask; submask = (submask - 1) & mask)
        parMasks[submask].push_back(mask);
    }

    vector<pair<int, int>> cols;
    for (int j = 0; j < n; j++)
    {
      int maxCol = 0;
      for (int i = 0; i < m; i++)
        maxCol = max(maxCol, a[i][j]);
      cols.push_back({maxCol, j});
    }

    sort(cols.begin(), cols.end(), greater<pair<int, int>>());
    vector<int> isGoodCol(n, 0);
    for (int i = 0; i < min(m, n); i++)
      isGoodCol[cols[i].second] = 1;

    vector<int> f(1 << m, 0);
    for (int j = 0; j < n; j++)
      if (isGoodCol[j])
      {
        vector<int> newF = f;
        for (int mask = 1; mask < 1 << m; mask++)
        {
          int bestSum = 0;
          for (int shift = 0; shift < m; shift++)
          {
            int sum = 0;
            for (int i = 0; i < m; i++)
              if (mask >> i & 1)
                sum += a[(i + shift) % m][j];
            bestSum = max(bestSum, sum);
          }

          for (int parMask : parMasks[mask])
            newF[parMask] = max(newF[parMask], f[parMask ^ mask] + bestSum);
        }
        f = newF;
      }

    cout << f[(1 << m) - 1] << endl;
  }
}