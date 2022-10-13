#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<int> col(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x] = y;
      col[y] = x;
    }

    int ans = 0;
    vector<int> flag(n + 1, 0);
    for (int i = 1; i <= n; i++)
      if (a[i] && a[i] != i && !flag[i] && !col[i])
      {
        int x = i, cnt = 0;
        while (a[x] && !flag[x])
        {
          cnt++;
          flag[x] = 1;
          x = a[x];
        }
        ans += cnt + (a[x] > 0);
      }

    for (int i = 1; i <= n; i++)
      if (a[i] && a[i] != i && !flag[i])
      {
        int x = i, cnt = 0;
        while (a[x] && !flag[x])
        {
          cnt++;
          flag[x] = 1;
          x = a[x];
        }
        ans += cnt + (a[x] > 0);
      }

    cout << ans << '\n';
  }
}