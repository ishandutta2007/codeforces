#include <bits/stdc++.h>
using namespace std;
const int N = 500500;
const int oo = 27081993;

struct SegmentTree
{
  int low, mid, high;
  int flipped;
  vector<int> maxDist;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, vector<int> &initial): low(low), high(high)
  {
    mid = (low + high) / 2;
    flipped = 0;
    if (low == high)
    {
      maxDist = {initial[low], -oo};
      return;
    }
    l = new SegmentTree(low, mid, initial);
    r = new SegmentTree(mid + 1, high, initial);
    for (int i : {0, 1})
      maxDist.push_back(max(l->maxDist[i], r->maxDist[i]));
  }

  void update(int x, int y)
  {
    if (low == x && high == y)
    {
      flipped ^= 1;
      swap(maxDist[0], maxDist[1]);
      return;
    }
    if (x <= mid)
      l->update(x, min(y, mid));
    if (mid < y)
      r->update(max(x, mid + 1), y);
    for (int i : {0, 1})
      maxDist[i ^ flipped] = max(l->maxDist[i], r->maxDist[i]);
  }
};

vector<int> a[N];
int dfsTime;

void dfs(int x, int par, vector<int> &dist, vector<int> &preDfs, vector<int> &postDfs)
{
  preDfs[x] = ++dfsTime;
  for (int y : a[x])
    if (y != par)
    {
      dist[y] = dist[x] + 1;
      dfs(y, x, dist, preDfs, postDfs);
    }
  postDfs[x] = dfsTime;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> edges;
  for (int i = 1; i < n; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    a[--x].push_back(--y);
    a[y].push_back(x);
    edges.push_back({x, y, z});
  }

  vector<int> dist0(n), preDfs0(n), postDfs0(n);
  dfsTime = 0;
  dfs(0, -1, dist0, preDfs0, postDfs0);

  // u-v is the diameter
  int u = max_element(begin(dist0), end(dist0)) - begin(dist0);
  vector<int> distU(n), preDfsU(n), postDfsU(n), initialU(n + 1);
  dfsTime = 0;
  dfs(u, -1, distU, preDfsU, postDfsU);
  for (int i = 0; i < n; i++)
    initialU[preDfsU[i]] = distU[i];

  int v = max_element(begin(distU), end(distU)) - begin(distU);
  vector<int> distV(n), preDfsV(n), postDfsV(n), initialV(n + 1);
  dfsTime = 0;
  dfs(v, -1, distV, preDfsV, postDfsV);
  for (int i = 0; i < n; i++)
    initialV[preDfsV[i]] = distV[i];

  SegmentTree treeU(1, n, initialU);
  SegmentTree treeV(1, n, initialV);
  for (auto [x, y, z] : edges)
    if (z)
    {
      treeU.update(max(preDfsU[x], preDfsU[y]), min(postDfsU[x], postDfsU[y]));
      treeV.update(max(preDfsV[x], preDfsV[y]), min(postDfsV[x], postDfsV[y]));
    }

  int q;
  cin >> q;
  while (q--)
  {
    int id;
    cin >> id;
    auto [x, y, z] = edges[--id];
    edges[id] = {x, y, z ^ 1};
    treeU.update(max(preDfsU[x], preDfsU[y]), min(postDfsU[x], postDfsU[y]));
    treeV.update(max(preDfsV[x], preDfsV[y]), min(postDfsV[x], postDfsV[y]));
    cout << max(treeU.maxDist[0], treeV.maxDist[0]) << '\n';
  }
}