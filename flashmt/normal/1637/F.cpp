#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 200200;

vector<int> a[N], h;
vector<pair<int, long long>> f;

void dfs(int x, int par = -1)
{
  if (par >= 0)
    a[x].erase(find(begin(a[x]), end(a[x]), par));
  for (int y : a[x])
    dfs(y, x);

  if (empty(a[x])) f[x] = {h[x], 0};
  else
  {
    sort(begin(a[x]), end(a[x]), [&](int u, int v) { return f[u].first > f[v].first; });
    for (int i = 0; i < size(a[x]); i++)
    {
      int y = a[x][i];
      if (!i) f[x].first = max(h[x], f[y].first);
      else f[x].second += f[y].first;
      f[x].second += f[y].second;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  h.resize(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  int root = max_element(begin(h), end(h)) - begin(h);
  f.assign(n, make_pair(0, 0));
  dfs(root);

  long long ans = h[root] * 2;
  int covered = min(2, int(size(a[root])));
  for (int i = 0; i < size(a[root]); i++)
  {
    int y = a[root][i];
    if (i >= covered)
      ans += f[y].first;
    ans += f[y].second;
  }
  cout << ans << endl;
}