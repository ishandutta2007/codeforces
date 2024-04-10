#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    vector<vector<int>> l(n, vector<int>(n));
    vector<vector<int>> r(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        l[i][j] = a[i] > a[j];
        if (j)
          l[i][j] += l[i][j - 1];
      }
      for (int j = i + 1; j < n; j++)
      {
        r[i][j] = a[i] > a[j];
        if (j)
          r[i][j] += r[i][j - 1];
      }
    }

    long long ans = 0;
    for (int i = 1; i < n - 1; i++)
      for (int j = i + 1; j < n - 1; j++)
        ans += l[j][i - 1] * (r[i][n - 1] - r[i][j]);
    cout << ans << '\n';
  }
}