#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int A = 1000100;

int n, ds[N];
vector<pair<int, int>> edges[A], queries[A];

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q, s, d;
  cin >> n >> q >> s >> d;
  s--;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    ds[i] = i;
  }
  for (int i = 0; i < q; i++)
  {
    int x, k;
    cin >> x >> k;
    queries[k].push_back({--x, i});
  }

  vector<int> r(n); // r[i] = min(j | a[j] - a[i] >= d)
  for (int i = 0, j = 0; i < n; i++)
  {
    while (j < n && a[j] - a[i] < d)
      j++;
    r[i] = min(j, n - 1);
  }

  for (int i = 0; i < n; i++)
  {
    int from = i ? max(r[i - 1] - 1, i + 1) : 1;
    int to = i + 1 < n ? r[i + 1] : n - 1;
    for (int j = from; j <= to; j++)
      edges[abs(a[j] - a[i] - d)].push_back({i, j});
  }

  vector<int> ans(q);
  for (int i = 0; i < A; i++)
  {
    for (auto [x, y] : edges[i])
    {
      int dx = get(x), dy = get(y);
      if (dx != dy)
        ds[dx] = dy;
    }
    for (auto [x, id] : queries[i])
      ans[id] = get(x) == get(s);
  }

  for (int x : ans)
    cout << (x ? "Yes\n" : "No\n");
}