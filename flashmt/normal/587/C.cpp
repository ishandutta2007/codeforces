#include <bits/stdc++.h>
using namespace std;
const int N = 100001, MAX_A = 10;

int n, depth[N], p[N][18];
vector <int> a[N], people[N][18];

void visit(int x, int par)
{
  for (auto y : a[x])
    if (y != par)
    {
      depth[y] = depth[x] + 1;
      p[y][0] = x;
      visit(y, x);
    }
}

vector <int> merge(vector <int> &u, vector <int> &v)
{
  vector <int> res;
  for (int cnt = 0, i = 0, j = 0; cnt < MAX_A && (i < u.size() || j < v.size()); cnt++)
    if (i == u.size()) res.push_back(v[j++]);
    else if (j == v.size()) res.push_back(u[i++]);
    else if (u[i] < v[j]) res.push_back(u[i++]);
    else res.push_back(v[j++]);
  return res;
}

vector <int> lca(int x, int y)
{
  vector <int> res;
  if (depth[x] < depth[y])
    swap(x, y);
  for (int i = 17; i >= 0; i--)
    if (depth[x] - (1 << i) >= depth[y])
    {
      res = merge(res, people[x][i]);
      x = p[x][i];
    }

  if (x == y) 
  {
    res = merge(res, people[x][0]);
    return res;
  }

  for (int i = 17; i >= 0; i--)
    if (p[x][i] != p[y][i])
    {
      res = merge(res, people[x][i]);
      x = p[x][i];
      res = merge(res, people[y][i]);
      y = p[y][i];
    }

  res = merge(res, people[x][1]);
  res = merge(res, people[y][0]);
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  int m, q, x, y, need;
  cin >> n >> m >> q;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  for (int i = 1; i <= m; i++)
  {
    cin >> x;
    people[x][0].push_back(i);
  }

  for (int i = 1; i <= n; i++)
    sort(people[i][0].begin(), people[i][0].end());

  visit(1, 0);

  for (int j = 0; j < 17; j++)
    for (int i = 1; i <= n; i++)
    {
      int k = p[i][j];
      p[i][j + 1] = p[k][j];
      people[i][j + 1] = merge(people[i][j], people[k][j]);
    }

  while (q--)
  {
    cin >> x >> y >> need;
    vector <int> ans = lca(x, y);
    need = min(need, int(ans.size()));
    cout << need << ' ';
    for (int i = 0; i < need; i++)
      cout << ans[i] << ' ';
    cout << '\n';
  }
}