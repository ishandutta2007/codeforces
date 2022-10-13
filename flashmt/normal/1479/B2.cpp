#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, a[100100];

struct SegmentTree
{
  int low, mid, high;
  int v, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = 0;
    v = oo;
    if (low != high)
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void pushDown()
  {
    if (save)
    {
      l->v += save;
      l->save += save;
      r->v += save;
      r->save += save;
      save = 0;
    }
  }

  void update(int x, int value)
  {
    if (low == high) v = min(v, value);
    else
    {
      pushDown();
      if (x <= mid) l->update(x, value);
      else r->update(x, value);
      v = min(l->v, r->v);
    }
  }

  int get(int x, int y)
  {
    if (low == x && high == y)
      return v;
    pushDown();
    int u = oo, v = oo;
    if (x <= mid)
      u = l->get(x, min(y, mid));
    if (mid < y)
      v = r->get(max(x, mid + 1), y);
    return min(u, v);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  SegmentTree *tree = new SegmentTree(0, n);
  tree->update(0, 1);
  for (int i = 1; i < n; i++)
  {
    int u = tree->get(a[i + 1], a[i + 1]);
    int v = tree->get(0, a[i + 1] - 1);
    if (a[i + 1] < n)
      v = min(v, tree->get(a[i + 1] + 1, n));

    if (a[i] != a[i + 1])
    {
      tree->v++;
      tree->save++;
    }

    tree->update(a[i], min(u, v + 1));
  }

  cout << tree->v << endl;
}