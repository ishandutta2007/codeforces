#include <bits/stdc++.h>
using namespace std;
const int INF = 27081993;

int minCost(vector<vector<int>> a)
{
  int n = a.size();
  int m = n * 2 + 2;
  vector<vector<int>> f(m, vector<int>(m));
  int s = m - 2, t = m - 1;
  int cost = 0;
  while (1)
  {
    vector<int> dist(m, INF);
    vector<int> p(m);
    vector<bool> inq(m, false);
    queue<int> q;
    dist[s] = 0;
    p[s] = -1;
    q.push(s);
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      inq[v] = false;
      if (v == s)
      {
        for (int i = 0; i < n; ++i)
        {
          if (f[s][i] == 0)
          {
            dist[i] = 0;
            p[i] = s;
            inq[i] = true;
            q.push(i);
          }
        }
      }
      else if (v < n) {
        for (int j = n; j < n + n; ++j)
        {
          if (f[v][j] < 1 && dist[j] > dist[v] + a[v][j - n])
          {
            dist[j] = dist[v] + a[v][j - n];
            p[j] = v;
            if (!inq[j])
            {
              q.push(j);
              inq[j] = true;
            }
          }
        }
      }
      else
      {
        for (int j = 0; j < n; ++j)
          if (f[v][j] < 0 && dist[j] > dist[v] - a[j][v - n])
          {
            dist[j] = dist[v] - a[j][v - n];
            p[j] = v;
            if (!inq[j])
            {
              q.push(j);
              inq[j] = true;
            }
          }
      }
    }

    int curcost = INF;
    for (int i = n; i < n + n; ++i)
      if (f[i][t] == 0 && dist[i] < curcost)
      {
        curcost = dist[i];
        p[t] = i;
      }
    if (curcost == INF)
      break;
    cost += curcost;
    for (int cur = t; cur != -1; cur = p[cur])
    {
      int prev = p[cur];
      if (prev != -1)
        f[cur][prev] = -(f[prev][cur] = 1);
    }
  }

  int res = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (f[i][j + n] == 1)
        res += a[i][j];

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n, t[222];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> t[i];

    int m = n + 100;
    vector<vector<int>> a(m, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        a[i][j] = abs(j + 1 - t[i]);

    cout << minCost(a) << endl;
  }
}