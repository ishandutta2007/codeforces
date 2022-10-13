#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  if (m == n * (n - 1) / 2)
  {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<int>> a(n);
  vector<int> neighborMask(n);
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
    neighborMask[x] |= 1 << y;
    neighborMask[y] |= 1 << x;
  }
  for (int i = 0; i < n; i++)
    neighborMask[i] |= 1 << i;

  int ans = n + 1;
  vector<int> picked;
  vector<int> flag(1 << n, -1), dist(1 << n);
  vector<pair<int, int>> tr(1 << n);
  for (int i = 0; i < n; i++)
  {
    queue<int> q;
    q.push(neighborMask[i]);
    flag[neighborMask[i]] = i;
    dist[neighborMask[i]] = 0;
    while (!q.empty())
    {
      int mask = q.front();
      q.pop();
      if (dist[mask] + 1 >= ans)
        break;

      for (int j = 0; j < n; j++)
        if (mask >> j & 1)
        {
          int newMask = mask | neighborMask[j];
          if (flag[newMask] != i)
          {
            flag[newMask] = i;
            dist[newMask] = dist[mask] + 1;
            tr[newMask] = {j, mask};
            q.push(newMask);
          }
        }
    }

    int mask = (1 << n) - 1;
    if (flag[mask] == i)
    {
      ans = dist[mask];
      picked = {i};
      while (mask != neighborMask[i])
      {
        auto [j, oldMask] = tr[mask];
        picked.push_back(j);
        mask = oldMask;
      }
    }
  }

  cout << ans + 1 << endl;
  reverse(begin(picked), end(picked));
  for (int x : picked)
    cout << x + 1 << ' ';
}