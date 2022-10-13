#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, k, ds[100100], p[100100];
vector<int> portals;
vector<pair<int, int>> a[100100];
long long dist[100100];

void dijkstra()
{
  priority_queue<pair<long long, int>> q;
  vector<int> done(n, 0);
  for (int i = 0; i < n; i++)
    dist[i] = oo;
  for (int x : portals)
  {
    dist[x] = 0;
    p[x] = x;
    q.push({0, x});
  }

  while (!q.empty())
  {
    auto [_, x] = q.top();
    q.pop();
    if (done[x])
      continue;
    done[x] = 1;
    for (auto [y, w] : a[x])
      if (dist[x] + w < dist[y])
      {
        dist[y] = dist[x] + w;
        p[y] = p[x];
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

  int m, k;
  cin >> n >> m;
  while (m--)
  {
    int x, y, w;
    cin >> x >> y >> w;
    --x;
    --y;
    a[x].push_back({y, w});
    a[y].push_back({x, w});
  }
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int x;
    cin >> x;
    portals.push_back(--x);
  }

  dijkstra();

  vector<tuple<long long, int, int>> newEdges;
  for (int x = 0; x < n; x++)
    for (auto [y, w] : a[x])
      if (p[y] > p[x])
        newEdges.push_back({dist[x] + dist[y] + w, p[x], p[y]});

  for (int x : portals)
    ds[x] = x;

  sort(newEdges.begin(), newEdges.end());
  long long ans = dist[0];
  for (auto [w, x, y] : newEdges)
  {
    int dx = get(x), dy = get(y);
    if (dx == dy)
      continue;
    ds[dy] = dx;
    ans += w;
  }

  cout << ans << endl;
}