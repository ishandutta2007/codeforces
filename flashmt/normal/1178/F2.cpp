#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, m, c[1000100], newC[1010], minVal[1010][1010];
int firstId[555], lastId[555], isFirst[1010], isLast[1010], l[1000100], r[1000100];
int newL[1010], newR[1010];
vector<int> id[555];
long long f[1010][1010];

long long dp(int from, int to)
{
  if (from > to)
    return 1;

  if (!isFirst[from] || !isLast[to])
    return 0;

  if (from == to)
    return 1;

  if (f[from][to] >= 0)
    return f[from][to];

  int color = minVal[from][to];
  long long wayLeft = 0, wayRight = 0;

  for (int i = firstId[color]; i >= max(from, newL[firstId[color]]); i--)
    wayLeft = (wayLeft + dp(from, i - 1) * dp(i, firstId[color] - 1)) % BASE;
  for (int i = lastId[color]; i <= min(to, newR[lastId[color]]); i++)
    wayRight = (wayRight + dp(i + 1, to) * dp(lastId[color] + 1, i)) % BASE;

  f[from][to] = wayLeft * wayRight % BASE * dp(firstId[color] + 1, lastId[color] - 1) % BASE;
  return f[from][to];
}

void calcLR()
{
  for (int i = 0; i < m; i++)
  {
    l[i] = i;
    while (l[i] > 0 && c[i] <= c[l[i] - 1])
      l[i] = l[l[i] - 1];
  }
  for (int i = m - 1; i >= 0; i--)
  {
    r[i] = i;
    while (r[i] + 1 < m && c[i] <= c[r[i] + 1])
      r[i] = r[r[i] + 1];
  }

  for (int i = 1; i <= n; i++)
    if (r[id[i][0]] < id[i].back())
    {
      cout << 0 << endl;
      exit(0);
    }
}

void compress()
{
  for (int i = 1; i <= n; i++)
  {
    firstId[i] = id[i][0];
    lastId[i] = id[i].back();
  }
  int newM = 1;
  isFirst[0] = 1;
  if (0 == lastId[c[0]])
    isLast[0] = 1;
  newC[0] = 0;
  for (int i = 1; i < m; i++)
    if (i == firstId[c[i]] || i == lastId[c[i]])
    {
      if (i == firstId[c[i]]) isFirst[newM] = 1;
      if (i == lastId[c[i]]) isLast[newM] = 1;
      newC[newM++] = i;
    }

  m = newM;
  for (int i = 0; i < m; i++)
  {
    if (isFirst[i])
      firstId[c[newC[i]]] = i;
    if (isLast[i])
      lastId[c[newC[i]]] = i;
  }
}

void init()
{
  for (int i = 0; i < m; i++)
  {
    int id = newC[i];
    newR[i] = upper_bound(newC, newC + m, r[id]) - newC;
    newR[i]--;
    newL[i] = lower_bound(newC, newC + m, l[id]) - newC;
  }

  for (int i = 0; i < m; i++)
  {
    minVal[i][i] = c[newC[i]];
    for (int j = i + 1; j < m; j++)
      minVal[i][j] = min(minVal[i][j - 1], c[newC[j]]);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> c[i];
    id[c[i]].push_back(i);
  }

  calcLR();
  compress();
  init();

  memset(f, -1, sizeof f);
  cout << dp(0, m - 1) << endl;
}