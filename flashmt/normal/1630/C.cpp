#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> id(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    id[--a[i]].push_back(i);
  }

  vector<int> flag(n), canRemove(n);
  vector<pair<int, int>> segs;
  for (int i = 0; i < n; i++)
    if (size(id[i]) >= 2)
    {
      int from = id[i][0], to = id[i].back();
      for (int j : id[i])
        if (j > from && j < to)
          canRemove[j] = 1;
      flag[from + 1]++;
      flag[to]--;
      segs.push_back({from, to});
    }

  for (int i = 0; i < n; i++)
  {
    if (i)
      flag[i] += flag[i - 1];
    if (size(id[a[i]]) == 1 && flag[i] > 0)
      canRemove[i] = 1;
  }

  if (empty(segs))
  {
    cout << 0 << endl;
    return 0;
  }

  sort(begin(segs), end(segs));
  int numSeg = size(segs), y = segs[0].second;
  for (int i = 1; i < numSeg;)
  {
    int j = i, maxY = -1, bestJ = -1;
    // find a segment that intersect with current one and has max Y
    while (j < numSeg)
    {
      auto [xx, yy] = segs[j];
      if (xx > y)
        break;

      if (yy > maxY)
      {
        maxY = yy;
        bestJ = j;
      }
      j++;
    }

    if (maxY < y)
    {
      for (int k = i; k < j; k++)
      {
        auto [xx, yy] = segs[k];
        canRemove[xx] = canRemove[yy] = 1;
      }
      if (j == numSeg)
        break;
      y = segs[j].second;
      i = j + 1;
    }
    else
    {
      canRemove[y] = 1;
      for (int k = i; k < j; k++)
        if (k != bestJ)
        {
          auto [xx, yy] = segs[k];
          canRemove[xx] = canRemove[yy] = 1;
        }

      y = maxY;
      i = j;
    }
  }

  int ans = accumulate(begin(canRemove), end(canRemove), 0);;
  cout << ans << endl;
}