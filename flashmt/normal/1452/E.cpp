#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt[2020][2020], l[2020], r[2020];

int getIntersect(int from, int i)
{
  return max(0, min(from + k - 1, r[i]) - max(from, l[i]) + 1);
}

int getDist(int from, int i)
{
  return abs(from * 2 + k - 1 - l[i] - r[i]);
}

int main()
{
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++)
    cin >> l[i] >> r[i];

  for (int i = 1; i < m; i++)
    for (int j = i + 1; j <= m; j++)
      if (l[i] + r[i] > l[j] + r[j])
      {
        swap(l[i], l[j]);
        swap(r[i], r[j]);
      }

  for (int i = 1; i + k - 1 <= n; i++)
    for (int j = 1; j <= m; j++)
      cnt[i][j] = cnt[i][j - 1] + getIntersect(i, j);

  int ans = 0;
  for (int i = 1; i + k - 1 <= n; i++)
    for (int j = i, p = 0; j + k - 1 <= n; j++)
    {
      while (p + 1 <= m && getDist(i, p + 1) < getDist(j, p + 1))
        p++;
      ans = max(ans, cnt[i][p] + cnt[j][m] - cnt[j][p]);
    }

  cout << ans << endl;
}