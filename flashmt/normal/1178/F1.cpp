#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, m, c[555], id[555], l[555], r[555], minVal[555][555];
long long f[555][555];

long long dp(int from, int to)
{
  if (from >= to)
    return 1;

  if (f[from][to] >= 0)
    return f[from][to];

  int color = minVal[from][to], curId = id[color];
  long long wayLeft = 0, wayRight = 0;
  for (int i = curId; i >= max(from, l[color]); i--)
    wayLeft = (wayLeft + dp(from, i - 1) * dp(i, curId - 1)) % BASE;
  for (int i = curId; i <= min(to, r[color]); i++)
    wayRight = (wayRight + dp(i + 1, to) * dp(curId + 1, i)) % BASE;

  f[from][to] = wayLeft * wayRight % BASE;
  return f[from][to];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> c[i];
    id[c[i]] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    l[i] = id[i];
    while (l[i] > 0 && c[l[i] - 1] > i)
      l[i]--;
    r[i] = id[i];
    while (r[i] + 1 < m && c[r[i] + 1] > i)
      r[i]++;
  }

  for (int i = 0; i < m; i++)
  {
    minVal[i][i] = c[i];
    for (int j = i + 1; j < m; j++)
      minVal[i][j] = min(minVal[i][j - 1], c[j]);
  }

  memset(f, -1, sizeof f);
  cout << dp(0, m - 1) << endl;
}