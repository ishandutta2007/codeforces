#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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
    vector<int> b(n + 1);
    vector<vector<int>> id(n + 2);
    for (int i = 1; i <= n; i++)
    {
      cin >> b[i];
      id[b[i]].push_back(i);
    }

    queue<int> q;
    q.push(0);
    q.push(n + 1);
    vector<int> ans;
    int k = 0;
    while (!empty(q))
    {
      int x = q.front();
      q.pop();
      if (empty(id[x]))
        continue;

      sort(begin(id[x]), end(id[x]), [&](int u, int v) { return size(id[u]) < size(id[v]); });
      for (int y : id[x])
      {
        ans.push_back(y);
        if (y < x)
          k = max(k, y);
      }
      q.push(ans.back());
    }

    assert(size(ans) == n);
    cout << k << '\n';
    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
}