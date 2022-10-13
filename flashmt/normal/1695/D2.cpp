#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 27081993;

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
    vector<vector<int>> a(n);
    for (int i = 0; i < n - 1; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
      a[y].push_back(x);
    }

    function<int(int, int)> dfs = [&](int x, int par)
    {
      int unpickedChildren = 0, res = 0;
      for (int y : a[x])
        if (y != par)
        {
          int u = dfs(y, x);
          res += u;
          if (!u)
            unpickedChildren++;
        }

      res += max(0, unpickedChildren - 1);
      return res;
    };


    int root = 0;
    for (int i = 1; i < n; i++)
      if (size(a[i]) > size(a[root]))
        root = i;
    int ans = dfs(root, -1);
    if (n > 1)
      ans = max(ans, 1);
    cout << ans << '\n';
  }
}