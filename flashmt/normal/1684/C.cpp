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
    vector<vector<int>> a(n, vector<int>(m));

    int isGood = 1;
    set<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        cin >> a[i][j];
      auto b = a[i];
      sort(begin(b), end(b));
      vector<int> bad;
      for (int j = 0; j < m; j++)
        if (b[j] != a[i][j])
          bad.push_back(j);

      if (empty(bad))
        continue;

      int u = bad[0], v = bad[1];
      swap(a[i][u], a[i][v]);
      if (is_sorted(begin(a[i]), end(a[i]))) ans.insert({u, v});
      else isGood = 0;
      swap(a[i][u], a[i][v]);
    }

    if (!isGood || size(ans) > 1) cout << "-1\n";
    else if (empty(ans)) cout << "1 1\n";
    else
    {
      auto [u, v] = *begin(ans);
      for (int i = 0; i < n; i++)
      {
        swap(a[i][u], a[i][v]);
        if (!is_sorted(begin(a[i]), end(a[i])))
        {
          isGood = 0;
          break;
        }
      }

      if (isGood) cout << u + 1 << ' ' << v + 1 << '\n';
      else cout << "-1\n";
    }
  }
}