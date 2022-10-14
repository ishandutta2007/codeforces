#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

pair<int, int> move(int x, int y, char c)
{
  if (c == 'U') return {x, y + 1};
  if (c == 'D') return {x, y - 1};
  if (c == 'R') return {x + 1, y};
  return {x - 1, y};
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    string s;
    cin >> s;
    set<pair<int, int>> points;
    int x = 0, y = 0;
    for (char c : s)
    {
      auto [xx, yy] = move(x, y, c);
      x = xx;
      y = yy;
      if (x || y)
        points.insert({x, y});
    }

    if (!x && !y) cout << oo << ' ' << oo << endl;
    else
    {
      int found = 0;
      for (auto [blockedX, blockedY] : points)
      {
        x = y = 0;
        for (char c : s)
        {
          auto [xx, yy] = move(x, y, c);
          if (xx != blockedX || yy != blockedY)
          {
            x = xx;
            y = yy;
          }
        }

        if (!x && !y)
        {
          cout << blockedX << ' ' << blockedY << endl;
          found = 1;
          break;
        }
      }

      if (!found)
        cout << 0 << ' ' << 0 << endl;
    }
  }
}