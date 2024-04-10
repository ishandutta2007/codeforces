#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 27081993;

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      a[i]--;
    }

    vector<vector<bool>> isGood(n + 2, vector<bool>(n + 2, 1));
    vector<int> cnt(n);
    for (int i = 1; i <= n; i++)
    {
      int maxCnt = 0;
      for (int j = i; j <= n; j++)
      {
        maxCnt = max(maxCnt, ++cnt[a[j]]);
        if (maxCnt * 2 > j - i + 1)
          isGood[i][j] = 0;
      }
      for (int j = i; j <= n; j++)
        cnt[a[j]]--;
    }

    vector<int> f(n + 1, -oo);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i - 1; j >= 0; j -= 2)
        if ((!j || a[i] == a[j]) && isGood[j + 1][i - 1])
          f[i] = max(f[i], f[j] + 1);

    int ans = -oo;
    for (int i = n; i >= 0; i -= 2)
      if (isGood[i + 1][n])
        ans = max(ans, f[i]);

    cout << ans << endl;
  }
}