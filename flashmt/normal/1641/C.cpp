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
  T value;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = oo;
    if (low == high) l = r = NULL;
    else
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void update(int x, T v)
  {
    value = min(value, v);
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
    else return min(l->get(x, mid), r->get(mid + 1, y));
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  set<int> notWell;
  for (int i = -1; i <= n; i++)
    notWell.insert(i);

  SegmentTree<int> minRSick(0, n - 1); // min R of a sick interval
  while (q--)
  {
    int t;
    cin >> t;
    if (!t)
    {
      int l, r, x;
      cin >> l >> r >> x;
      l--; r--;
      if (!x)
      {
        while (1)
        {
          auto u = notWell.lower_bound(l);
          if (u != end(notWell) && *u <= r) notWell.erase(u);
          else break;
        }
      }
      else minRSick.update(l, r);
    }
    else
    {
      int x;
      cin >> x;
      x--;
      if (!notWell.count(x)) cout << "NO\n";
      else
      {
        auto u = notWell.upper_bound(x);
        int r = *u;
        u--;
        u--;
        int l = *u;
        int minR = minRSick.get(l + 1, x);
        cout << (minR < r ? "YES" : "N/A") << '\n';
      }
    }
  }
}