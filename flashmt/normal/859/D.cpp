#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

int n, p[77][77];
double prob[77][7], f[77][7];

int allOne(int x)
{
  return (1 << x) - 1;
}

pair <int, int> getRange(int x, int round)
{
  int low = x & (allOne(n) - allOne(round));
  int high = x | allOne(round);
  int mid = (low + high) / 2;
  if (x <= mid)
    return {mid + 1, high};
  return {low, mid};
}

double dp(int i, int round)
{
  if (!round)
    return 0;
  double &res = f[i][round];
  if (res > -EPS)
    return res;

  auto u = getRange(i, round);
  for (int j = u.first; j <= u.second; j++)
    res = max(res, dp(j, round - 1));
  res += prob[i][round] * (1 << round - 1) + dp(i, round - 1);
  return res;
}

int main()
{
  cin >> n;
  for (int i = 0; i < 1 << n; i++)
    for (int j = 0; j < 1 << n; j++)
      cin >> p[i][j];

  for (int i = 0; i < 1 << n; i++)
  {
    prob[i][0] = 1;
    for (int j = 0; j <= n; j++)
      f[i][j] = -1;
  }

  for (int round = 1; round <= n; round++)
    for (int i = 0; i < 1 << n; i++)
    {
      auto u = getRange(i, round);
      for (int j = u.first; j <= u.second; j++)
        if (j != i)
          prob[i][round] += prob[i][round - 1] * prob[j][round - 1] * p[i][j] / 100;
    }

  double ans = 0;
  for (int i = 0; i < 1 << n; i++)
    ans = max(ans, dp(i, n));
  cout << fixed << setprecision(9) << ans << endl;
}