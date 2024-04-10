#include <bits/stdc++.h>
using namespace std;
const int N = 400400;

int m, n, down[N];
string s[N];
vector<int> a[N];
int low[N], num[N], counter, sccId[N], numScc;
vector<int> st;

int toInt(int row, int col)
{
  return row * n + col;
}

void visit(int x)
{
  low[x] = num[x] = counter++;
  st.push_back(x);
  for (int y : a[x])
    if (sccId[y] < 0)
    {
      if (num[y] >= 0) low[x] = min(low[x], num[y]);
      else
      {
        visit(y);
        low[x] = min(low[x], low[y]);
      }
    }

  if (num[x] != low[x])
    return;

  while (1)
  {
    int y = st.back();
    st.pop_back();
    sccId[y] = numScc;
    if (y == x)
      break;
  }
  numScc++;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    cin >> s[i];

  for (int j = 0; j < n; j++)
  {
    int lastRow = m;
    for (int i = m - 1; i >= 0; i--)
    {
      int u = toInt(i, j);
      if (s[i][j] == '#')
      {
        if (lastRow < m)
          a[u].push_back(toInt(lastRow, j));
        lastRow = i;
        if (i && s[i - 1][j] == '#')
          a[u].push_back(toInt(i - 1, j));
      }
      down[u] = lastRow;
    }
  }

  for (int j = 0; j < n; j++)
    for (int i = 0; i < m; i++)
    {
      int u = toInt(i, j);
      for (int jj = j - 1; jj <= j + 1; jj += 2)
        if (jj >= 0 && jj < n)
        {
          int v = toInt(i, jj);
          if (down[v] < m)
            a[u].push_back(toInt(down[v], jj));
        }
    }

  memset(sccId, -1, sizeof sccId);
  memset(num, -1, sizeof num);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      int x = toInt(i, j);
      if (s[i][j] == '#' && sccId[x] < 0)
        visit(x);
    }

  vector<int> degIn(numScc, 0);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      int x = toInt(i, j);
      if (s[i][j] == '#')
        for (int y : a[x])
          if (sccId[y] != sccId[x])
            degIn[sccId[y]]++;
    }

  int ans = 0;
  for (int x : degIn)
    if (!x)
      ans++;

  cout << ans << endl;
}