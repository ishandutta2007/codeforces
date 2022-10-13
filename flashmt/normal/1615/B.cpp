#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<int>> cnt(20, vector<int>(2e5 + 5));
  for (int i = 1; i <= 2e5; i++)
    for (int j = 0; j < 20; j++)
      cnt[j][i] = cnt[j][i - 1] + (i >> j & 1);

  int test;
  cin >> test;
  while (test--)
  {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = 0; i < 20; i++)
      ans = max(ans, cnt[i][r] - cnt[i][l - 1]);
    cout << r - l + 1 - ans << '\n';
  }
}