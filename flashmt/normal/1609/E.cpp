#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct Node
{
  int f[3][3]; // f(i, j) = cost such that no s(i, j) appears where s = "abc"

  Node()
  {
    memset(f, 0, sizeof f);
  }

  Node(int x)
  {
    memset(f, 0, sizeof f);
    f[x][x] = 1;
  }

  Node operator+(const Node &u)
  {
    Node res;
    for (int l = 0; l < 3; l++)
      for (int r = l; r < 3; r++)
      {
        res.f[l][r] = oo;
        for (int i = l; i <= r; i++)
          res.f[l][r] = min(res.f[l][r], f[l][i] + u.f[i][r]);
      }

    return res;
  }
};

struct SegmentTree
{
  int low, mid, high;
  Node value;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, string &s): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high) value = Node(s[low] - 'a');
    else
    {
      l = new SegmentTree(low, mid, s);
      r = new SegmentTree(mid + 1, high, s);
      value = l->value + r->value;
    }
  }

  void update(int x, int c)
  {
    if (low == high) value = Node(c);
    else
    {
      if (x <= mid) l->update(x, c);
      else r->update(x, c);
      value = l->value + r->value;
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  SegmentTree tree(0, n - 1, s);
  while (q--)
  {
    int x;
    char c;
    cin >> x >> c;
    tree.update(--x, c - 'a');
    cout << tree.value.f[0][2] << '\n';
  }
}