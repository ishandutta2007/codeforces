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
    vector<int> a(n);
    vector<vector<int>> id(n + 1);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      id[a[i]].push_back(i);
    }

    int maxA = 0;
    for (int i = 1; i <= n; i++)
      if (size(id[i]) > size(id[maxA]))
        maxA = i;

    int numCycle = size(id[maxA]);
    vector<vector<int>> cycles(numCycle);
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < size(id[i]); j++)
        cycles[j].push_back(id[i][j]);

    vector<int> ans(n);
    for (auto cycle : cycles)
    {
      int len = size(cycle);
      for (int i = 0; i < len; i++)
      {
        int curId = cycle[i];
        int nextId = cycle[(i + 1) % len];
        ans[curId] = a[nextId];
      }
    }

    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
}