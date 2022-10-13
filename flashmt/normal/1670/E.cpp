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
    n = 1 << n;
    vector<vector<pair<int, int>>> a(n);
    for (int i = 0; i < n - 1; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back({--y, i});
      a[y].push_back({x, i});
    }

    vector<int> nodeValues(n), edgeValues(n - 1);
    int curValue = 1;

    function<void(int, int, int)> dfs = [&](int x, int par, int level)
    {
      for (auto [y, id] : a[x])
        if (y != par)
        {
          edgeValues[id] = curValue;
          nodeValues[y] = curValue + n;
          curValue++;
          if (level % 2 == 0)
            swap(edgeValues[id], nodeValues[y]);
          dfs(y, x, level ^ 1);
        }
    };

    nodeValues[0] = n;
    dfs(0, -1, 0);

    cout << "1\n";
    for (int x : nodeValues)
      cout << x << ' ';
    cout << '\n';
    for (int x : edgeValues)
      cout << x << ' ';
    cout << '\n';
  }
}