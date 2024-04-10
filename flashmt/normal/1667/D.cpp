#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 2e5 + 5;

struct TopoSort
{
  int n;
  vector<vector<int>> a;
  vector<int> degIn, order;

  TopoSort(int n): n(n)
  {
    a = vector<vector<int>>(n);
    degIn = vector<int>(n);
  }

  void addEdge(int x, int y)
  {
    a[x].push_back(y);
    degIn[y]++;
  }

  int sort()
  {
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!degIn[i])
        q.push(i);
    while (!empty(q))
    {
      int x = q.front();
      q.pop();
      order.push_back(x);
      for (int y : a[x])
        if (!--degIn[y])
          q.push(y);
    }
    return size(order) == n;
  }
};

vector<int> a[N];
int par[N], edgeType[N];
TopoSort *ts;

int dfs(int x)
{
  vector<vector<int>> edgeId(2);
  for (int y : a[x])
    if (y != par[x])
    {
      par[y] = x;
      if (!dfs(y))
        return 0;
      edgeId[edgeType[y]].push_back(y);
    }

  if (par[x] >= 0)
  {
    edgeType[x] = size(edgeId[0]) >= size(edgeId[1]);
    edgeId[edgeType[x]].push_back(x);
  }

  vector<int> order;
  for (int i = 0; i < size(a[x]); i++)
  {
    int curType = (i + 1) % 2;
    if (empty(edgeId[curType]))
      return 0;
    order.push_back(edgeId[curType].back());
    edgeId[curType].pop_back();
  }

  for (int i = 0; i + 1 < size(order); i++)
    ts->addEdge(order[i], order[i + 1]);

  return 1;
}

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
    for (int i = 0; i < n; i++)
      a[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
      a[y].push_back(x);
    }

    par[0] = -1;
    ts = new TopoSort(n);
    if (!dfs(0))
    {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    ts->sort();
    auto ans = ts->order;
    reverse(begin(ans), end(ans));
    for (int i : ans)
      if (i)
        cout << par[i] + 1 << ' ' << i + 1 << '\n';
  }
}