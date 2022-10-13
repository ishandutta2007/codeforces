#include <bits/stdc++.h>
using namespace std;
const int N = 500500;
const long long oo = 1LL << 60;

struct SegmentTree
{
  int low, mid, high;
  long long minValue, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, vector<long long> &initialValues): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = 0;
    if (low == high) minValue = initialValues[low];
    else
    {
      l = new SegmentTree(low, mid, initialValues);
      r = new SegmentTree(mid + 1, high, initialValues);
      minValue = min(l->minValue, r->minValue);
    }
  }

  void pushDown()
  {
    if (save)
    {
      l->minValue += save;
      l->save += save;
      r->minValue += save;
      r->save += save;
      save = 0;
    }
  }

  void update(int x, int y, long long value)
  {
    if (low == x && high == y)
    {
      minValue += value;
      save += value;
    }
    else
    {
      pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), value);
      if (mid < y)
        r->update(max(x, mid + 1), y, value);
      minValue = min(l->minValue, r->minValue);
    }
  }

  long long get(int x, int y)
  {
    if (low == x && high == y)
      return minValue;
    pushDown();
    long long t = oo, u = oo;
    if (x <= mid)
      t = l->get(x, min(y, mid));
    if (mid < y)
      u = r->get(max(x, mid + 1), y);
    return min(t, u);
  }
};

int n, par[N], w[N];
vector<pair<int, int>> a[N];
long long dist[N], ans[N];
vector<tuple<int, int, int>> queries[N];
int dfsTime, preDfs[N], postDfs[N];
vector<long long> leafPreDfs, initialValues;

void dfs(int x)
{
  preDfs[x] = ++dfsTime;
  if (a[x].empty())
  {
    leafPreDfs.push_back(dfsTime);
    initialValues.push_back(dist[x]);
  }
  for (auto u : a[x])
  {
    int y = u.first, w = u.second;
    dist[y] = dist[x] + w;
    dfs(y);
  }
  preDfs[x] = lower_bound(leafPreDfs.begin(), leafPreDfs.end(), preDfs[x]) - leafPreDfs.begin();
  postDfs[x] = leafPreDfs.size() - 1;
}

void solve(int x, SegmentTree *tree)
{
  for (auto q : queries[x])
  {
    int from, to, id;
    tie(from, to, id) = q;
    from = lower_bound(leafPreDfs.begin(), leafPreDfs.end(), from) - leafPreDfs.begin();
    to = upper_bound(leafPreDfs.begin(), leafPreDfs.end(), to) - leafPreDfs.begin();
    ans[id] = tree->get(from, to - 1);
  }

  for (auto u : a[x])
  {
    int y = u.first, w = u.second;

    tree->update(preDfs[y], postDfs[y], -w);
    if (preDfs[y])
      tree->update(0, preDfs[y] - 1, w);
    if (postDfs[y] + 1 < leafPreDfs.size())
      tree->update(postDfs[y] + 1, leafPreDfs.size() - 1, w);

    solve(y, tree);

    tree->update(preDfs[y], postDfs[y], w);
    if (preDfs[y])
      tree->update(0, preDfs[y] - 1, -w);
    if (postDfs[y] + 1 < leafPreDfs.size())
      tree->update(postDfs[y] + 1, leafPreDfs.size() - 1, -w);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++)
  {
    cin >> par[i] >> w[i];
    a[par[i]].push_back({i, w[i]});
  }
  for (int i = 0; i < q; i++)
  {
    int v, l, r;
    cin >> v >> l >> r;
    queries[v].push_back({l, r, i});
  }

  dfs(1);
  SegmentTree *tree = new SegmentTree(0, leafPreDfs.size() - 1, initialValues);
  solve(1, tree);
  for (int i = 0; i < q; i++)
    cout << ans[i] << '\n';
}