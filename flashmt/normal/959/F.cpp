#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; i++)
  {
    int l, x;
    cin >> l >> x;
    queries[--l].push_back({x, i});
  }

  vector<int> p2(n + 1);
  for (int i = 0; i <= n; i++)
    p2[i] = i ? p2[i - 1] * 2 % BASE : 1;

  vector<int> basis, ans(q);
  for (int i = 0; i < n; i++)
  {
    int cur = a[i];
    for (int x : basis)
      cur = min(cur, cur ^ x);
    if (cur)
    {
      int id = 0;
      while (id < size(basis) && basis[id] > cur)
        id++;
      basis.insert(begin(basis) + id, cur);
    }

    for (auto [x, id] : queries[i])
    {
      for (int y : basis)
        x = min(x, x ^ y);
      if (!x)
        ans[id] = p2[i + 1 - size(basis)];
    }
  }

  for (int x : ans)
    cout << x << '\n';
}