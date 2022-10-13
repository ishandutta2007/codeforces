#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct FenwickTree
{
  int n, indexBase;
  vector<T> a;

  FenwickTree(int n, int indexBase = 1): n(n), indexBase(indexBase)
  {
    a = vector<T>(n + 1, 0);
  }

  void add(int x, T v)
  {
    for (int i = x + 1 - indexBase; i <= n; i += i & -i)
      a[i] += v;
  }

  T get(int x)
  {
    T res = 0;
    for (int i = x + 1 - indexBase; i; i -= i & -i)
      res += a[i];
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n + 1), l(n + 1);
  for (int i = 0; i < n; i++)
    cin >> p[i] >> l[i];
  p[n] = 2e9 + 1;
  int q;
  vector<vector<pair<int, int>>> queries(n);
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;
    queries[--x].push_back({--y, i});
  }

  vector<int> ans(q), cost(n + 1);
  set<int> alive = {n};
  FenwickTree<int> tree(n, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    while (!empty(alive))
    {
      int j = *begin(alive);
      if (p[j] + l[j] > p[i] + l[i])
      {
        if (j < n)
        {
          tree.add(j, -cost[j]);
          cost[j] = max(0, p[j] - p[i] - l[i]);
          tree.add(j, cost[j]);
        }
        break;
      }
      tree.add(j, -cost[j]);
      alive.erase(j);
    }

    for (auto [y, id] : queries[i])
    {
      int j = *alive.upper_bound(y);
      ans[id] = tree.get(j - 1);
    }

    alive.insert(i);
  }

  for (int x : ans)
    cout << x << '\n';
}