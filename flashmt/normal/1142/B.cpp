#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q, p[200200], a[200200], id[200200];

  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
    id[p[i]] = i;
  }

  for (int i = 0; i < m; i++)
    cin >> a[i];

  vector<int> last(n + 1, -1);
  int r[200200][20];
  for (int i = m - 1; i >= 0; i--)
  {
    int nextValue = p[(id[a[i]] + 1) % n];
    if (last[nextValue] < 0) r[i][0] = m;
    else r[i][0] = last[nextValue];
    last[a[i]] = i;
  }

  for (int j = 0; j < 18; j++)
    for (int i = 0; i < m; i++)
      if (r[i][j] < m) r[i][j + 1] = r[r[i][j]][j];
      else r[i][j + 1] = m;

  vector<int> ans(m + 1, m);
  for (int i = m - 1; i >= 0; i--)
  {
    int x = i;
    for (int j = 17; j >= 0 && x < m; j--)
      if (n - 1 >> j & 1)
        x = r[x][j];
    ans[i] = min(ans[i + 1], x);
  }

  int x, y;
  while (q--)
  {
    cin >> x >> y;
    cout << (ans[x - 1] <= y - 1 ? 1 : 0);
  }
}