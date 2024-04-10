#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 1 << 30;

struct SegmentTree
{
  int low, mid, high;
  pair<int, int> value;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, vector<int> &initial): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high)
    {
      value = {initial[low], low};
      l = r = NULL;
    }
    else
    {
      l = new SegmentTree(low, mid, initial);
      r = new SegmentTree(mid + 1, high, initial);
      value = max(l->value, r->value);
    }
  }

  void update(int x, int v)
  {
    if (low == high)
    {
      value = {v, low};
      return;
    }
    if (x <= mid) l->update(x, v);
    else r->update(x, v);
    value = max(l->value, r->value);
  }

  pair<int, int> get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    if (y <= mid) return l->get(x, y);
    else if (x > mid) return r->get(x, y);
    else return max(l->get(x, mid), r->get(mid + 1, y));
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
    int n, s, t;
    cin >> n >> s >> t;
    s--; t--;
    vector<int> p(n);
    for (int &x : p)
      cin >> x;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
      r[i] = min(i + p[i], n - 1);
      l[i] = min(p[i] - i, 0);
    }

    SegmentTree treeL(0, n - 1, l);
    SegmentTree treeR(0, n - 1, r);
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!empty(q))
    {
      int x = q.front();
      q.pop();

      // [l[x], x)
      if (x)
        while (1)
        {
          auto [ry, y] = treeR.get(-l[x], x - 1);
          if (ry < x)
            break;

          treeR.update(y, -oo);
          if (dist[y] < 0)
          {
            dist[y] = dist[x] + 1;
            q.push(y);
          }
        }

      // (x, r[x]]
      if (x < n - 1)
        while (1)
        {
          auto [ly, y] = treeL.get(x + 1, r[x]);
          if (-ly > x)
            break;

          treeL.update(y, -oo);
          if (dist[y] < 0)
          {
            dist[y] = dist[x] + 1;
            q.push(y);
          }
        }
    }

    cout << dist[t] << '\n';
  }
}