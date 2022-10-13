#include <bits/stdc++.h>
using namespace std;

int flag[1010][1010];

void go(int x, int y, int xx, int yy)
{
  if (y > yy)
    swap(y, yy);
  for (int i = x; i <= xx; i++)
    for (int j = y; j <= yy; j++)
      flag[i][j] = 1;
}

int main()
{
  pair<int, int> a[3];
  for (int i = 0; i < 3; i++)
    cin >> a[i].first >> a[i].second;
  sort(a, a + 3);
  go(a[0].first, a[0].second, a[1].first, a[0].second);
  go(a[1].first, a[0].second, a[1].first, a[1].second);

  int minY = min(a[0].second, a[1].second), maxY = max(a[0].second, a[1].second);
  go(a[1].first, a[2].second, a[2].first, a[2].second);
  if (a[2].second > maxY) go(a[1].first, maxY, a[1].first, a[2].second);
  else if (a[2].second < minY) go(a[1].first, a[2].second, a[1].first, minY);

  vector<pair<int, int>> ans;
  for (int i = 0; i <= 1000; i++)
    for (int j = 0; j <= 1000; j++)
      if (flag[i][j])
        ans.push_back({i, j});

  cout << ans.size() << '\n';
  for (auto u : ans)
    cout << u.first << ' ' << u.second << '\n';
}