#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

struct SegmentTree
{
  int low, mid, high;
  long long aw, w;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, int w[], int a[]): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high)
    {
      this->w = w[low];
      aw = 1LL * a[low] * w[low] % BASE;
    }
    else
    {
      l = new SegmentTree(low, mid, w, a);
      r = new SegmentTree(mid + 1, high, w, a);
      this->w = l->w + r->w;
      aw = (l->aw + r->aw) % BASE;
    }
  }

  void update(int x, long long newW, long long newAw)
  {
    if (low == high)
    {
      w = newW;
      aw = newAw % BASE;
    }
    else
    {
      if (x <= mid) l->update(x, newW, newAw);
      else r->update(x, newW, newAw);
      w = l->w + r->w;
      aw = (l->aw + r->aw) % BASE;
    }
  }

  pair<long long, long long> get(int x, int y)
  {
    if (low == x && high == y)
      return {w, aw};
    pair<long long, long long> t(0, 0), u(0, 0);
    if (x <= mid)
      t = l->get(x, min(y, mid));
    if (mid < y)
      u = r->get(max(x, mid + 1), y);
    return {t.first + u.first, (t.second + u.second) % BASE};
  }

  int find(long long k)
  {
    if (low == high)
      return low;
    return k <= l->w ? l->find(k) : r->find(k - l->w);
  }
};


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q, a[200200], w[200200];
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] -= i;
  }
  for (int i = 1; i <= n; i++)
    cin >> w[i];

  SegmentTree *tree = new SegmentTree(1, n, w, a);
  while (q--)
  {
    int x, y;
    cin >> x >> y;
    if (x < 0)
    {
      x = -x;
      w[x] = y;
      tree->update(x, w[x], 1LL * a[x] * w[x]);
    }
    else
    {
      long long sum = tree->get(x, y).first;
      long long prefix = x > 1 ? tree->get(1, x - 1).first : 0;
      int id = tree->find(prefix + (sum + 1) / 2);
      auto u = tree->get(x, id), v = tree->get(id, y);
      long long ans = u.first % BASE * a[id] % BASE - u.second + v.second - v.first % BASE * a[id] % BASE;
      ans = (ans + BASE * 2) % BASE;
      cout << ans << '\n';
    }
  }
}