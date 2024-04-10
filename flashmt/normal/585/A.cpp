#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, v[4444], d[4444], p[4444], out[4444] = {0};

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> v[i] >> d[i] >> p[i];

  vector <int> ans;
  while (1)
  {
    int x = 0;
    for (int i = 1; i <= n; i++)
      if (!out[i])
      {
        x = i;
        ans.push_back(i);
        break;
      }

    if (!x) break;

    out[x] = 1;
    queue <int> q;
    for (int i = x + 1, cur = v[x]; i <= n && cur > 0; i++)
      if (!out[i])
      {
        p[i] -= cur;
        if (p[i] < 0)
        {
          out[i] = 1;
          q.push(i);
        }
        cur--;
      }

    while (!q.empty())
    {
      int y = q.front();
      q.pop();
      for (int i = y + 1; i <= n; i++)
        if (!out[i])  
        {
          p[i] -= d[y];
          if (p[i] < 0)
          {
            out[i] = 1;
            q.push(i);
          }
        }
    }
  }

  cout << ans.size() << endl;
  for (auto x : ans)
    cout << x << ' ';
}