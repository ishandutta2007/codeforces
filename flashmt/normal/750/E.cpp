#include <bits/stdc++.h>
using namespace std;
const string GOAL = "2017";
const int oo = 27081993;

struct Node
{
  int f[5][5];

  Node()
  {
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        if (i == j) f[i][j] = 0;
        else f[i][j] = oo;
  }

  Node(char c)
  {
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        if (i == j) f[i][j] = 0;
        else f[i][j] = oo;

    for (int i = 0; i < 4; i++)
      if (GOAL[i] == c)
      {
        f[i][i + 1] = 0;
        f[i][i] = 1;
      }

    if (c == '6')
      f[3][3] = f[4][4] = 1;
  }

  Node operator+(const Node &u)
  {
    Node res;
    for (int l = 0; l < 5; l++)
      for (int r = l; r < 5; r++)
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
    if (low == high) value = Node(s[low]);
    else
    {
      l = new SegmentTree(low, mid, s);
      r = new SegmentTree(mid + 1, high, s);
      value = l->value + r->value;
    }
  }

  Node get(int x, int y)
  {
    if (low == x && high == y) return value;
    else if (y <= mid) return l->get(x, y);
    else if (mid < x) return r->get(x, y);
    else return l->get(x, mid) + r->get(mid + 1, y);
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
    int l, r;
    cin >> l >> r;
    int ans = tree.get(--l, --r).f[0][4];
    cout << (ans == oo ? -1 : ans) << '\n';
  }
}