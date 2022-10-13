#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, depth[200200], isLeaf[200200], lowestLeaf[200200];
vector<int> a[200200], path;

void visit(int x, int par)
{
  isLeaf[x] = 1;
  lowestLeaf[x] = oo;
  int maxLowestLeaf = -1;
  for (int y : a[x])
    if (y != par)
    {
      isLeaf[x] = 0;
      depth[y] = depth[x] + 1;
      visit(y, x);
      lowestLeaf[x] = min(lowestLeaf[x], lowestLeaf[y]);
      maxLowestLeaf = max(maxLowestLeaf, lowestLeaf[y]);
    }

  if (isLeaf[x]) lowestLeaf[x] = depth[x];
  else
    for (int i = 0; i < a[x].size(); i++)
    {
      int y = a[x][i];
      if (y == par) continue;
      if ((x != 1 && lowestLeaf[y] == lowestLeaf[x]) || (x == 1 && lowestLeaf[y] == maxLowestLeaf))
      {
        swap(a[x][i], a[x][int(a[x].size()) - 1]);
        return;
      }
    }
}

void go(int x, int par)
{
  path.push_back(x);
  for (int y : a[x])
    if (y != par)
    {
      go(y, x);
      path.push_back(x);
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
    cin >> n;
    for (int i = 1; i <= n; i++)
      a[i].clear();
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    visit(1, 0);
    path.clear();
    go(1, 0);

    int lastSeen = 0, ans = 0;
    vector<int> seen(n + 1, 0);
    for (int i = 0; i < path.size(); i++)
      if (!seen[path[i]])
      {
        ans = max(ans, i - lastSeen);
        lastSeen = i;
        seen[path[i]] = 1;
      }
    ans = max(ans, int(path.size()) - 1 - lastSeen);

    cout << ans << endl;
  }
}