#include <bits/stdc++.h>
using namespace std;

int n, color[300300];
vector<int> a[300300];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int  m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
      a[i].clear();
      color[i] = -1;
    }
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    queue<int> q;
    color[1] = 1;
    q.push(1);
    vector<int> ans;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      if (color[x])
      {
        ans.push_back(x);
        for (int y : a[x])
        {
          if (color[y] < 0)
            q.push(y);
          color[y] = 0;
        }
      }
      else
      {
        for (int y : a[x])
          if (color[y] < 0)
          {
            color[y] = 1;
            q.push(y);
          }
      }
    }

    int hasAns = 1;
    for (int i = 1; i <= n; i++)
      hasAns &= color[i] >= 0;
    if (!hasAns) cout << "NO\n";
    else
    {
      cout << "YES\n";
      cout << ans.size() << '\n';
      for (int x : ans)
        cout << x << ' ';
      cout << '\n';
    }
  }
}