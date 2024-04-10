#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const pair<int, int> EMPTY = {0, 0}, FAILED = {-1, -1};

int n, per[N], id[N], p[N][20], depth[N], preDfs[N], postDfs[N], dfsCounter;
vector<int> a[200200];

int lca(int x, int y)
{
  if (depth[x] > depth[y])
    swap(x, y);

  for (int i = 17; i >= 0; i--)
    if (depth[y] - (1 << i) >= depth[x])
      y = p[y][i];
  if (x == y)
    return x;

  for (int i = 17; i >= 0; i--)
    if (p[x][i] != p[y][i])
    {
      x = p[x][i];
      y = p[y][i];
    }
  return p[x][0];
}

int isAncestor(int x, int y)
{
  return preDfs[x] <= preDfs[y] && postDfs[y] <= postDfs[x];
}

int isBetween(int x, int y, int z)
{
  return isAncestor(x, y) && isAncestor(y, z);
}

struct SegmentTree
{
  int low, mid, high;
  pair<int, int> v;
  SegmentTree *l, *r;

  int isGood(int x0, int x1, int y0, int y1)
  {
    int z = lca(x0, x1);
    if (!isBetween(z, y0, x0) && !isBetween(z, y0, x1))
      return 0;
    if (!isBetween(z, y1, x0) && !isBetween(z, y1, x1))
      return 0;
    return 1;
  }

  pair<int, int> merge(pair<int, int> x, pair<int, int> y)
  {
    if (x == EMPTY)
      return y;
    if (y == EMPTY)
      return x;
    if (x == FAILED || y == FAILED)
      return FAILED;
    int x0 = x.first, x1 = x.second, y0 = y.first, y1 = y.second;
    if (isGood(x0, x1, y0, y1))
      return {x0, x1};
    if (isGood(x0, y0, x1, y1))
      return {x0, y0};
    if (isGood(x0, y1, x1, y0))
      return {x0, y1};
    if (isGood(x1, y0, x0, y1))
      return {x1, y0};
    if (isGood(x1, y1, x0, y0))
      return {x1, y1};
    if (isGood(y0, y1, x0, x1))
      return {y0, y1};
    return FAILED;
  }

  SegmentTree(int low, int high, int id[]): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high) v = {id[low], id[low]};
    else
    {
      l = new SegmentTree(low, mid, id);
      r = new SegmentTree(mid + 1, high, id);
      v = merge(l->v, r->v);
    }
  }

  void update(int x, int id)
  {
    if (low == high) v = {id, id};
    else
    {
      if (x <= mid) l->update(x, id);
      else r->update(x, id);
      v = merge(l->v, r->v);
    }
  }

  int get(pair<int, int> curV)
  {
    if (low == high)
      return merge(curV, v) == FAILED ? low - 1 : low;
    auto newV = merge(curV, l->v);
    return newV == FAILED ? l->get(curV) : r->get(newV);
  }
};

void dfs(int x)
{
  preDfs[x] = ++dfsCounter;
  for (int y : a[x])
  {
    depth[y] = depth[x] + 1;
    dfs(y);
  }
  postDfs[x] = dfsCounter;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> per[i];
    id[per[i]] = i;
  }
  for (int i = 2; i <= n; i++)
  {
    cin >> p[i][0];
    a[p[i][0]].push_back(i);
  }

  dfs(1);
  for (int j = 0; j < 17; j++)
    for (int i = 1; i <= n; i++)
      p[i][j + 1] = p[p[i][j]][j];

  SegmentTree *tree = new SegmentTree(0, n - 1, id);

  int q;
  cin >> q;
  while (q--)
  {
    int op, x, y;
    cin >> op;
    if (op == 1)
    {
      cin >> x >> y;
      tree->update(per[x], y);
      tree->update(per[y], x);
      swap(per[x], per[y]);
    }
    else cout << tree->get(EMPTY) + 1 << '\n';
  }
}