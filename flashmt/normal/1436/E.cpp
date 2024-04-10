#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct SegmentTree
{
  int low, mid, high;
  long long minValue;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    minValue = -1;
    if (low != high)
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void update(int x, int value)
  {
    if (low == high) minValue = value;
    else
    {
      if (x <= mid) l->update(x, value);
      else r->update(x, value);
      minValue = min(l->minValue, r->minValue);
    }
  }

  int get(int x, int y)
  {
    if (low == x && high == y)
      return minValue;
    int t = oo, u = oo;
    if (x <= mid)
      t = l->get(x, min(y, mid));
    if (mid < y)
      u = r->get(max(x, mid + 1), y);
    return min(t, u);
  }
};


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, maxVal = 0;
  cin >> n;
  vector<int> last(n + 3, -1), found(n + 3, 0);
  SegmentTree *tree = new SegmentTree(1, n + 3);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    maxVal = max(maxVal, x);
    if (x > 1 && tree->get(1, x - 1) > last[x])
      found[x] = 1;
    last[x] = i;
    tree->update(x, i);
  }

  if (maxVal == 1) cout << 1 << endl;
  else
  {
    for (int x = 2; x <= n + 2; x++)
      if (!found[x] && tree->get(1, x - 1) <= last[x])
      {
        cout << x << endl;
        return 0;
      }

    assert(0);
  }
}