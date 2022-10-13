#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int BASE = 998244353;
const int oo = 27081993;

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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<vector<int>> adj(n);
    TopoSort ts(n);
    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      x--; y--;
      adj[x].push_back(y);
      ts.addEdge(x, y);
    }
    ts.sort();
    vector<int> order = ts.order;
    int goal = order.back();

    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
      b[i] = min(int(a[i]), oo);
      a[i] %= BASE;
    }

    for (int x : order)
      for (int y : adj[x])
      {
        a[y] += a[x];
        if (a[y] >= BASE)
          a[y] -= BASE;
      }

    long long ans = a[goal];
    // iterate the first n seconds
    for (int t = 0; t < n; t++)
    {
      int stop = 1;
      for (int x : b)
        if (x)
          stop = 0;
      if (stop)
        break;

      if (!b[goal])
        ans++;
      vector<int> newB(n);
      for (int x = 0; x < n; x++)
        if (b[x])
        {
          newB[x] += b[x] - 1;
          for (int y : adj[x])
            newB[y]++;
        }

      for (int i = 0; i < n; i++)
        newB[i] = min(newB[i], oo);
      swap(b, newB);
    }

    ans %= BASE;
    cout << ans << '\n';
  }
}