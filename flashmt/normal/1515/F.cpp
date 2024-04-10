#include <bits/stdc++.h>
using namespace std;

long long a[300300];
int ds[300300], cost;
vector<pair<int, int>> edges[300300];
vector<int> ans, revAns;

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

void visit(int x, int par)
{
  for (auto [y, id] : edges[x])
    if (y != par)
    {
      visit(y, x);
      if (a[x] + a[y] >= cost)
      {
        a[x] = a[x] + a[y] - cost;
        ans.push_back(id);
      }
      else revAns.push_back(id);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m >> cost;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    ds[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    int dx = get(--x), dy = get(--y);
    if (dx != dy)
    {
      ds[dy] = dx;
      edges[x].push_back({y, i});
      edges[y].push_back({x, i});
    }
  }

  if (accumulate(a, a + n, 0LL) < (n - 1LL) * cost)
  {
    cout << "NO" << endl;
    return 0;
  }

  visit(0, -1);

  cout << "YES\n";
  for (int id : ans)
    cout << id + 1 << '\n';
  reverse(revAns.begin(), revAns.end());
  for (int id : revAns)
    cout << id + 1 << '\n';
}