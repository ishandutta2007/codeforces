#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 60;

typedef tuple<int, int, int> Edge;

struct DisjointSet
{
  int n;
  vector<int> ds, sz;

  DisjointSet(int n): n(n)
  {
    ds = sz = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
      ds[i] = i;
      sz[i] = 1;
    }
  }

  int get(int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds[x]);
  }

  int join(int x, int y)
  {
    int dx = get(x), dy = get(y);
    if (dx == dy)
      return 0;
    if (sz[dx] < sz[dy])
      swap(dx, dy);
    ds[dy] = dx;
    sz[dx] += sz[dy];
    return 1;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    edges.push_back({--x, --y, w});
  }

  vector<int> candidates = {0};
  for (int i = 0; i < m; i++)
  {
    auto [x, y, w] = edges[i];
    candidates.push_back(w);
    for (int j = i + 1; j < m; j++)
    {
      auto [xx, yy, ww] = edges[j];
      candidates.push_back((w + ww) / 2);
      candidates.push_back((w + ww) / 2 + 1);
    }
  }

  sort(begin(candidates), end(candidates));
  int numCandidates = unique(begin(candidates), end(candidates)) - begin(candidates);
  candidates.resize(numCandidates);
  vector<pair<long long, int>> cost(numCandidates);
  for (int i = 0; i < numCandidates; i++)
  {
    int curW = candidates[i];
    sort(begin(edges), end(edges), [&](Edge u, Edge v) { return abs(get<2>(u) - curW) < abs(get<2>(v) - curW); });
    long long totalCost = 0;
    int delta = 0;
    DisjointSet ds(n);
    for (auto [x, y, w] : edges)
      if (ds.join(x, y))
      {
        totalCost += abs(curW - w);
        if (curW >= w) delta++;
        else delta--;
      }
    cost[i] = {totalCost, delta};
  }

  long long ans = 0;
  int p, k;
  long long a, b, c, q;
  cin >> p >> k >> a >> b >> c;
  for (int i = 0; i < k; i++)
  {
    if (i < p) cin >> q;
    else q = (q * a + b) % c;
    int id = upper_bound(begin(candidates), end(candidates), q) - begin(candidates);
    long long minCost = cost[id - 1].first + (q - candidates[id - 1]) * cost[id - 1].second;
    ans ^= minCost;
  }
  cout << ans << endl;
}