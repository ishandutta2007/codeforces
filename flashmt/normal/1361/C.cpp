#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> &a, vector<int> &b, int mask)
{
  vector<int> used(n);
  vector<vector<pair<int, int>>> adj(mask + 1);
  for (int i = 0; i < n; i++)
  {
    int x = a[i] & mask, y = b[i] & mask;
    adj[x].push_back({y, i});
    adj[y].push_back({x, i});
  }
  for (int i = 0; i <= mask; i++)
    if (size(adj[i]) % 2)
      return {};

  int start = 0;
  while (start <= mask && empty(adj[start]))
    start++;
  assert(start <= mask);

  auto getEdge = [&](int x)
  {
    while (!empty(adj[x]))
    {
      auto [y, id] = adj[x].back();
      adj[x].pop_back();
      if (used[id])
        continue;
      used[id] = 1;
      return pair<int, int>(y, id);
    }
    return pair<int, int>(-1, -1);
  };

  vector<pair<int, int>> st = {{start, -1}}, res;
  while (!empty(st))
  {
    auto [x, xId] = st.back();
    auto [y, yId] = getEdge(x);
    if (y >= 0) st.push_back({y, yId});
    else
    {
      res.push_back({x, xId});
      st.pop_back();
    }
  }

  res.pop_back();
  if (size(res) != n)
    return {};

  vector<int> order;
  for (auto [x, id] : res)
    if ((a[id] & mask) == x)
    {
      order.push_back(id * 2 + 1);
      order.push_back(id * 2 + 2);
    }
    else
    {
      order.push_back(id * 2 + 2);
      order.push_back(id * 2 + 1);
    }
  return order;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  if (n == 1)
  {
    int ans = 20;
    for (int i = 0; i < 20; i++)
      if ((a[0] ^ b[0]) >> i & 1)
      {
        ans = i;
        break;
      }
    cout << ans << endl << 1 << ' ' << 2 << endl;
    return 0;
  }

  for (int bit = 20; bit; bit--)
  {
    auto order = solve(n, a, b, (1 << bit) - 1);
    if (!empty(order))
    {
      cout << bit << endl;
      for (auto x : order)
        cout << x << ' ';
      return 0;
    }
  }

  cout << 0 << endl;
  for (int i = 1; i <= n * 2; i++)
    cout << i << ' ';
}