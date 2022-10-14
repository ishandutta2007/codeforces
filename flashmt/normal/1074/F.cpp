#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
  int low, mid, high;
  int v, save, cnt;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    v = save = 0;
    cnt = high - low + 1;
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
      l->v += save;
      l->save += save;
      r->v += save;
      r->save += save;
      save = 0;
    }
  }

  void update(int x, int y, int value)
  {
    if (low == x && high == y)
    {
      v += value;
      save += value;
    }
    else
    {
      pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), value);
      if (mid < y)
        r->update(max(x, mid + 1), y, value);
      v = max(l->v, r->v);
      cnt = 0;
      if (l->v == v)
        cnt += l->cnt;
      if (r->v == v)
        cnt += r->cnt;
    }
  }
};

int preDfs[200200], postDfs[200200], dfsCount;
vector<int> a[200200];
vector<pair<int, int>> children[200200];

void dfs(int x, int par)
{
  preDfs[x] = ++dfsCount;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      children[x].push_back({preDfs[y], y});
    }
  postDfs[x] = dfsCount;
}

int findAncestor(int x, int y) // find ancestor of y that is direct child of x
{
  int id = upper_bound(children[x].begin(), children[x].end(), make_pair(preDfs[y], dfsCount)) - children[x].begin();
  return children[x][id - 1].second;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dfs(1, 0);
  SegmentTree *tree = new SegmentTree(1, n);
  set<pair<int, int>> edges;
  int expected = 0;
  while (q--)
  {
    int x, y;
    cin >> x >> y;
    if (preDfs[x] > preDfs[y])
      swap(x, y);

    int v = edges.count({x, y}) ? -1 : 1;
    expected += v;
    if (edges.count({x, y})) edges.erase({x, y});
    else edges.insert({x, y});

    if (postDfs[x] >= postDfs[y]) // x is ancestor of y
    {
      int z = findAncestor(x, y);
      tree->update(1, preDfs[z] - 1, v); // z != 1
      tree->update(preDfs[y], postDfs[y], v);
      if (postDfs[z] < n)
        tree->update(postDfs[z] + 1, n, v);
    }
    else // cross edge
    {
      tree->update(preDfs[x], postDfs[x], v);
      tree->update(preDfs[y], postDfs[y], v);
    }

    cout << (tree->v == expected ? tree->cnt : 0) << '\n';
  }
}