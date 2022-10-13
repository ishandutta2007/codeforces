#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111222;

struct SegmentTree
{
  int low, mid, high;
  vector<pair<int, int>> v;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    v = vector<pair<int, int>>(9, {oo, oo});
    if (low == high)
      return;
    l = new SegmentTree(low, mid);
    r = new SegmentTree(mid + 1, high);
  }

  void merge(vector<pair<int, int>> &p, vector<pair<int, int>> &q)
  {
    for (int i = 0; i < 9; i++)
      if (p[i].first < q[i].first) p[i].second = min(p[i].second, q[i].first);
      else p[i] = {q[i].first, min(q[i].second, p[i].first)};
  }

  void update(int x, int value)
  {
    if (low == high)
    {
      int tmp = value;
      for (int i = 0; i < 9; i++)
      {
        if (tmp % 10) v[i] = {value, oo};
        else v[i] = {oo, oo};
        tmp /= 10;
      }
    }
    else
    {
      if (x <= mid) l->update(x, value);
      else r->update(x, value);
      v = l->v;
      merge(v, r->v);
    }
  }

  vector<pair<int, int>> get(int x, int y)
  {
    if (low == x && high == y)
      return v;
    vector<pair<int, int>> p(9, {oo, oo}), q(p);
    if (x <= mid)
      p = l->get(x, min(y, mid));
    if (mid < y)
      q = r->get(max(x, mid + 1), y);
    merge(p, q);
    return p;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q, x, op, y;
  cin >> n >> q;
  SegmentTree *tree = new SegmentTree(0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    tree->update(i, x);
  }

  while (q--)
  {
    cin >> op >> x >> y;
    if (op == 1) tree->update(--x, y);
    else
    {
      auto v = tree->get(--x, --y);
      int ans = oo * 2;
      for (auto u : v)
        if (u.second < oo)
          ans = min(ans, u.first + u.second);
      cout << (ans < oo * 2 ? ans : -1) << '\n';
    }
  }
}