#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct SegmentTree
{
  int low, mid, high, minVal;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, int a[]): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high)
    {
      minVal = a[low];
      return;
    }
    l = new SegmentTree(low, mid, a);
    r = new SegmentTree(mid + 1, high, a);
    minVal = min(l -> minVal, r -> minVal);
  }

  void remove(int x)
  {
    if (low == high) minVal = oo;
    else
    {
      if (x <= mid) l -> remove(x);
      else r -> remove(x);
      minVal = min(l -> minVal, r -> minVal);
    }
  }

  int query(int x, int y)
  {
    if (low == x && high == y)
      return minVal;
    int minL = oo, minR = oo;
    if (x <= mid)
      minL = l -> query(x, min(y, mid));
    if (mid < y)
      minR = r -> query(max(x, mid + 1), y);
    return min(minL, minR);
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int test, n, a[300300], b[300300];
  queue <int> id[300300];
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      id[a[i]].push(i);
    }
    for (int i = 0; i < n; i++)
      cin >> b[i];

    SegmentTree *tree = new SegmentTree(0, n - 1, a);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
      if (id[b[i]].empty())
      {
        ans = 0;
        break;
      }
      int curId = id[b[i]].front();
      id[b[i]].pop();
      if (tree -> query(0, curId) < b[i])
      {
        ans = 0;
        break;
      }
      tree -> remove(curId);
    }

    for (int i = 0; i < n; i++)
      while (!id[a[i]].empty())
        id[a[i]].pop();

    cout << (ans ? "YES\n" : "NO\n");
  }
}