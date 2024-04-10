#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
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
    return min(u, v);
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
  const int A = 1e5 + 5;
  int test;
  cin >> test;
  SegmentTree<int> tree(1, A);
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      tree.update(1, a[i], 1);
    }

    vector<vector<int>> b(m);
    vector<long long> sumB(m);
    vector<int> sz(m), average(m);
    for (int i = 0; i < m; i++)
    {
      cin >> sz[i];
      b[i].resize(sz[i]);
      for (int j = 0; j < sz[i]; j++)
      {
        cin >> b[i][j];
        sumB[i] += b[i][j];
      }
      average[i] = (sumB[i] + sz[i] - 1) / sz[i];
      tree.update(1, average[i], -1);
    }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < sz[i]; j++)
      {
        int newAverage = (sumB[i] - b[i][j] + sz[i] - 2) / (sz[i] - 1);
        tree.update(1, average[i], 1);
        tree.update(1, newAverage, -1);
        cout << (tree.value >= 0);
        tree.update(1, newAverage, 1);
        tree.update(1, average[i], -1);
      }

    cout << '\n';

    for (int x : a)
      tree.update(1, x, -1);
    for (int x : average)
      tree.update(1, x, 1);
  }
}