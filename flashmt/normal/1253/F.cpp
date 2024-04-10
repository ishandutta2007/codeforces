#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, k, ds[100100];
vector<pair<int, int>> a[100100], queries[100100];
long long dist[100100], ans[300300];
set<int> comp[100100];

void dijkstra()
{
  priority_queue<pair<long long, int>> q;
  for (int i = 0; i < n; i++)
    if (i < k) q.push({0, i});
    else dist[i] = oo;

  while (!q.empty())
  {
    auto [_, x] = q.top();
    q.pop();
    for (auto [y, w] : a[x])
      if (dist[x] + w < dist[y])
      {
        dist[y] = dist[x] + w;
        q.push({-dist[y], y});
      }
  }
}

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, q;
  cin >> n >> m >> k >> q;
  while (m--)
  {
    int x, y, w;
    cin >> x >> y >> w;
    --x;
    --y;
    a[x].push_back({y, w});
    a[y].push_back({x, w});
  }
  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;
    queries[--x].push_back({--y, i});
    queries[y].push_back({x, i});
  }

  dijkstra();

  vector<tuple<long long, int, int>> newEdges;
  for (int x = 0; x < n; x++)
    for (auto [y, w] : a[x])
      if (y > x)
        newEdges.push_back({dist[x] + dist[y] + w, x, y});

  for (int i = 0; i < n; i++)
  {
    ds[i] = i;
    comp[i].insert(i);
  }

  sort(newEdges.begin(), newEdges.end());
  for (auto [w, x, y] : newEdges)
  {
    int dx = get(x), dy = get(y);
    if (dx == dy)
      continue;

    if (comp[dx].size() < comp[dy].size())
      swap(dx, dy);
    ds[dy] = dx;

    for (int u : comp[dy])
      for (auto [v, id] : queries[u])
        if (comp[dx].count(v))
          ans[id] = w;

    for (int u : comp[dy])
      comp[dx].insert(u);
  }

  for (int i = 0; i < q; i++)
    cout << ans[i] << '\n';
}