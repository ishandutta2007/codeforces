#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int A = 200200;
const int oo = 27081993;

struct SegmentTree
{
  int low, mid, high;
  int save;
  vector<int> pos;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    pos = {low, oo};
    save = 0;
    if (low == high) l = r = NULL;
    else
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void updateNode()
  {
    swap(pos[0], pos[1]);
    save ^= 1;
  }

  void pushDown()
  {
    if (!save)
      return;
    l->updateNode();
    r->updateNode();
    save = 0;
  }

  void update(int x, int y)
  {
    if (low == x && high == y)
    {
      updateNode();
      return;
    }
    pushDown();
    if (x <= mid)
      l->update(x, min(y, mid));
    if (mid < y)
      r->update(max(x, mid + 1), y);
    for (int i : {0, 1})
      pos[i] = min(l->pos[i], r->pos[i]);
  }

  int find(int x, int y, int v)
  {
    if (low == x && high == y)
      return pos[v];
    pushDown();
    int res = oo;
    if (x <= mid)
      res = l->find(x, min(y, mid), v);
    if (mid < y)
      res = min(res, r->find(max(x, mid + 1), y, v));
    return res;
  }

  int findRightMostOne()
  {
    if (low == high)
      return low;
    pushDown();
    return r->pos[1] < oo ? r->findRightMostOne() : l->findRightMostOne();
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  SegmentTree tree(1, A);

  vector<int> a(n);
  for (int &x : a)
  {
    cin >> x;
    tree.update(x, tree.find(x, A, 0));
  }

  while (q--)
  {
    int i, x;
    cin >> i >> x;
    i--;
    tree.update(a[i], tree.find(a[i], A, 1));
    a[i] = x;
    tree.update(a[i], tree.find(a[i], A, 0));
    cout << tree.findRightMostOne() << '\n';
  }
}