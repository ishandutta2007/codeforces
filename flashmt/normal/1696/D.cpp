#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    if (n == 1)
    {
      cout << 0 << '\n';
      continue;
    }

    vector<int> stInc = {0}, stDec = {0};
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
      int boundInc = -1;
      while (!empty(stInc) && a[stInc.back()] > a[i])
        stInc.pop_back();
      if (!empty(stInc))
        boundInc = stInc.back();

      int boundDec = -1;
      while (!empty(stDec) && a[stDec.back()] < a[i])
        stDec.pop_back();
      if (!empty(stDec))
        boundDec = stDec.back();

      {
        int low = 0, high = int(size(stInc)) - 1, res = -1;
        while (low <= high)
        {
          int mid = (low + high) / 2;
          if (stInc[mid] > boundDec)
          {
            res = stInc[mid];
            high = mid - 1;
          }
          else low = mid + 1;
        }
        if (res >= 0)
          adj[res].push_back(i);
      }

      {
        int low = 0, high = int(size(stDec)) - 1, res = -1;
        while (low <= high)
        {
          int mid = (low + high) / 2;
          if (stDec[mid] > boundInc)
          {
            res = stDec[mid];
            high = mid - 1;
          }
          else low = mid + 1;
        }
        if (res >= 0)
          adj[res].push_back(i);
      }

      stInc.push_back(i);
      stDec.push_back(i);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!empty(q))
    {
      int x = q.front();
      q.pop();
      for (int y : adj[x])
        if (dist[y] < 0)
        {
          dist[y] = dist[x] + 1;
          q.push(y);
        }
    }

    cout << dist[n - 1] << '\n';
  }
}