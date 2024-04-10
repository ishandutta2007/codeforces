#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, deg[100100] = {0}, p[100100];

  cin >> n;
  int root = 0;
  for (int i = 1; i <= n; i++)
    cin >> p[i];  

  for (int i = 1; i <= n; i++)
    if (p[i] == i)
      root = i;

  if (!root)
    for (int i = 1; i <= n; i++)
      if (p[p[i]] == i)
        root = i;

  if (!root)
  {
    cout << "NO\n";
    return 0;
  }


  set < pair<int,int> > edges;
  for (int i = 1; i <= n; i++)
    if (i != root)
    {
      int x = i, y = root;
      if (deg[i] && i != p[root]) continue;
      while (1)
      {
        if (x > y) swap(x, y);
        if (edges.count(make_pair(x, y)))
          break;

        edges.insert(make_pair(x, y));
        deg[x]++;
        deg[y]++;
        x = p[x];
        y = p[y];
      }
    }

  if (edges.size() == n - 1) 
  {
    cout << "YES\n";
    for (auto edge : edges)
      cout << edge.first << ' ' << edge.second << '\n';
  }
  else cout << "NO\n";
}