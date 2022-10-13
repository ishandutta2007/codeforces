#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k, x, y, w;
  vector<pair<int, int>> a[200200];
  set<tuple<long long, int, int>> candidates;
  set<pair<int, int>> seen;
  map<pair<int, int>, long long> dist;

  cin >> n >> m >> k;
  while (m--)
  {
    cin >> x >> y >> w;
    if (x > y)
      swap(x, y);
    a[x].push_back({w, y});
    a[y].push_back({w, x});
    candidates.insert({w, x, y});
    dist[{x, y}] = w;
  }

  for (int i = 1; i <= n; i++)
    sort(a[i].begin(), a[i].end());

  while (1)
  {
    auto c = *candidates.begin();
    candidates.erase(c);
    long long curDist = get<0>(c);
    int x = get<1>(c), y = get<2>(c);
    if (seen.count({x, y}))
      continue;
    seen.insert({x, y});

    k--;
    if (!k)
    {
      cout << curDist << endl;
      return 0;
    }

    int added = 0;
    for (auto u : a[y])
    {
      int z = u.second;
      if (z <= x)
        continue;
      if (!dist.count({x, z}) || dist[{x, z}] > curDist + u.first)
      {
        dist[{x, z}] = curDist + u.first;
        candidates.insert({dist[{x, z}], x, z});
        if (++added >= k)
          break;
      }
    }
    for (auto u : a[x])
    {
      int z = u.second;
      if (z <= y)
        continue;
      if (!dist.count({y, z}) || dist[{y, z}] > curDist + u.first)
      {
        dist[{y, z}] = curDist + u.first;
        candidates.insert({dist[{y, z}], y, z});
        if (++added >= k)
          break;
      }
    }
  }
}