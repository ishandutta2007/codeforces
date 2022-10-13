#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 27081993;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;
    vector<vector<vector<int>>> cost(k + 1, vector<vector<int>>(k + 1, vector<int>(4)));
    for (int i = 0; i < n; i++)
    {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      if (r1 == r2)
      {
        cost[r1 - 1][min(c1, c2)][2]++;
        cost[r1][min(c1, c2)][0]++;
      }
      else
      {
        cost[min(r1, r2)][c1 - 1][1]++;
        cost[min(r1, r2)][c1][3]++;
      }
    }

    vector<vector<int>> dist(k + 1, vector<int>(k + 1, oo));
    vector<vector<int>> done(k + 1, vector<int>(k + 1));
    set<tuple<int, int, int>> s;
    dist[k / 2][k / 2] = 0;
    s.insert({0, k / 2, k / 2});
    while (!empty(s))
    {
      auto [_, x, y] = *begin(s);
      s.erase(begin(s));
      if (done[x][y])
        continue;
      done[x][y] = 1;

      if (!x || x == k || !y || y == k)
      {
        cout << n - dist[x][y] << endl;
        break;
      }

      for (int i = 0; i < 4; i++)
      {
        int xx = x + DX[i], yy = y + DY[i];
        int newDist = dist[x][y] + cost[x][y][i] + cost[k - x][k - y][(i + 2) % 4];
        if (dist[xx][yy] > newDist)
        {
          dist[xx][yy] = newDist;
          s.insert({newDist, xx, yy});
        }
      }
    }
  }
}