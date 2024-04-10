#include <bits/stdc++.h>
using namespace std;
const int N = 200200;

int n, w[N], canTurn[N];
int low[N], num[N], flag[N], counter, sccId[N], numScc;
long long sccW[N], f[N], fTurn[N];
vector<int> a[N], st, b[N];

void dfs(int x, int par)
{
  low[x] = num[x] = counter++;
  st.push_back(x);
  flag[x] = 1;
  for (int y : a[x])
    if (y != par)
    {
      if (num[y] < 0)
        dfs(y, x);
      if (flag[y])
        low[x] = min(low[x], low[y]);
    }

  if (low[x] != num[x])
    return;

  int cnt = 0;
  while (1)
  {
    int y = st.back();
    st.pop_back();
    flag[y] = 0;
    sccId[y] = numScc;
    sccW[numScc] += w[y];
    cnt++;
    if (y == x)
      break;
  }
  canTurn[numScc] = cnt > 1;
  numScc++;
}

void calc(int x, int par)
{
  for (int y : b[x])
    if (y != par)
    {
      calc(y, x);
      canTurn[x] |= canTurn[y];
      fTurn[x] += fTurn[y];
    }

  for (int y : b[x])
    if (y != par)
      f[x] = max(f[x], fTurn[x] - fTurn[y] + f[y]);

  if (canTurn[x]) fTurn[x] += sccW[x];
  else fTurn[x] = 0;
  f[x] += sccW[x];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> w[i];
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  memset(num, -1, sizeof num);
  for (int i = 0; i < n; i++)
    if (num[i] < 0)
      dfs(i, -1);

  for (int x = 0; x < n; x++)
    for (int y : a[x])
      if (sccId[y] > sccId[x])
      {
        b[sccId[x]].push_back(sccId[y]);
        b[sccId[y]].push_back(sccId[x]);
      }

  int s;
  cin >> s;
  s = sccId[s - 1];

  calc(s, -1);
  cout << f[s] << endl;
}