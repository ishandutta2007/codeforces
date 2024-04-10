#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int MAX = 10100;
const int oo = 1 << 30;

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
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];

    vector<int> f(MAX, oo);
    f[0] = 0;
    for (int i = 0, sum = 0; i < n; i++)
    {
      vector<int> newF(MAX, oo);
      for (int s = 0; s < MAX; s++)
        if (f[s] < oo)
          for (int j = 0; j < 2; j++)
          {
            int ss = s + a[j][i];
            newF[ss] = min(newF[ss], f[s] + s * a[j][i] + (sum - s) * a[j ^ 1][i]);
          }

      sum += a[0][i] + a[1][i];
      swap(f, newF);
    }

    int ans = *min_element(begin(f), end(f)) * 2;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++)
        ans += (n - 1) * a[i][j] * a[i][j];
    cout << ans << endl;
  }
}