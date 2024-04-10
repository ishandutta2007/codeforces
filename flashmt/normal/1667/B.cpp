#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 1 << 30;

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
    value = -oo;
    save = 0;
    if (low == high) l = r = NULL;
    else
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void update(int x, T v)
  {
    value = max(value, v);
    if (low == high)
      return;
    if (x <= mid) l->update(x, v);
    else r->update(x, v);
  }

  T get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    if (y <= mid) return l->get(x, y);
    else if (x > mid) return r->get(x, y);
    else return merge(l->get(x, mid), r->get(mid + 1, y));
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    map<long long, int> m;
    m[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      int x;
      cin >> x;
      a[i] = a[i - 1] + x;
      m[a[i]] = 0;
    }

    int numA = 0;
    for (auto [k, _] : m)
      m[k] = numA++;
    for (int i = 0; i <= n; i++)
      a[i] = m[a[i]];

    vector<int> f(n + 1, -oo), maxF(numA, -oo);
    f[0] = maxF[a[0]] = 0;
    SegmentTree<int> treeSmall(0, numA - 1), treeBig(0, numA - 1);
    treeSmall.update(a[0], 0);
    treeBig.update(a[0], 0);
    for (int i = 1; i <= n; i++)
    {
      f[i] = maxF[a[i]];
      if (a[i])
        f[i] = max(f[i], treeSmall.get(0, a[i] - 1) + i);
      if (a[i] < numA - 1)
        f[i] = max(f[i], treeBig.get(a[i] + 1, numA - 1) - i);

      maxF[a[i]] = max(maxF[a[i]], f[i]);
      treeSmall.update(a[i], f[i] - i);
      treeBig.update(a[i], f[i] + i);
    }
    cout << f[n] << '\n';
  }
}