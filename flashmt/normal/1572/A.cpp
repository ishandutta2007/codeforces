#include <bits/stdc++.h>
using namespace std;

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
    int n;
    cin >> n;
    TopoSort ts(n);
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      while (k--)
      {
        int x;
        cin >> x;
        ts.addEdge(i, --x);
      }
    }

    if (!ts.sort()) cout << "-1\n";
    else
    {
      vector<int> f(n, 1);
      for (int x : ts.order)
        for (int y : ts.a[x])
          f[y] = max(f[y], f[x] + (y > x));
      int ans = *max_element(begin(f), end(f));
      cout << ans << '\n';
    }
  }
}