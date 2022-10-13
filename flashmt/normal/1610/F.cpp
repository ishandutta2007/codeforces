#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 300300;

int n, w[N], flag[N];
vector<tuple<int, int, int>> a[N];
vector<int> nodeW, curW, ans;
vector<pair<int, int>> edges;

bool cmp(tuple<int, int, int> u, tuple<int, int, int> v)
{
  auto [yU, idU, dirU] = u;
  auto [yV, idV, dirV] = v;
  return nodeW[yU] > nodeW[yV] || (nodeW[yU] == nodeW[yV] && w[idU] > w[idV]);
}

void setEdge(int i, int dir)
{
  ans[i] = dir;
  auto [x, y] = edges[i];
  if (dir == 1)
  {
    curW[x] += w[i];
    curW[y] -= w[i];
  }
  else
  {
    curW[x] -= w[i];
    curW[y] += w[i];
  }
}

void bfs(int s)
{
  queue<int> q;
  q.push(s);
  flag[s] = 1;
  while (!empty(q))
  {
    int x = q.front();
    q.pop();
    for (auto [y, id, dir] : a[x])
    {
      if (ans[id])
        continue;

      if (!nodeW[y])
      {
        if (curW[x] <= 0) setEdge(id, dir);
        else setEdge(id, 3 - dir);
      }
      else
      {
        if (abs(curW[x]) >= abs(curW[y]))
        {
          if (curW[x] <= 0) setEdge(id, dir);
          else setEdge(id, 3 - dir);
        }
        else
        {
          if (curW[y] <= 0) setEdge(id, 3 - dir);
          else setEdge(id, dir);
        }

        if (!flag[y])
        {
          flag[y] = 1;
          q.push(y);
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  nodeW.assign(n, 0);
  curW.assign(n, 0);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y >> w[i];
    a[--x].push_back({--y, i, 1});
    a[y].push_back({x, i, 2});
    edges.push_back({x, y});
    if (w[i] == 1)
    {
      nodeW[x] ^= 1;
      nodeW[y] ^= 1;
    }
  }

  ans.assign(m, 0);
  for (int i = 0; i < n; i++)
    sort(begin(a[i]), end(a[i]), cmp);

  for (int i = 0; i < n; i++)
    if (!flag[i] && nodeW[i])
      bfs(i);

  for (int i = 0; i < n; i++)
    if (nodeW[i] && abs(curW[i]) != 1)
      assert(0);

  int total = accumulate(begin(nodeW), end(nodeW), 0);
  cout << total << endl;
  for (int x : ans)
    cout << max(x, 1);
  cout << endl;
}