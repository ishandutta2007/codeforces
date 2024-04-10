#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q, a[100100], f[100100][17] = {0}, cnt[100100] = {0};
  vector<int> d[100100];

  for (int i = 2; i <= 1e5; i++)
    if (d[i].empty())
      for (int j = i; j <= 1e5; j += i)
        d[j].push_back(i);

  cin >> n >> q;
  for (int i = 1, j = 1; i <= n; i++)
  {
    cin >> a[i];
    for (int x : d[a[i]])
    {
      while (cnt[x] && j < i)
      {
        for (int y : d[a[j]])
          cnt[y]--;
        j++;
      }
      cnt[x]++;
    }

    f[i][0] = j - 1;
    for (int j = 0; j < 16; j++)
      f[i][j + 1] = f[f[i][j]][j];
  }

  while (q--)
  {
    int l, r, ans = 0, cur = 0;
    cin >> l >> r;
    for (int i = 16; i >= 0; i--)
      if (f[r][i] < l) ans = cur | 1 << i;
      else
      {
        r = f[r][i];
        cur |= 1 << i;
      }
    cout << ans << endl;
  }

}