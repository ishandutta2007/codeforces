#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct SegmentTreeData
{
  // depth(x) - 2 * depth(y) + depth(z)
  int x, y, xy, yz, xyz;
};

struct SegmentTree
{
  int low, mid, high, save;
  SegmentTree *l, *r;
  SegmentTreeData data;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    data = {0, 0, 0, 0, 0};
    save = 0;
    if (low == high)
      return;
    l = new SegmentTree(low, mid);
    r = new SegmentTree(mid + 1, high);
  }

  void merge(SegmentTreeData left, SegmentTreeData right)
  {
    data.x = max(left.x, right.x);
    data.y = max(left.y, right.y);

    data.xy = max(left.xy, right.xy);
    data.xy = max(data.xy, left.x + right.y);

    data.yz = max(left.yz, right.yz);
    data.yz = max(data.yz, left.y + right.x);

    data.xyz = max(left.xyz, right.xyz);
    data.xyz = max(data.xyz, left.x + right.yz);
    data.xyz = max(data.xyz, left.xy + right.x);
  }

  void updateNode(int v)
  {
    save += v;
    data.x += v;
    data.y -= v * 2;
    data.xy -= v;
    data.yz -= v;
  }

  void add(int x, int y, int v)
  {
    if (low == x && high == y) updateNode(v);
    else
    {
      l->updateNode(save);
      r->updateNode(save);
      save = 0;
      if (x <= mid)
        l->add(x, min(y, mid), v);
      if (mid < y)
        r->add(max(x, mid + 1), y, v);
      merge(l->data, r->data);
    }
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q, x, y;
  string s;
  cin >> n >> q >> s;
  SegmentTree *tree = new SegmentTree(0, 2 * n - 2);
  for (int i = 0; i < 2 * n - 2; i++)
    tree->add(i + 1, 2 * n - 2, (s[i] == '(' ? 1 : -1));

  cout << tree->data.xyz << '\n';

  while (q--)
  {
    cin >> x >> y;
    swap(s[--x], s[--y]);
    tree->add(x + 1, 2 * n - 2, (s[x] == '(' ? 2 : -2));
    tree->add(y + 1, 2 * n - 2, (s[y] == '(' ? 2 : -2));
    cout << tree->data.xyz << '\n';
  }
}