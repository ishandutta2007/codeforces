#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, m, k, c[111];
long long p[111][111];
pair <long long, int> f[111][111][2];

void update(int j, int i, int color)
{
  long long cost = p[i][color] - p[j][color];
  for (int num = 1; num <= k; num++)
  {
    pair <long long, int> cur = make_pair(f[j][num - 1][color == f[j][num - 1][0].second].first + cost, color);
    if (cur < f[i][num][0])
    {
      f[i][num][1] = f[i][num][0];
      f[i][num][0] = cur;
    }
    else f[i][num][1] = min(f[i][num][1], cur);
  }
}

int main()
{
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      cin >> p[i][j];
      if (c[i]) 
        p[i][j] = 0;
      p[i][j] += p[i - 1][j];
    }

  for (int j = 1; j <= k; j++)
    f[0][j][0] = f[0][j][1] = make_pair(oo, 0);

  for (int i = 1; i <= n; i++)
  {
    for (int num = 0; num <= k; num++)
      f[i][num][0] = f[i][num][1] = make_pair(oo, 0);

    set <int> s;
    for (int j = i - 1; j >= 0; j--)
    {
      if (c[j + 1])
        s.insert(c[j + 1]);

      if (s.size() > 1)
        break;

      for (int color = 1; color <= m; color++)
        if (s.empty() || *s.begin() == color)
          update(j, i, color);
    }
  }

  cout << (f[n][k][0].first == oo ? -1 : f[n][k][0].first) << endl;
}