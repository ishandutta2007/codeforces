#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n), p(n);
  int pivot = -1;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i] >> p[i];
    p[i]--;
    if (p[i] == i)
      continue;
    if (pivot < 0) pivot = i;
    else if (make_pair(y[i], x[i]) < make_pair(y[pivot], x[pivot])) pivot = i;
  }

  if (pivot < 0)
  {
    cout << 0 << endl;
    return 0;
  }

  vector<int> flag(n, -1);
  for (int i = 0; i < n; i++)
    if (p[i] != i && flag[i] < 0)
      for (int x = i; flag[x] < 0; x = p[x])
        flag[x] = i;

  vector<int> order;
  for (int i = 0; i < n; i++)
    if (i != pivot && flag[i] >= 0)
    {
      x[i] -= x[pivot];
      y[i] -= y[pivot];
      order.push_back(i);
    }

  sort(begin(order), end(order), [&](int u, int v) { return 1LL * x[u] * y[v] - 1LL * x[v] * y[u] > 0; });

  vector<pair<int, int>> ans;
  for (int i = 0; i + 1 < size(order); i++)
  {
    int u = order[i], v = order[i + 1];
    if (flag[u] == flag[v])
      continue;

    ans.push_back({u, v});
    swap(p[u], p[v]);

    int curFlagV = flag[v];
    for (int j = 0; j < n; j++)
      if (flag[j] == curFlagV)
        flag[j] = flag[u];
  }

  while (p[pivot] != pivot)
  {
    int u = p[pivot];
    ans.push_back({pivot, u});
    swap(p[pivot], p[u]);
  }

  cout << size(ans) << endl;
  for (auto [u, v] : ans)
    cout << u + 1 << ' ' << v + 1 << endl;
}