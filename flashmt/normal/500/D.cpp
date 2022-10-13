#include <bits/stdc++.h>
using namespace std;

vector<int> a[100100];
int sz[100100], p[100100];

void dfs(int x)
{
  sz[x] = 1;
  for (int y : a[x])
    if (y != p[x])
    {
      p[y] = x;
      dfs(y);
      sz[x] += sz[y];
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < n - 1; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    edges.push_back({--x, --y, w});
    a[x].push_back(y);
    a[y].push_back(x);
  }

  p[0] = -1;
  dfs(0);

  long long sum = 0;
  for (auto [x, y, w] : edges)
  {
    if (p[x] == y)
      swap(x, y);
    sum += 1LL * sz[y] * (n - sz[y]) * w;
  }

  int q;
  cin >> q;
  while (q--)
  {
    int i, w;
    cin >> i >> w;
    auto [x, y, oldW] = edges[--i];
    if (p[x] == y)
      swap(x, y);
    sum += 1LL * sz[y] * (n - sz[y]) * (w - oldW);
    edges[i] = {x, y, w};

    cout << fixed << setprecision(9) << sum * 6. / n / (n - 1) << '\n';
  }
}