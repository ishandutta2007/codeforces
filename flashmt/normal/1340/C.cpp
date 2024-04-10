#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, green, red;
  cin >> n >> m;
  vector<int> d(m);
  for (int i = 0; i < m; i++)
    cin >> d[i];
  sort(begin(d), end(d));
  cin >> green >> red;

  vector<vector<int>> flag(m, vector<int>(green));
  flag[0][0] = 1;
  vector<pair<int, int>> q = {{0, 0}};
  int offset = 0, ans = oo;
  while (!empty(q))
  {
    vector<pair<int, int>> newQ;
    for (int i = 0; i < size(q); i++)
    {
      auto [x, r] = q[i];
      for (int y = x - 1; y <= x + 1; y += 2)
      {
        if (y < 0 || y >= m)
          continue;

        int rr = r + abs(d[y] - d[x]);
        if (rr > green)
          continue;

        if (y == m - 1) ans = min(ans, offset + rr);
        else if (rr < green)
        {
          if (!flag[y][rr])
          {
            flag[y][rr] = 1;
            q.push_back({y, rr});
          }
        }
        else if (!flag[y][0])
        {
          flag[y][0] = 1;
          newQ.push_back({y, 0});
        }
      }
    }

    swap(q, newQ);
    offset += green + red;
  }

  cout << (ans == oo ? -1 : ans) << endl;
}