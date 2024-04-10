#include <bits/stdc++.h>
using namespace std;

int ask(int x, int y, int xx, int yy)
{
  cout << "? " << x << ' ' << y << ' ' << xx << ' ' << yy << '\n';
  cout.flush();
  string resp;
  cin >> resp;
  return resp[0] == 'Y';
}

int main()
{
  int n;
  cin >> n;

  string ans;
  vector<pair<int, int>> cells;
  int x = 1, y = 1;
  while (x + y < n + 1) // move from (1, 1) to diagonal, prioritize going down
  {
    cells.push_back({x, y});
    int dx = 0, dy = 0;
    if (x == n) dy = 1;
    else if (y == n) dx = 1;
    else if (ask(x + 1, y, n, n)) dx = 1;
    else dy = 1;

    x += dx;
    y += dy;
    if (dx) ans += 'D';
    else ans += 'R';
  }

  string ans2;
  int mx = x, my = y;
  x = n;
  y = n;
  while (x > mx || y > my) // move from (n, n) to (mx, my), prioritize going left
  {
    int dx = 0, dy = 0;
    if (x == mx) dy = 1;
    else if (y == my) dx = 1;
    else
    {
      auto [xx, yy] = cells[x + y - n - 2];
      if (ask(xx, yy, x, y - 1)) dy = 1;
      else dx = 1;
    }

    x -= dx;
    y -= dy;
    if (dx) ans2 += 'D';
    else ans2 += 'R';
  }
  reverse(ans2.begin(), ans2.end());

  cout << "! " << ans << ans2 << '\n';
  cout.flush();
}