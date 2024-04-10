#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 60;

struct Ladder
{
  int x, y, xx, yy, gain;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> floorCost(n);
    for (int i = 0; i < n; i++)
      cin >> floorCost[i];
    vector<Ladder> ladders;
    for (int i = 0; i < k; i++)
    {
      int x, y, xx, yy, gain;
      cin >> x >> y >> xx >> yy >> gain;
      ladders.push_back({--x, --y, --xx, --yy, gain});
    }
    ladders.push_back({n - 1, m - 1, n, m, 0});

    vector<vector<int>> startLadders(n), endLadders(n);
    for (int i = 0; i <= k; i++)
    {
      startLadders[ladders[i].x].push_back(i);
      if (ladders[i].xx < n)
        endLadders[ladders[i].xx].push_back(i);
    }

    vector<long long> f(k + 1, oo);
    for (int id : startLadders[0])
      f[id] = ladders[id].y * floorCost[0];

    for (int i = 1; i < n; i++)
    {
      sort(begin(startLadders[i]), end(startLadders[i]), [&](int u, int v) { return ladders[u].y < ladders[v].y; });
      sort(begin(endLadders[i]), end(endLadders[i]), [&](int u, int v) { return ladders[u].yy < ladders[v].yy; });

      // left to right
      long long curMin = oo * 2;
      for (int j = 0, jj = 0; j < size(startLadders[i]); j++)
      {
        int curId = startLadders[i][j];
        while (jj < size(endLadders[i]))
        {
          int prevId = endLadders[i][jj];
          if (ladders[prevId].yy > ladders[curId].y)
            break;
          jj++;
          if (f[prevId] < oo)
            curMin = min(curMin, f[prevId] - ladders[prevId].gain - ladders[prevId].yy * floorCost[i]);
        }
        f[curId] = min(f[curId], curMin + ladders[curId].y * floorCost[i]);
      }

      // right to left
      reverse(begin(startLadders[i]), end(startLadders[i]));
      reverse(begin(endLadders[i]), end(endLadders[i]));
      curMin = oo * 2;
      for (int j = 0, jj = 0; j < size(startLadders[i]); j++)
      {
        int curId = startLadders[i][j];
        while (jj < size(endLadders[i]))
        {
          int prevId = endLadders[i][jj];
          if (ladders[prevId].yy < ladders[curId].y)
            break;
          jj++;
          if (f[prevId] < oo)
            curMin = min(curMin, f[prevId] - ladders[prevId].gain + ladders[prevId].yy * floorCost[i]);
        }
        f[curId] = min(f[curId], curMin - ladders[curId].y * floorCost[i]);
      }
    }

    if (f[k] == oo) cout << "NO ESCAPE\n";
    else cout << f[k] << '\n';
  }
}