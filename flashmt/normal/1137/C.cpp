#include <bits/stdc++.h>
using namespace std;
const int N = 5000500;

int n, d, num[N], low[N], flag[N], counter, numScc, sccId[N], museums[N], seen[100100];
vector<int> a[100100], st, sccEdges[N];
string schedule[100100];

inline void dfs(int x)
{
  int u = x / d, du = x % d;
  low[x] = num[x] = counter++;
  st.push_back(x);
  flag[x] = 1;
  for (int v : a[u])
  {
    int dv = (du + 1) % d, y = v * d + dv;
    if (num[y] < 0)
      dfs(y);
    if (flag[y])
      low[x] = min(low[x], low[y]);
  }

  if (low[x] != num[x])
    return;

  while (1)
  {
    int y = st.back();
    st.pop_back();
    flag[y] = 0;
    sccId[y] = numScc;
    if (schedule[y / d][y % d] == '1' && seen[y / d] != numScc)
    {
      museums[numScc]++;
      seen[y / d] = numScc;
    }
    if (y == x)
      break;
  }
  numScc++;
}

int calc(int x)
{
  int res = 0;
  for (int y : sccEdges[x])
    res = max(res, calc(y));
  return res + museums[x];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, x, y;
  cin >> n >> m >> d;
  while (m--)
  {
    cin >> x >> y;
    a[--x].push_back(--y);
  }

  for (int i = 0; i < n; i++)
    cin >> schedule[i];

  memset(num, -1, sizeof num);
  memset(seen, -1, sizeof seen);
  for (int i = 0; i < n * d; i++)
    if (num[i] < 0)
      dfs(i);

  for (int x = 0; x < n; x++)
    for (int y : a[x])
      for (int dx = 0; dx < d; dx++)
      {
        int dy = (dx + 1) % d;
        int u = x * d + dx, v = y * d + dy;
        if (sccId[u] != sccId[v])
          sccEdges[sccId[u]].push_back(sccId[v]);
      }

  cout << calc(sccId[0]) << endl;
}