#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
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
  int n, q;
  cin >> n >> q;
  vector<long long> save(n);
  FenwickTree<long long> tree(n, 0);
  set<tuple<int, int, int>> intervals = {{0, n, 0}};
  while (q--)
  {
    string op;
    cin >> op;
    if (op == "Color")
    {
      int l, r, c;
      cin >> l >> r >> c;
      auto newInterval = make_tuple(--l, r, --c);
      while (l < r)
      {
        auto u = intervals.upper_bound(make_tuple(l, n + 1, 0));
        auto [ll, rr, cc] = *--u;
        intervals.erase(u);
        if (ll < l)
          intervals.insert({ll, l, cc});
        if (r < rr)
          intervals.insert({r, rr, cc});
        tree.add(l, save[cc] - save[c]);
        tree.add(min(r, rr), save[c] - save[cc]);
        l = rr;
      }
      intervals.insert(newInterval);
    }
    else if (op == "Add")
    {
      int c, x;
      cin >> c >> x;
      save[--c] += x;
    }
    else
    {
      int i;
      cin >> i;
      auto u = intervals.upper_bound(make_tuple(--i, n + 1, 0));
      auto [l, r, c] = *--u;
      cout << tree.get(i) + save[c] << '\n';
    }
  }
}