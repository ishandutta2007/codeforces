#include <bits/stdc++.h>
using namespace std;

struct Cube
{
  int x, y, id;
};

int n, m;
vector<Cube> cubes;

vector<tuple<int, int, int, int>> solve()
{
  vector<tuple<int, int, int, int>> moves;
  // make x unique
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++)
      if (cubes[i].x > cubes[j].x)
        swap(cubes[i], cubes[j]);

  vector<int> moveLeft, moveRight;
  for (int i = 0; i < m; i++)
    if (cubes[i].x < i) moveRight.push_back(i);
    else if (cubes[i].x > i) moveLeft.push_back(i);

  for (int i : moveLeft)
    while (cubes[i].x > i)
    {
      moves.push_back({cubes[i].x, cubes[i].y, cubes[i].x - 1, cubes[i].y});
      cubes[i].x--;
    }

  reverse(moveRight.begin(), moveRight.end());
  for (int i : moveRight)
    while (cubes[i].x < i)
    {
      moves.push_back({cubes[i].x, cubes[i].y, cubes[i].x + 1, cubes[i].y});
      cubes[i].x++;
    }

  // move cube i to y = i
  for (int i = 0; i < m; i++)
  {
    while (cubes[i].y < cubes[i].id)
    {
      moves.push_back({cubes[i].x, cubes[i].y, cubes[i].x, cubes[i].y + 1});
      cubes[i].y++;
    }
    while (cubes[i].y > cubes[i].id)
    {
      moves.push_back({cubes[i].x, cubes[i].y, cubes[i].x, cubes[i].y - 1});
      cubes[i].y--;
    }
  }

  // move cube i to x = i
  for (int i = 0; i < m; i++)
  {
    while (cubes[i].x < cubes[i].id)
    {
      moves.push_back({cubes[i].x, cubes[i].y, cubes[i].x + 1, cubes[i].y});
      cubes[i].x++;
    }
    while (cubes[i].x > cubes[i].id)
    {
      moves.push_back({cubes[i].x, cubes[i].y, cubes[i].x - 1, cubes[i].y});
      cubes[i].x--;
    }
  }

  return moves;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  vector<tuple<int, int, int, int>> ans;
  for (int turn = 0; turn < 2; turn++)
  {
    cubes.clear();
    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      cubes.push_back({--x, --y, i});
    }
    auto moves = solve();
    if (!turn) ans = moves;
    else
    {
      reverse(moves.begin(), moves.end());
      for (auto [x, y, xx, yy] : moves)
        ans.push_back({xx, yy, x, y});
    }
  }

  cout << ans.size() << '\n';
  for (auto [x, y, xx, yy] : ans)
    cout << x + 1 << ' ' << y + 1 << ' ' << xx + 1 << ' ' << yy + 1 << '\n';
}