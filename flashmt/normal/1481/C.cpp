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
    vector<int> a(n), b(n), c(m), colorId(n, -1);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      a[i]--;
    }

    vector<vector<int>> need(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
      colorId[--b[i]] = i;
      if (b[i] != a[i])
        need[b[i]].push_back(i);
    }

    vector<int> ans(m, -1);
    int hasAns = 1;
    for (int i = 0; i < m; i++)
    {
      int x;
      cin >> x;
      x--;
      if (!need[x].empty())
      {
        ans[i] = need[x].back();
        need[x].pop_back();
        a[ans[i]] = x;
      }
      else if (colorId[x] >= 0)
      {
        ans[i] = colorId[x];
      }
    }

    for (int i = 0; i < n; i++)
      if (a[i] != b[i])
        hasAns = 0;
    if (ans[m - 1] < 0)
      hasAns = 0;

    if (!hasAns) cout << "NO\n";
    else
    {
      cout << "YES\n";
      for (int i = 0; i < m; i++)
        cout << (ans[i] < 0 ? ans[m - 1] : ans[i]) + 1 << " \n"[i == m - 1];
    }
  }
}