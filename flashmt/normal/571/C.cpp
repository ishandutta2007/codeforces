#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 200200;

int n, m, done[N], ans[N];
// 1-indexed
vector<int> v[N];
vector<pair<int, int>> clauseId[N], edges[N];

void constructGraph()
{
  for (int i = 1; i <= m; i++)
    if (empty(clauseId[i])) ans[i] = 0;
    else
    {
      auto [u, isPos] = clauseId[i][0];
      int v = 0, isPosV = isPos;
      if (size(clauseId[i]) == 2)
        tie(v, isPosV) = clauseId[i][1];

      if (isPosV != isPos)
      {
        if (!isPos)
          swap(u, v);
        edges[u].push_back({v, i});
        edges[v].push_back({u, -i});
      }
      else
      {
        ans[i] = isPos;
        done[u] = 1;
        if (v)
          done[v] = 1;
      }
    }
}

int solve()
{
  vector<int> deg(n + 1);
  set<pair<int, int>> s;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (done[i]) q.push(i);
    else
    {
      deg[i] = size(edges[i]);
      s.insert({deg[i], i});
    }

  while (1)
  {
    int x = 0;
    if (!empty(q))
    {
      x = q.front();
      q.pop();
    }
    else
    {
      // find a node with min degree
      while (!empty(s))
      {
        auto [_, u] = *begin(s);
        s.erase(begin(s));
        if (!done[u])
        {
          x = u;
          int found = 0;
          // find an unassigned edge
          for (auto [y, vId] : edges[x])
            if (ans[abs(vId)] < 0)
            {
              if (vId > 0) ans[vId] = 1;
              else ans[-vId] = 0;
              found = 1;
              s.erase({deg[y], y});
              s.insert({--deg[y], y});
              break;
            }

          if (found) break;
          else return 0;
        }
      }
    }

    if (!x)
      break;

    for (auto [y, vId] : edges[x])
      if (!done[y] && ans[abs(vId)] < 0)
      {
        done[y] = 1;
        q.push(y);
        if (vId < 0) ans[-vId] = 1;
        else ans[vId] = 0;
      }
  }

  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    int s;
    cin >> s;
    while (s--)
    {
      int x;
      cin >> x;
      v[i].push_back(x);
      clauseId[abs(x)].push_back({i, x > 0});
    }
  }

  memset(ans, -1, sizeof ans);
  constructGraph();
  if (!solve()) cout << "NO" << endl;
  else
  {
    cout << "YES" << endl;
    for (int i = 1; i <= m; i++)
      cout << max(0, ans[i]);
    cout << endl;
  }
}