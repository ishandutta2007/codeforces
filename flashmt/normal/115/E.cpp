#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

template<typename T>
struct SegmentTree
{
  int low, mid, high;
  T value, save;
  SegmentTree *l, *r;

  T merge(T u, T v)
  {
    return max(u, v);
  }

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = save = 0;
    if (low == high) l = r = NULL;
    else
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void updateNode(T v)
  {
    value += v;
    save += v;
  }

  void pushDown()
  {
    if (!save)
      return;
    l->updateNode(save);
    r->updateNode(save);
    save = 0;
  }

  void update(int x, int y, T v)
  {
    if (low == x && high == y)
    {
      updateNode(v);
      return;
    }
    pushDown();
    if (x <= mid)
      l->update(x, min(y, mid), v);
    if (mid < y)
      r->update(max(x, mid + 1), y, v);
    value = merge(l->value, r->value);
  }

  T get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    pushDown();
    if (y <= mid) return l->get(x, y);
    else if (x > mid) return r->get(x, y);
    else return merge(l->get(x, mid), r->get(mid + 1, y));
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> cost(n + 1);
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    cost[i] = cost[i - 1] + x;
  }

  vector<vector<pair<int, int>>> at(n + 1);
  while (m--)
  {
    int l, r, gain;
    cin >> l >> r >> gain;
    at[r].push_back({--l, gain});
  }

  long long ans = 0;
  SegmentTree<long long> tree(0, n);
  vector<long long> f(n + 1);
  for (int i = 1; i <= n; i++)
  {
    for (auto [l, gain] : at[i])
      tree.update(0, l, gain);
    f[i] = max(f[i - 1], tree.get(0, i - 1) - cost[i]);
    ans = max(ans, f[i]);
    tree.update(i, i, f[i] + cost[i]);
  }
  cout << ans << endl;
}