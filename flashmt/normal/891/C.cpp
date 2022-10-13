#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
const int W = 5e5;

vector<int> ans, queryEdges[N];
int ds[N], curFlag, flag[N], seen[N];

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

// return 1 if cycle is found
int dfs(int x, int par = -1)
{
  seen[x] = 1;
  if (par >= 0)
    queryEdges[x].erase(find(begin(queryEdges[x]), end(queryEdges[x]), par));
  for (int y : queryEdges[x])
    if (seen[y]) return 1;
    else if (dfs(y, x)) return 1;
  return 0;
}

int check(vector<pair<int, int>> &curEdges)
{
  vector<int> nodes;
  curFlag++;

  auto addNode = [&](int x)
  {
    if (flag[x] != curFlag)
    {
      flag[x] = curFlag;
      queryEdges[x].clear();
      seen[x] = 0;
      nodes.push_back(x);
    }
  };

  for (auto [x, y] : curEdges)
  {
    x = get(x);
    y = get(y);
    addNode(x);
    addNode(y);
    queryEdges[x].push_back(y);
    queryEdges[y].push_back(x);
  }

  for (int x : nodes)
    if (!seen[x])
      if (dfs(x, -1))
        return 0;

  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  iota(ds, ds + n, 0);
  vector<int> edgesAt[W];
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    edges.push_back({--x, --y, --w});
    edgesAt[w].push_back(i);
  }

  int q;
  cin >> q;
  ans.assign(q, 1);
  vector<pair<int, int>> queries[W];
  for (int i = 0; i < q; i++)
  {
    int k;
    cin >> k;
    while (k--)
    {
      int id;
      cin >> id;
      auto [x, y, w] = edges[--id];
      queries[w].push_back({id, i});
    }
  }

  for (int w = 0; w < W; w++)
  {
    for (int i = 0; i < size(queries[w]);)
    {
      int queryId = queries[w][i].second;
      vector<pair<int, int>> curEdges;
      while (i < size(queries[w]) && queries[w][i].second == queryId)
      {
        auto [edgeId, _] = queries[w][i++];
        auto [x, y, __] = edges[edgeId];
        curEdges.push_back({x, y});
      }
      ans[queryId] &= check(curEdges);
    }

    for (int i : edgesAt[w])
    {
      auto [x, y, _] = edges[i];
      int dx = get(x), dy = get(y);
      if (dx != dy)
        ds[dy] = dx;
    }
  }

  for (int x : ans)
    cout << (x ? "YES" : "NO") << '\n';
}