#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;

int depth, n, dist[N], checkStatus, candidate, isGood[N], maxDepth[N];
vector<int> a[N], path;
set<int> ans;

void findFurthest(int x, int par)
{
  for (int y : a[x])
    if (y != par)
    {
      dist[y] = dist[x] + 1;
      findFurthest(y, x);
    }
}

int findPath(int u, int v, int par)
{
  path.push_back(u);
  if (u == v)
    return 1;

  for (int x : a[u])
    if (x != par)
      if (findPath(x, v, u))
        return 1;

  path.pop_back();
  return 0;
}

void verifyChildCnt(int childCnt, int expectedChildCnt)
{
  if (childCnt != expectedChildCnt)
    checkStatus = -1;
}

void calcDepth(int x, int par, int curDepth)
{
  maxDepth[x] = curDepth;
  for (int y : a[x])
    if (y != par)
    {
      calcDepth(y, x, curDepth + 1);
      maxDepth[x] = max(maxDepth[x], maxDepth[y]);
    }
}

void dfsCheck(int x, int par, int curDepth, int passed)
{
  if (maxDepth[x] + passed > depth)
  {
    checkStatus = -1;
    return;
  }

  int childCnt = 0;
  for (int y : a[x])
    if (y != par)
      childCnt++;

  if (childCnt == 3 || childCnt == 1)
  {
    if (passed || checkStatus) checkStatus = -1;
    else if ((childCnt == 3) ^ (curDepth + 1 == depth))
    {
      checkStatus = 1;
      candidate = x;
    }
  }
  else if (curDepth == depth - passed) verifyChildCnt(childCnt, 0);
  else verifyChildCnt(childCnt, 2);


  if (checkStatus < 0)
    return;

  for (int y : a[x])
    if (y != par)
      dfsCheck(y, x, curDepth + 1, passed | (candidate == x && maxDepth[y] < maxDepth[x]));
}

void check(int root)
{
  checkStatus = candidate = 0;
  memset(isGood, 0, sizeof isGood);
  calcDepth(root, 0, 1);
  dfsCheck(root, 0, 1, 0);
  if (checkStatus == 1)
    ans.insert(candidate);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> depth;
  n = (1 << depth) - 1;
  for (int i = 0; i < n - 2; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dist[1] = 0;
  findFurthest(1, 0);
  int u = 1;
  for (int i = 2; i <= n; i++)
    if (dist[i] > dist[u])
      u = i;

  dist[u] = 0;
  findFurthest(u, 0);
  int v = 1;
  for (int i = 2; i <= n; i++)
    if (dist[i] > dist[v])
      v = i;

  findPath(u, v, 0);

  if (dist[v] % 2 == 0) check(path[dist[v] / 2]);
  else
  {
    check(path[dist[v] / 2]);
    check(path[dist[v] / 2 + 1]);
  }

  cout << ans.size() << endl;
  for (int x : ans)
    cout << x << ' ';
}