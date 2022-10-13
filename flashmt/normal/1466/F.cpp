#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int n, m;
int ds[500500], isGood[500500], sz[500500];

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    sz[i] = 1;
    ds[i] = i;
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++)
  {
    int k, x, y;
    cin >> k >> x;
    if (k == 1)
    {
      int dx = get(x);
      if (!isGood[dx])
      {
        isGood[dx] = 1;
        ans.push_back(i);
      }
    }
    else
    {
      cin >> y;
      int dx = get(x), dy = get(y);
      if (dx != dy)
        if (!isGood[dx] || !isGood[dy])
        {
          ds[dy] = dx;
          sz[dx] += sz[dy];
          isGood[dx] |= isGood[dy];
          ans.push_back(i);
        }
    }
  }

  long long t = 1;
  for (int i = 1; i <= m; i++)
    if (i == get(i))
      for (int j = 0; j < sz[i] - 1 + isGood[i]; j++)
        t = t * 2 % BASE;

  cout << t << ' ' << ans.size() << '\n';
  for (int x : ans)
    cout << x << ' ';
}