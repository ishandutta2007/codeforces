#include <bits/stdc++.h>
using namespace std;
const int N = 500500;
const int oo = 27081993;

int n, m, q, p[N], isRemoved[N], ds[N], extraNode;
int dfsTime, preDfs[N], postDfs[N], mergeNode[N], initialValues[N];
vector<int> a[N];
pair<int, int> e[N], queries[N], child[N];

struct SegmentTree
{
  int low, mid, high;
  pair<int, int> value;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, int initialValues[]): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high) value = {initialValues[low], low};
    else
    {
      l = new SegmentTree(low, mid, initialValues);
      r = new SegmentTree(mid + 1, high, initialValues);
      value = max(l->value, r->value);
    }
  }

  void update(int x)
  {
    if (low == high)
    {
      value.first = 0;
      return;
    }
    if (x <= mid) l->update(x);
    else r->update(x);
    value = max(l->value, r->value);
  }

  pair<int, int> get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    auto t = x <= mid ? l->get(x, min(y, mid)) : make_pair(-oo, 0);
    auto u = mid < y ? r->get(max(x, mid + 1), y) : make_pair(-oo, 0);
    return max(t, u);
  }
};


int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

// return the corresponding extra node with this merge
int merge(int x, int y)
{
  int dx = get(x), dy = get(y);
  if (dx == dy)
    return 0;
  extraNode++;
  ds[dx] = ds[dy] = ds[extraNode] = extraNode;
  child[extraNode] = {dx, dy};
  return extraNode;
}

void dfs(int x)
{
  if (!x || preDfs[x])
    return;
  preDfs[x] = ++dfsTime;
  initialValues[preDfs[x]] = p[x];
  auto [u, v] = child[x];
  dfs(u);
  dfs(v);
  postDfs[x] = dfsTime;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
  {
    cin >> p[i];
    ds[i] = i;
  }
  for (int i = 1; i <= m; i++)
    cin >> e[i].first >> e[i].second;
  for (int i = 1; i <= q; i++)
  {
    cin >> queries[i].first >> queries[i].second;
    if (queries[i].first == 2)
      isRemoved[queries[i].second] = 1;
  }

  extraNode = n;
  for (int i = 1; i <= m; i++)
    if (!isRemoved[i])
      merge(e[i].first, e[i].second);

  for (int i = q; i; i--)
    if (queries[i].first == 2)
    {
      auto [x, y] = e[queries[i].second];
      mergeNode[i] = merge(x, y);
    }

  set<pair<int, int>> intervals;
  for (int i = extraNode; i; i--)
    if (!preDfs[i])
    {
      dfs(i);
      intervals.insert({preDfs[i], postDfs[i]});
    }

  SegmentTree *tree = new SegmentTree(1, extraNode, initialValues);
  for (int i = 1; i <= q; i++)
    if (queries[i].first == 1)
    {
      int x = queries[i].second;
      auto it = intervals.upper_bound(make_pair(preDfs[x], oo));
      assert(it != intervals.begin());
      it--;
      auto [ans, minNode] = tree->get(it->first, it->second);
      tree->update(minNode);
      cout << ans << '\n';
    }
    else if (mergeNode[i])
    {
      int x = mergeNode[i];
      auto it = intervals.find(make_pair(preDfs[x], postDfs[x]));
      assert(it != intervals.end());
      intervals.erase(it);
      auto [u, v] = child[x];
      intervals.insert({preDfs[u], postDfs[u]});
      intervals.insert({preDfs[v], postDfs[v]});
    }
}