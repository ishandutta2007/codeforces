#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int LOG = 30;
const int oo = 1 << 30;

struct SegmentTree
{
  int low, mid, high;
  vector<int> v;
  SegmentTree *l, *r;

  vector<int> merge(vector<int> t, vector<int> u)
  {
    vector<int> res(min(int(size(u) + size(t)), LOG + 1));
    for (int i = 0, j = 0, k = 0; i < size(res); i++)
      if (j == size(t)) res[i] = u[k++];
      else if (k == size(u)) res[i] = t[j++];
      else if (t[j] < u[k]) res[i] = t[j++];
      else res[i] = u[k++];
    return res;
  }

  SegmentTree(int low, int high, vector<int> &a): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high)
    {
      l = r = NULL;
      v = {a[low]};
    }
    else
    {
      l = new SegmentTree(low, mid, a);
      r = new SegmentTree(mid + 1, high, a);
      v = merge(l->v, r->v);
    }
  }

  vector<int> get(int x, int y)
  {
    if (low == x && high == y)
      return v;
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
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    SegmentTree tree(0, n - 1, a);
    int q;
    cin >> q;
    while (q--)
    {
      int l, r;
      cin >> l >> r;
      vector<int> v = tree.get(--l, --r);
      int ans = oo;
      for (int i = 0; i < size(v); i++)
        for (int j = i + 1; j < size(v); j++)
          ans = min(ans, v[i] | v[j]);
      cout << ans << '\n';
    }
  }
}