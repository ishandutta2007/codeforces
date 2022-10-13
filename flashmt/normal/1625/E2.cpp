#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

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
  string s;
  cin >> n >> q >> s;
  s = ")" + s;
  n++;
  vector<int> l(n, -1), r(n, -1), st;
  for (int i = 0; i < n; i++)
    if (s[i] == '(') st.push_back(i);
    else if (!empty(st))
    {
      int j = st.back();
      st.pop_back();
      l[i] = j;
      r[j] = i;
    }

  vector<int> par(n), preDfs(n), postDfs(n);
  int dfsTime = 0;
  vector<OrderedSet> child(n);

  auto construct = [&](auto self, int i) -> void
  {
    preDfs[i] = ++dfsTime;
    for (int j = i + 1; j < r[i]; j = r[j] + 1)
    {
      child[i].insert(j);
      par[j] = i;
      self(self, j);
    }
    postDfs[i] = dfsTime;
  };

  for (int i = 1; i < n; i++)
    if (r[i] >= 0)
    {
      int j = i;
      preDfs[i - 1] = ++dfsTime;
      while (j < n && r[j] >= 0)
      {
        child[i - 1].insert(j);
        par[j] = i - 1;
        construct(construct, j);
        j = r[j] + 1;
      }
      postDfs[i - 1] = dfsTime;
      i = j;
    }

  FenwickTree<long long> tree(dfsTime);
  for (int i = 0; i < n; i++)
    if (!empty(child[i]))
    {
      int sz = size(child[i]);
      tree.add(preDfs[i], sz * (sz + 1LL) / 2);
    }

  while (q--)
  {
    int t, x, y;
    cin >> t >> x >> y;
    int p = par[x];
    if (t == 1)
    {
      int sz = size(child[p]);
      tree.add(preDfs[p], -sz * (sz + 1LL) / 2);
      child[p].erase(x);
      tree.add(preDfs[p], sz * (sz - 1LL) / 2);
    }
    else
    {
      y = l[y];
      int xId = child[p].order_of_key(x);
      int yId = child[p].order_of_key(y);
      int numChild = yId - xId + 1;
      long long ans = tree.get(postDfs[y]) - tree.get(preDfs[x] - 1);
      ans += numChild * (numChild + 1LL) / 2;
      cout << ans << '\n';
    }
  }
}