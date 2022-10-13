#include <bits/stdc++.h>
using namespace std;

struct DisjointSet
{
  int n;
  vector<int> par;

  DisjointSet(int n)
  {
    this->n = n;
    for (int i = 0; i < n; i++)
      par.push_back(i);
  }

  int get(int x)
  {
    return x == par[x] ? x : par[x] = get(par[x]);
  }

  int join(int x, int y)
  {
    x = get(x);
    y = get(y);
    par[x] = y;
    return x != y;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n, sumXor = 0;
  map<int, int> a[200200];
  cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    --x;
    --y;
    a[x][y] = a[y][x] = z;
    edges.push_back({z, x, y});
    sumXor ^= z;
  }

  set<int> unvisited;
  for (int i = 0; i < n; i++)
    unvisited.insert(i);

  DisjointSet ds(n);
  while (!unvisited.empty())
  {
    int x = *unvisited.begin();
    unvisited.erase(x);
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      auto it = unvisited.begin();
      while (it != unvisited.end())
      {
        if (a[cur].count(*it))
        {
          it++;
          continue;
        }
        q.push(*it);
        ds.join(cur, *it);
        it = unvisited.erase(it);
      }
    }
  }

  sort(edges.begin(), edges.end());
  DisjointSet ds2(n);
  long long ans = 0;
  for (auto [z, x, y] : edges)
    if (ds.join(x, y))
    {
      ds2.join(x, y);
      ans += z;
    }

  DisjointSet ds3(n);
  for (int x = 0; x < n; x++)
    for (int y = x + 1; y < n; y++)
      if (!a[x].count(y))
        if (!ds3.join(x, y))
        {
          cout << ans << endl;
          return 0;
        }

  for (auto [z, x, y] : edges)
    if (ds2.get(x) != ds2.get(y))
      sumXor = min(sumXor, z);

  cout << ans + sumXor << endl;
}