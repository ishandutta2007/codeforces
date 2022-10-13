#include <bits/stdc++.h>
using namespace std;

int n, ds[100100], w[100100];

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k, ds[100100], w[100100] = {0};
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++)
  {
    int x;
    cin >> x;
    w[x] = 1;
  }

  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    edges.push_back({z, x, y});
  }

  for (int i = 1; i <= n; i++)
    ds[i] = i;
  function<int(int)> getDs = [&](int x)
  {
    return x == ds[x] ? x : ds[x] = getDs(ds[x]);
  };

  sort(edges.begin(), edges.end());
  for (auto edge : edges)
  {
    int z = get<0>(edge), x = get<1>(edge), y = get<2>(edge);
    int dx = getDs(x), dy = getDs(y);
    if (dx != dy)
    {
      ds[dx] = dy;
      w[dy] += w[dx];
      if (w[dy] == k)
      {
        for (int i = 0; i < k; i++)
          cout << z << " \n"[i == k - 1];
        return 0;
      }
    }
  }
}