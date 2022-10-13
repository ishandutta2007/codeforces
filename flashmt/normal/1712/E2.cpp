#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int A = 200200;

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
  vector<vector<int>> d(A * 2);
  for (int i = 1; i < A * 2; i++)
  {
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0)
      {
        d[i].push_back(j);
        if (j * j < i)
          d[i].push_back(i / j);
      }

    sort(rbegin(d[i]), rend(d[i]));
    if (i > 1)
      d[i].push_back(1);
  }

  vector<vector<int>> g(A);
  FenwickTree<long long> tree(A);
  for (int k = 2; k < A; k++)
  {
    long long ways = size(d[k]) * (size(d[k]) - 1LL) / 2;
    g[k].assign(size(d[k * 2]), 0);
    int low = size(d[k * 2]) - 1, high = 1;
    for (int i = low, j = high; i >= high; i--)
    {
      while (j < i && d[k * 2][i] + d[k * 2][j] > k)
        j++;
      g[k][i] = max(min(i, j) - 1, 0);
      ways += g[k][i];
    }
    tree.add(k, ways);
  }

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  vector<vector<pair<int, int>>> queries(A);
  for (int i = 0; i < test; i++)
  {
    int l, r;
    cin >> l >> r;
    queries[l].push_back({r, i});
  }

  vector<long long> ans(test);
  for (int l = 1; l < A; l++)
  {
    for (auto [r, id] : queries[l])
    {
      ans[id] = (r - l + 1LL) * (r - l) * (r - l - 1) / 6;
      ans[id] -= tree.get(r) - tree.get(l - 1);
    }

    // shift the left bound
    for (int i = l; i < A * 2; i += l)
    {
      if (i > l && i < A)
      {
        d[i].pop_back();
        tree.add(i, -int(size(d[i])));
      }

      if (i % 2 == 0 && i > 2)
      {
        tree.add(i / 2, -g[i / 2].back());
        g[i / 2].pop_back();
      }
    }
  }

  for (auto x : ans)
    cout << x << '\n';
}