#include <bits/stdc++.h>
using namespace std;

int n, par[1010], parEdge[1010];
vector <int> leaf[1010];
vector < pair<int, int> > a[1010];
vector < array<int, 3> > ans;

void visit(int x)
{
  if (a[x].size() == 1 && par[x])
  {
    leaf[x].push_back(x);
    return;
  }

  for (auto u : a[x])
  {
    int y = u.first;
    if (y == par[x])
      continue;
    par[y] = x;
    parEdge[y] = u.second;
    visit(y);
    leaf[x].push_back(leaf[y][0]);
  }
}

void addCost(int x, int y, int z)
{
  while (x != y)
  {
    parEdge[x] -= z;
    x = par[x];
  }
}

void solve(int x)
{
  if (a[x].size() == 1 && par[x])
    return;

  for (auto u : a[x])
  {
    int y = u.first, z = parEdge[y];
    if (y == par[x])
      continue;

    int curLeaf = leaf[y][0];
    int siblingLeaf = (leaf[x][0] == curLeaf ? leaf[x][1] : leaf[x][0]);
    int otherLeaf;
    if (par[x]) otherLeaf = (leaf[par[x]][0] == curLeaf || leaf[par[x]][0] == siblingLeaf ? leaf[par[x]][1] : leaf[par[x]][0]);
    else
    {
      // this is root
      for (int i : leaf[x])
        if (i != curLeaf && i != siblingLeaf)
        {
          otherLeaf = i;
          break;
        }
    }

    ans.push_back({otherLeaf, curLeaf, z / 2});
    ans.push_back({otherLeaf, siblingLeaf, - z / 2});
    ans.push_back({curLeaf, siblingLeaf, z / 2});
    addCost(curLeaf, y, z);
    solve(y);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, y, z;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y >> z;
    a[x].push_back({y, z});
    a[y].push_back({x, z});
  }

  int root = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].size() == 2)
    {
      cout << "NO\n";
      return 0;
    }
    else if (a[i].size() > 2) root = i;

  if (!root) ans.push_back({1, 2, a[1][0].second});
  else
  {
    visit(root);
    solve(root);
  }
  cout << "YES\n" << ans.size() << '\n';
  for (auto u : ans)
    cout << u[0] << ' ' << u[1] << ' ' << u[2] << '\n';
}