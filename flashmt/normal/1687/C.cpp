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
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a[i + 1] = a[i] + x;
    }
    vector<long long> b(n + 1);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      b[i + 1] = b[i] + x;
    }
    vector<vector<int>> segs(n + 1);
    while (m--)
    {
      int l, r;
      cin >> l >> r;
      segs[--l].push_back(r);
      segs[r].push_back(l);
    }

    if (a[n] != b[n])
    {
      cout << "NO\n";
      continue;
    }

    set<int> alive;
    queue<int> q;
    auto apply = [&](int l, int r)
    {
      if (l > r)
        swap(l, r);
      while (1)
      {
        auto u = alive.upper_bound(l);
        if (u == end(alive))
          break;
        int i = *u;
        if (i >= r)
          break;
        alive.erase(i);
        a[i] = b[i];
        q.push(i);
      }
    };

    for (int i = 0; i <= n; i++)
      if (a[i] == b[i]) q.push(i);
      else alive.insert(i);

    while (!empty(q))
    {
      int x = q.front();
      q.pop();
      for (int y : segs[x])
        if (a[y] == b[y])
          apply(x, y);
    }

    cout << (a == b ? "YES" : "NO") << '\n';
  }
}