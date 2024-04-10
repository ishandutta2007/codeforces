#include <bits/stdc++.h>
using namespace std;

int region[300300], longestPath[300300], n, maxPath[300300];
vector <int> a[300300];

int get(int x)
{
  return x == region[x] ? x : region[x] = get(region[x]);
}

void merge(int x, int y)
{
  x = get(x);
  y = get(y);
  if (x == y) return;
  region[y] = x;
  int newPath = (longestPath[x] + 1) / 2 + (longestPath[y] + 1) / 2 + 1;
  longestPath[x] = max(max(longestPath[x], longestPath[y]), newPath);
}

void visit(int x, int par, int curRegion)
{
  int maxPath2 = 0;
  region[x] = curRegion;
  for (int i = 0; i < int(a[x].size()); i++)
  {
    int y = a[x][i];
    if (y == par) continue;
    visit(y, x, curRegion);
    if (maxPath[y] + 1 > maxPath[x]) maxPath2 = maxPath[x], maxPath[x] = maxPath[y] + 1;
    else maxPath2 = max(maxPath2, maxPath[y] + 1);
  }
  
  longestPath[curRegion] = max(longestPath[curRegion], maxPath[x] + maxPath2);
}

int main()
{
  ios::sync_with_stdio(0);
  int x, y, q, m, type;
  
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) region[i] = i;
  
  while (m--)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  
  for (int i = 1; i <= n; i++)
    if (region[i] == i)
      visit(i, 0, i);
  
  while (q--)
  {
    cin >> type >> x;
    if (type == 1) cout << longestPath[get(x)] << endl;
    else 
    {
      cin >> y;
      merge(x, y);
    }
  }
}