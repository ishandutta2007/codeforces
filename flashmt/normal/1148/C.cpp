#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, p[300300], id[300300];
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> p[i];
    id[p[i]] = i;
  }

  vector<pair<int, int>> ans;

  auto op = [&](int x, int y)
  {
    ans.push_back({x, y});
    swap(p[x], p[y]);
    id[p[x]] = x;
    id[p[y]] = y;
  };

  for (int i = 1; i <= n; i++)
  {
    if (p[i] == i)
      continue;

    if (abs(i - id[i]) >= n / 2) op(i, id[i]);
    else if (max(i, id[i]) <= n / 2)
    {
      op(id[i], n);
      op(i, n);
    }
    else if (min(i, id[i]) > n / 2)
    {
      int x = id[i];
      op(1, x);
      op(1, i);
      op(1, x);
    }
    else
    {
      int x = id[i];
      op(1, x);
      op(1, n);
      op(i, n);
      op(1, n);
      op(1, x);
    }
  }

  cout << ans.size() << '\n';
  for (auto u : ans)
    cout << u.first << ' ' << u.second << '\n';
}