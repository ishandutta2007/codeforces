#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 2e5 + 5;

vector<pair<int, int>> a[N];
vector<int> s, seen;
int hasAns;

void dfs(int x, int par = -1)
{
  seen[x] = 1;
  for (auto [y, v] : a[x])
    if (y != par)
    {
      if (s[y] < 0) s[y] = s[x] ^ v;
      else if (s[y] != (s[x] ^ v)) hasAns = 0;
      if (!seen[y])
        dfs(y, x);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    s.assign(n, -1);
    for (int i = 0; i < n; i++)
      a[i].clear();

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
      int x, y, v;
      cin >> x >> y >> v;
      edges.push_back({--x, --y, v});
      if (v >= 0)
      {
        v = __builtin_popcount(v) % 2;
        a[x].push_back({y, v});
        a[y].push_back({x, v});
      }
    }
    for (int i = 0; i < m; i++)
    {
      int x, y, v;
      cin >> x >> y >> v;
      a[--x].push_back({--y, v});
      a[y].push_back({x, v});
    }

    seen.assign(n, 0);
    hasAns = 1;
    for (int i = 0; i < n; i++)
      if (!seen[i])
      {
        s[i] = 0;
        dfs(i);
      }

    if (!hasAns) cout << "NO\n";
    else
    {
      cout << "YES\n";
      for (auto [x, y, v] : edges)
      {
        if (v < 0)
          v = s[x] ^ s[y];
        cout << x + 1 << ' ' << y + 1 << ' ' << v << '\n';
      }
    }
  }
}