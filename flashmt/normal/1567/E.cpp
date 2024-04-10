#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int isFull, prefix, suffix;
  long long pairs;

  Node(int isFull, int prefix, int suffix, long long pairs): isFull(isFull), prefix(prefix), suffix(suffix), pairs(pairs) {}

  Node() {}

  Node(int x)
  {
    pairs = isFull = prefix = suffix = x;
  }
};

struct SegmentTree
{
  int low, mid, high;
  Node node;
  SegmentTree *l, *r;

  long long numPairs(int x)
  {
    return x * (x + 1LL) / 2;
  }

  Node merge(Node l, Node r)
  {
    int isFull = l.isFull & r.isFull;
    int prefix = l.isFull ? l.prefix + r.prefix : l.prefix;
    int suffix = r.isFull ? r.suffix + l.suffix : r.suffix;
    long long pairs = l.pairs + r.pairs + numPairs(l.suffix + r.prefix) - numPairs(l.suffix) - numPairs(r.prefix);
    return Node(isFull, prefix, suffix, pairs);
  }

  SegmentTree(int low, int high, vector<int> &a): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high)
    {
      node = Node(a[low + 1] >= a[low]);
      return;
    }
    l = new SegmentTree(low, mid, a);
    r = new SegmentTree(mid + 1, high, a);
    node = merge(l->node, r->node);
  }

  void update(int x, int v)
  {
    if (low == high)
    {
      node = Node(v);
      return;
    }
    if (x <= mid) l->update(x, v);
    else r->update(x, v);
    node = merge(l->node, r->node);
  }

  Node get(int x, int y)
  {
    if (low == x && high == y)
      return node;
    Node t = x <= mid ? l->get(x, min(y, mid)) : Node(0);
    Node u = mid < y ? r->get(max(x, mid + 1), y) : Node(0);
    return merge(t, u);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  SegmentTree *tree;
  if (n > 1)
    tree = new SegmentTree(0, n - 2, a);
  while (q--)
  {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1)
    {
      x--;
      if (x && ((a[x - 1] <= a[x]) ^ (a[x - 1] <= y)))
        tree->update(x - 1, a[x - 1] <= y);
      if (x + 1 < n && ((a[x] <= a[x + 1]) ^ (y <= a[x + 1])))
        tree->update(x, y <= a[x + 1]);
      a[x] = y;
    }
    else if (x == y) cout << "1\n";
    else
    {
      auto ans = tree->get(x - 1, y - 2);
      cout << y - x + 1 + ans.pairs << '\n';
    }
  }
}