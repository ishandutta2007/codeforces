#include <bits/stdc++.h>
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
    vector<vector<int>> a(n, vector<int>());
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
    }

    vector<int> ans, maxPath(n);
    for (int x = 0; x < n; x++)
      if (maxPath[x] == 2) ans.push_back(x);
      else
        for (int y : a[x])
          maxPath[y] = max(maxPath[y], maxPath[x] + 1);

    cout << size(ans) << '\n';
    for (int x : ans)
      cout << x + 1 << ' ';
    cout << '\n';
  }
}