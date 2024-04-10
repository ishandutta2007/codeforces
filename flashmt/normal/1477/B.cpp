#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
  int low, mid, high;
  int v, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, string &s): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = -1;
    if (low == high) v = s[low] - '0';
    else
    {
      l = new SegmentTree(low, mid, s);
      r = new SegmentTree(mid + 1, high, s);
      v = l->v + r->v;
    }
  }

  void pushDown()
  {
    if (save >= 0)
    {
      l->v = (mid - low + 1) * save;
      l->save = save;
      r->v = (high - mid) * save;
      r->save = save;
      save = -1;
    }
  }

  void update(int x, int y, int value)
  {
    if (low == x && high == y)
    {
      v = (high - low + 1) * value;
      save = value;
    }
    else
    {
      pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), value);
      if (mid < y)
        r->update(max(x, mid + 1), y, value);
      v = l->v + r->v;
    }
  }

  int get(int x, int y)
  {
    if (low == x && high == y)
      return v;
    pushDown();
    int res = 0;
    if (x <= mid)
      res += l->get(x, min(y, mid));
    if (mid < y)
      res += r->get(max(x, mid + 1), y);
    return res;
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
    string s, f;
    int n, q;
    cin >> n >> q >> s >> f;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++)
    {
      cin >> l[i] >> r[i];
      l[i]--;
      r[i]--;
    }

    SegmentTree *tree = new SegmentTree(0, n - 1, f);
    string ans = "YES";
    for (int i = q - 1; i >= 0; i--)
    {
      int v = tree->get(l[i], r[i]), len = r[i] - l[i] + 1;
      if (v * 2 == len)
      {
        ans = "NO";
        break;
      }
      tree->update(l[i], r[i], v * 2 > len);
    }

    for (int i = 0; i < n; i++)
      if (tree->get(i, i) != s[i] - '0')
      {
        ans = "NO";
        break;
      }

    cout << ans << '\n';
  }
}