#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct SegmentTree
{
  int low, mid, high;
  int value, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = save = 0;
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
      l->value += save;
      l->save += save;
      r->value += save;
      r->save += save;
      save = 0;
    }
  }

  void update(int x, int y, int v)
  {
    if (low == x && high == y)
    {
      value += v;
      save += v;
    }
    else
    {
      pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), v);
      if (mid < y)
        r->update(max(x, mid + 1), y, v);
      value = max(l->value, r->value);
    }
  }

  int get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    pushDown();
    int t = x <= mid ? l->get(x, min(y, mid)) : -oo;
    int u = mid < y ? r->get(max(x, mid + 1), y) : -oo;
    return max(t, u);
  }
};


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> id(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    id[--x] = i;
  }

  int ans = n - 1;
  cout << ans + 1 << ' ';
  SegmentTree *tree = new SegmentTree(0, n - 1);
  tree->update(0, id[ans], 1);
  for (int i = 0; i < n - 1; i++)
  {
    int x;
    cin >> x;
    tree->update(0, --x, -1);
    while (tree->value <= 0)
      tree->update(0, id[--ans], 1);
    cout << ans + 1 << " \n"[i == n - 2];
  }
}