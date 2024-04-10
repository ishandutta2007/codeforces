#include <bits/stdc++.h>
using namespace std;
const int N = 100100;

struct Edge
{
  int x, y;
  long long c;
};

struct SegmentTree
{
  int low, mid, high;
  long long v, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, long long initialDist[]): low(low), high(high)
  {
    mid = (low + high) / 2;
    save = 0;
    if (low == high) v = initialDist[low];
    else
    {
      l = new SegmentTree(low, mid, initialDist);
      r = new SegmentTree(mid + 1, high, initialDist);
      v = max(l->v, r->v);
    }
  }

  void pushDown()
  {
    l->v += save;
    l->save += save;
    r->v += save;
    r->save += save;
    save = 0;
  }

  void update(int x, int y, long long dif)
  {
    if (low == x && high == y)
    {
      v += dif;
      save += dif;
    }
    else
    {
      pushDown();
      if (x <= mid)
        l->update(x, min(y, mid), dif);
      if (mid < y)
        r->update(max(x, mid + 1), y, dif);
      v = max(l->v, r->v);
    }
  }

  long long get(int x, int y)
  {
    if (low == x && high == y)
      return v;
    pushDown();
    long long u = 0, v = 0;
    if (x <= mid)
      u = l->get(x, min(y, mid));
    if (mid < y)
      v = r->get(max(x, mid + 1), y);
    return max(u, v);
  }
};

struct CentroidData
{
  SegmentTree *segTree;
  multiset<long long> candidates;
  vector<pair<int, int>> segments;

  long long getAns()
  {
    if (candidates.empty())
      return 0;
    auto u = candidates.rbegin();
    return candidates.size() == 1 ? *u : *u + *(++u);
  }
};

struct CentroidNode
{
  int root, preDfs, postDfs, branchId;
};

int n, dfsTime;
Edge edges[N];
vector<pair<int, int>> adj[N];
long long initialDist[N];
multiset<long long> ans;
// centroid variables
int done[N], treeSize[N];
vector<int> activeNodes;
CentroidData centroidData[N];
vector<CentroidNode> centroidNodes[N];

void dfsPre(int x, int par, long long dist, int root, int branchId)
{
  int preDfs = ++dfsTime;
  initialDist[preDfs] = dist;
  for (auto u : adj[x])
  {
    int y = u.first;
    if (y != par && !done[y])
      dfsPre(y, x, dist + edges[u.second].c, root, branchId);
  }
  centroidNodes[x].push_back({root, preDfs, dfsTime, branchId});
}

void initCentroid(int root)
{
  int branchId = 0;
  dfsTime = 0;
  for (auto u : adj[root])
  {
    int x = u.first;
    if (!done[x])
    {
      dfsPre(x, root, edges[u.second].c, root, branchId);
      CentroidNode node = centroidNodes[x].back();
      centroidData[root].segments.push_back({node.preDfs, node.postDfs});
      branchId++;
    }
  }

  centroidNodes[root].push_back({root, 0, dfsTime, -1});
  centroidData[root].segTree = dfsTime > 0 ? new SegmentTree(1, dfsTime, initialDist) : NULL;
  for (auto u : centroidData[root].segments)
    centroidData[root].candidates.insert(centroidData[root].segTree->get(u.first, u.second));
  ans.insert(centroidData[root].getAns());
}

void dfs(int x, int par)
{
  activeNodes.push_back(x);
  treeSize[x] = 1;
  for (auto u : adj[x])
  {
    int y = u.first;
    if (!done[y] && y != par)
    {
      dfs(y, x);
      treeSize[x] += treeSize[y];
    }
  }
}

void decompose(int x)
{
  activeNodes.clear();
  dfs(x, 0);
  int centroid = x;
  for (int y : activeNodes)
    if (treeSize[y] * 2 >= treeSize[x] && treeSize[y] < treeSize[centroid])
      centroid = y;

  initCentroid(centroid);
  done[centroid] = 1;

  for (auto u : adj[centroid])
    if (!done[u.first])
      decompose(u.first);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long w, e;
  int q, x, y, d;
  long long c;
  cin >> n >> q >> w;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> x >> y >> c;
    adj[x].push_back({y, i});
    adj[y].push_back({x, i});
    edges[i] = {x, y, c};
  }

  decompose(1);

  long long curAns = 0;
  while (q--)
  {
    cin >> d >> e;
    int i = (d + curAns) % (n - 1), x = edges[i].x, y = edges[i].y;
    long long newC = (e + curAns) % w, diff = newC - edges[i].c;
    edges[i].c = newC;
    for (int j = 0; j < centroidNodes[x].size() && j < centroidNodes[y].size(); j++)
    {
      auto nodeX = centroidNodes[x][j], nodeY = centroidNodes[y][j];
      if (nodeX.root != nodeY.root)
        break;

      int root = centroidNodes[x][j].root;
      if (nodeX.preDfs > nodeY.preDfs)
        swap(nodeX, nodeY);

      ans.erase(ans.find(centroidData[root].getAns()));
      auto segment = centroidData[root].segments[nodeY.branchId];
      auto &segTree = centroidData[root].segTree;
      auto &candidates = centroidData[root].candidates;
      long long u = segTree->get(segment.first, segment.second);
      candidates.erase(candidates.find(u));
      segTree->update(nodeY.preDfs, nodeY.postDfs, diff);
      candidates.insert(segTree->get(segment.first, segment.second));
      ans.insert(centroidData[root].getAns());
    }
    curAns = *ans.rbegin();
    cout << curAns << '\n';
  }
}