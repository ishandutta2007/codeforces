#include <bits/stdc++.h>
using namespace std;
const int N = 100100;

vector<int> a[N], comp[N], cntDist[N];
vector<long long> sumDist[N];
int flag[N], dist[N], maxDist[N], diameter[N];
map<pair<int, int>, double> cache;

void dfs(int x, int par)
{
  for (int y : a[x])
    if (y != par)
    {
      dist[y] = dist[x] + 1;
      if (flag[y] < 0)
      {
        flag[y] = flag[x];
        comp[flag[x]].push_back(y);
      }
      dfs(y, x);
    }
}

void build(int s)
{
  flag[s] = s;
  comp[s].push_back(s);

  dfs(s, -1);
  int u = s;
  for (int x : comp[s])
    if (dist[x] > dist[u])
      u = x;

  dist[u] = 0;
  dfs(u, -1);
  int v = s;
  for (int x : comp[s])
  {
    maxDist[x] = max(maxDist[x], dist[x]);
    if (dist[x] > dist[v])
      v = x;
  }
  diameter[s] = dist[v];

  dist[v] = 0;
  dfs(v, -1);
  for (int x : comp[s])
    maxDist[x] = max(maxDist[x], dist[x]);

  cntDist[s].assign(diameter[s] + 1, 0);
  sumDist[s].assign(diameter[s] + 1, 0);
  for (int x : comp[s])
  {
    cntDist[s][maxDist[x]]++;
    sumDist[s][maxDist[x]] += maxDist[x];
  }

  for (int i = 1; i <= diameter[s]; i++)
  {
    cntDist[s][i] += cntDist[s][i - 1];
    sumDist[s][i] += sumDist[s][i - 1];
  }
}

double query(int x, int y)
{
  if (diameter[x] < diameter[y])
    swap(x, y);

  if (cache.count({x, y}))
    return cache[{x, y}];

  double res = 0;
  for (int i = (diameter[y] + 1) / 2; i <= diameter[y]; i++)
  {
    int curCnt = cntDist[y][i];
    if (i)
      curCnt -= cntDist[y][i - 1];

    int boundX = diameter[x] - 1 - i;
    if (boundX < 0) res += (1. * sumDist[x][diameter[x]] / size(comp[x]) + i + 1) * curCnt;
    else
    {
      int cntLarge = cntDist[x][diameter[x]] - cntDist[x][boundX];
      double expectedLarge = 1. * (sumDist[x][diameter[x]] - sumDist[x][boundX]) / cntLarge + i + 1;
      res += (expectedLarge * cntLarge + 1. * diameter[x] * cntDist[x][boundX]) / size(comp[x]) * curCnt;
    }
  }
  res /= size(comp[y]);

  return cache[{x, y}] = res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  fill(flag, flag + n, -1);
  for (int i = 0; i < n; i++)
    if (flag[i] < 0)
      build(i);

  while (q--)
  {
    int x, y;
    cin >> x >> y;
    x = flag[x - 1];
    y = flag[y - 1];
    if (x == y) cout << "-1\n";
    else cout << fixed << setprecision(9) << query(x, y) << '\n';
  }
}