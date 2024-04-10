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
    vector<int> p(n);
    for (int &x : p)
    {
      cin >> x;
      x--;
    }

    vector<vector<int>> cycles;
    vector<int> flag(n);
    for (int i = 0; i < n; i++)
      if (!flag[i])
      {
        int x = i;
        vector<int> cycle;
        while (!flag[x])
        {
          cycle.push_back(x);
          flag[x] = 1;
          x = p[x];
        }
        auto minEle = min_element(begin(cycle), end(cycle));
        rotate(begin(cycle), minEle, end(cycle));
        cycles.push_back(cycle);
      }

    sort(begin(cycles), end(cycles));
    vector<int> ans = cycles[0];
    reverse(begin(ans) + 1, end(ans));
    for (int i = 1; i < size(cycles); i++)
    {
      auto cycle = cycles[i];
      for (int j = 0; j < size(ans); j++)
        if (ans[j] == cycle[0] - 1)
        {
          reverse(begin(cycle), end(cycle));
          ans.insert(begin(ans) + j + 1, begin(cycle), end(cycle));
          break;
        }
    }

    int weight = 0;
    for (int i = 0; i < n; i++)
      weight += abs(ans[i] - p[ans[(i + 1) % n]]);
    assert(weight == (size(cycles) - 1) * 2);

    for (int x : ans)
      cout << x + 1 << ' ';
    cout << endl;
  }
}