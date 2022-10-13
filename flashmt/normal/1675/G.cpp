#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int oo = 27081993;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> f(m + 1, vector<int>(m * 2 + 1, oo));
  f[m][m] = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    vector<vector<int>> newF(m + 1, vector<int>(m * 2 + 1, oo));
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= m * 2; k++)
        if (f[j][k] != oo)
          for (int jj = 0; jj <= j; jj++)
          {
            int kk = jj - x + k;
            if (kk >= 0 && kk <= m * 2)
              newF[jj][kk] = min(newF[jj][kk], f[j][k] + abs(kk - m));
          }

    swap(f, newF);
  }

  int ans = oo;
  for (int j = 0; j <= m; j++)
    ans = min(ans, f[j][m]);
  cout << ans << endl;
}