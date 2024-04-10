#include <bits/stdc++.h>
using namespace std;
const int X = 2e5;

long long solve(vector<pair<int, int>> a, int parity)
{
  sort(begin(a), end(a));

  set<pair<int, int>> leftY, rightY;
  for (auto [x, y] : a)
    rightY.insert({y, x});

  int curId = 0;
  long long res = 0;
  for (int whiteX = parity ? -X : -X + 1; whiteX <= X; whiteX += 2)
  {
    while (curId < size(a))
    {
      auto [x, y] = a[curId];
      if (x > whiteX)
        break;
      rightY.erase({y, x});
      leftY.insert({y, x});
      curId++;
    }

    if (size(leftY) >= 2 && size(rightY) >= 2)
    {
      int maxY = min(rbegin(leftY)->first, rbegin(rightY)->first);
      int minY = max(begin(leftY)->first, begin(rightY)->first);
      res += max(0, (maxY - minY) / 2);
    }
  }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> a(2);
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[abs(x + y) % 2].push_back({x + y, x - y});
  }
  cout << solve(a[0], 0) + solve(a[1], 1) << endl;
}