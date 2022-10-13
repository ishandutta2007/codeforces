#include <bits/stdc++.h>
using namespace std;

int m, l[55], r[55], x[55], c[55], f[55][55][55];

int dp(int from, int to, int h)
{
  if (from > to || !h)
    return 0;
  if (f[from][to][h] >= 0)
    return f[from][to][h];

  int &res = f[from][to][h];
  res = dp(from, to, h - 1);

  int cost[55] = {0};
  for (int i = 0; i < m; i++)
    if (from <= l[i] && r[i] <= to && x[i] < h)
    {
      cost[l[i]] += c[i];
      cost[r[i] + 1] -= c[i];
    }

  for (int i = from; i <= to; i++)
  {
    cost[i] += cost[i - 1];
    res = max(res, dp(from, i - 1, h) + dp(i + 1, to, h) + h * h - cost[i]);
  }
  return res;
}

int main()
{
  int n, h;
  cin >> n >> h >> m;
  for (int i = 0; i < m; i++)
    cin >> l[i] >> r[i] >> x[i] >> c[i];
  memset(f, -1, sizeof f);
  cout << dp(1, n, h) << endl;
}