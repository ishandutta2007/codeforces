#include <bits/stdc++.h>
using namespace std;
const int N = 666;
const int M = N * N;
const int oo = 1000111000;

int n, m, cost[N][N], dist[N];

inline int getNext(int x)
{
  return x + 1 < n ? x + 1 : 0;
}

void solve(int s)
{
  int minCost = *min_element(cost[s], cost[s] + n);
  vector<int> ans(n, minCost + n - 1);
  ans[s] = 0;

  for (int i = 0; i < n; i++)
    dist[i] = oo;

  queue<int> q[N];
  for (int i = 0; i < n; i++)
    if (cost[s][i] < oo && cost[s][i] - minCost < n)
    {
      dist[i] = cost[s][i];
      q[cost[s][i] - minCost].push(i);
    }

  for (int curDist = minCost; curDist < minCost + n; curDist++)
    while (!q[curDist - minCost].empty())
    {
      int x = q[curDist - minCost].front();
      q[curDist - minCost].pop();
      if (dist[x] != curDist)
        continue;

      ans[x] = min(ans[x], curDist);

      if (curDist + 1 < minCost + n) // move 1 step
      {
        int y = getNext(x);
        if (curDist + 1 < dist[y])
        {
          dist[y] = curDist + 1;
          q[curDist + 1 - minCost].push(y);
        }
      }

      for (int i = 0; i < n; i++)
        if (cost[x][i] < oo)
        {
          int newDist = curDist + cost[x][i], y = (i + curDist % n) % n;
          if (newDist < minCost + n && newDist < dist[y])
          {
            dist[y] = newDist;
            q[newDist - minCost].push(y);
          }
        }
    }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cost[i][j] = oo;
  while (m--)
  {
    int x, y, z;
    cin >> x >> y >> z;
    cost[x][y] = min(cost[x][y], z);
  }

  for (int i = 0; i < n; i++)
    solve(i);
}