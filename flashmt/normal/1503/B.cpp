#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> cells[2];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cells[(i + j) % 2].push_back({i, j});

  for (int turn = 0; turn < n * n; turn++)
  {
    int c;
    cin >> c;
    c--;
    int found = 0;
    for (int i = 0; i < 2; i++)
      if (i != c && !cells[i].empty())
      {
        auto [x, y] = cells[i].back();
        cells[i].pop_back();
        cout << i + 1 << ' ' << x + 1 << ' ' << y + 1 << endl;
        cout.flush();
        found = 1;
        break;
      }

    if (found)
      continue;

    for (int i = 0; i < 2; i++)
      if (!cells[i].empty())
      {
        auto [x, y] = cells[i].back();
        cells[i].pop_back();
        cout << 3 << ' ' << x + 1 << ' ' << y + 1 << endl;
        cout.flush();
        break;
      }
  }
}