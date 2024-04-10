#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

struct SegmentTree
{
  int low, mid, high, value, maxValue;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = maxValue = 0;
    if (low == high)
      return;
    l = new SegmentTree(low, mid);
    r = new SegmentTree(mid + 1, high);
  }

  void update(int x, int y, int v)
  {
    if (low == x && high == y)
    {
      value += v;
      maxValue += v;
    }
    else
    {
      if (x <= mid)
        l -> update(x, min(y, mid), v);
      if (mid < y)
        r -> update(max(x, mid + 1), y, v);
      maxValue = max(l -> maxValue, r -> maxValue) + value;
    }
  }

  int get()
  {
    if (maxValue <= 0)
      return -1;

    if (low == high)
      return low;

    l -> value += value;
    l -> maxValue += value;
    r -> value += value;
    r -> maxValue += value;
    value = 0;

    return r -> maxValue > 0 ? r -> get() : l -> get();
  }
};

int main()
{
  int a[300300], b[300300], m, n;
  scanf("%d%d", &n, &m);

  SegmentTree *tree = new SegmentTree(1, N);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", a + i);
    tree -> update(1, a[i], 1);
  }
  for (int i = 1; i <= m; i++)
  {
    scanf("%d", b + i);
    tree -> update(1, b[i], -1);
  }

  int q, t, id, v;
  scanf("%d", &q);
  while (q--)
  {
    scanf("%d%d%d", &t, &id, &v);
    if (t == 1)
    {
      tree -> update(1, a[id], -1);
      a[id] = v;
      tree -> update(1, a[id], 1);
    }
    else
    {
      tree -> update(1, b[id], 1);
      b[id] = v;
      tree -> update(1, b[id], -1);
    }

    printf("%d\n", tree -> get());
  }
}