#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 1 << 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), cost(n), profit(m + n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n; i++)
    cin >> cost[i];
  for (int i = 0; i < m + n; i++)
    cin >> profit[i];

  vector<vector<int>> f(n + m, vector<int>(n + 1, -oo));
  for (int i = 0; i < n + m; i++)
    f[i][0] = 0;

  for (int id = n - 1; id >= 0; id--)
  {
    int i = a[id];
    for (int k = n; k; k--)
      f[i][k] = max(f[i][k], f[i][k - 1] + profit[i] - cost[id]);

    for (int ii = i, bound = n; ii + 1 < m + n && bound; ii++, bound /= 2)
      for (int k = bound; k; k--)
      {
        int newF = f[ii][k] + profit[ii + 1] * (k / 2);
        f[ii + 1][k / 2] = max(f[ii + 1][k / 2], newF);
      }

    for (int j = 1; j < m + n; j++)
      f[j][0] = max({f[j][0], f[j - 1][0], f[j - 1][1]});
  }

  int ans = 0;
  for (int i = 0; i < m + n; i++)
    ans = max(ans, f[i][1]);

  cout << ans << endl;
}