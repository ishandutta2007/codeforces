#include <bits/stdc++.h>
using namespace std;

int n, q, dfsTime, timeIn[200200], timeOut[200200], par[200200], flag[200200], ans[200200];
vector<int> a[200200], queries[200200], qId[200200];

void visit(int x)
{
  timeIn[x] = ++dfsTime;
  for (int y : a[x])
    if (y != par[x])
    {
      par[y] = x;
      visit(y);
    }
  timeOut[x] = dfsTime;
}

void go(int x)
{
  flag[x] = 1;
  for (int id : qId[x])
  {
    ans[id] = 1;
    for (int i : queries[id])
      ans[id] &= flag[i] || flag[par[i]];
  }
  for (int y : a[x])
    if (y != par[x])
      go(y);
  flag[x] = 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  visit(1);
  for (int i = 0; i < q; i++)
  {
    int k, x;
    cin >> k;
    while (k--)
    {
      cin >> x;
      queries[i].push_back(x);
    }

    // sort by timeOut and which is the best node to travel to for this query
    sort(queries[i].begin(), queries[i].end(), [](int u, int v) { return timeOut[u] < timeOut[v]; });
    int node = 1;
    for (int x : queries[i])
      if (timeIn[x] > timeOut[node]) break;
      else if (timeIn[x] > timeIn[node] && timeOut[x] <= timeOut[node]) node = par[x];
    qId[node].push_back(i);
  }

  go(1);
  for (int i = 0; i < q; i++)
    cout << (ans[i] ? "YES" : "NO") << '\n';
}