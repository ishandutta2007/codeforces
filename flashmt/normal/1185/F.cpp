#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, m, favorite[1 << 9] = {0};
  cin >> n >> m;
  while (n--)
  {
    int mask = 0, num, x;
    cin >> num;
    while (num--)
    {
      cin >> x;
      mask |= 1 << x - 1;
    }
    favorite[mask]++;
  }

  vector < pair<int, int> > pizza[1 << 9];
  for (int i = 1; i <= m; i++)
  {
    int mask = 0, x, num, price;
    cin >> price >> num;
    while (num--)
    {
      cin >> x;
      mask |= 1 << x - 1;
    }
    pizza[mask].push_back({price, i});
  }

  for (int bit = 0; bit < 9; bit++)
    for (int mask = 0; mask < 1 << 9; mask++)
      if (mask >> bit & 1)
        favorite[mask] += favorite[mask ^ 1 << bit];

  for (int mask = 0; mask < 1 << 9; mask++)
    sort(pizza[mask].begin(), pizza[mask].end());

  int maxPleased = -1, minPrice;
  pair <int, int> ans;
  for (int mask = 0; mask < 1 << 9; mask++)
  {
    if (pizza[mask].empty()) 
      continue;
    auto cheapest = pizza[mask][0];
    if (pizza[mask].size() >= 2)
    {
      int price = cheapest.first + pizza[mask][1].first;
      if (favorite[mask] > maxPleased || (favorite[mask] == maxPleased && price < minPrice))
      {
        maxPleased = favorite[mask];
        minPrice = price;
        ans = {cheapest.second, pizza[mask][1].second};
      }
    }

    for (int otherMask = mask + 1; otherMask < 1 << 9; otherMask++)
      if (!pizza[otherMask].empty())
      {
        int combinedMask = mask | otherMask, price = cheapest.first + pizza[otherMask][0].first;
        if (favorite[combinedMask] > maxPleased || (favorite[combinedMask] == maxPleased && price < minPrice))
        {
          maxPleased = favorite[combinedMask];
          minPrice = price;
          ans = {cheapest.second, pizza[otherMask][0].second};
        }
      }
  }

  cout << ans.first << ' ' << ans.second << endl;
}