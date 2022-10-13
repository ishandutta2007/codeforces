#include <bits/stdc++.h>
using namespace std;
const int N = 400400;

int m, n, down[N], req[N], from[N], to[N], isCritical[N], seen[N];
string s[N];
vector<int> a[N], b[N];
int low[N], num[N], counter, sccId[N], numScc;
vector<int> st, cols[N];

int toInt(int row, int col)
{
  return row * n + col;
}

void visit(int x)
{
  low[x] = num[x] = counter++;
  st.push_back(x);
  for (int y : a[x])
    if (sccId[y] >= 0) continue;
    else if (num[y] >= 0) low[x] = min(low[x], num[y]);
    else
    {
      visit(y);
      low[x] = min(low[x], low[y]);
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

void constructSCC()
{
  for (int j = 0; j < n; j++)
  {
    int lastRow = m;
    for (int i = m - 1; i >= 0; i--)
    {
      int u = toInt(i, j);
      if (s[i][j] == '#')
      {
        cols[j].push_back(u);
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
      if (s[i][j] == '#')
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

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      int x = toInt(i, j);
      if (s[i][j] == '#')
        for (int y : a[x])
          if (sccId[y] != sccId[x])
            b[sccId[x]].push_back(sccId[y]);
    }
}

void unmark(int x)
{
  seen[x] = 1;
  for (int y : b[x])
    if (!seen[y])
    {
      isCritical[y] = 0;
      unmark(y);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    cin >> s[i];
  for (int i = 0; i < n; i++)
  {
    cin >> req[i];
    req[i]--;
  }

  constructSCC();
  vector<int> sccCol(numScc, n);
  for (int i = 0; i < n; i++)
    if (req[i] >= 0)
    {
      int u = sccId[cols[i][req[i]]];
      isCritical[u] = 1;
      sccCol[u] = min(sccCol[u], i);
    }

  for (int i = numScc - 1; i >= 0; i--)
    if (isCritical[i] && !seen[i])
      unmark(i);

  vector<pair<int, int>> ranges;
  vector<int> toCover;
  for (int i = 0; i < numScc; i++)
  {
    if (isCritical[i])
    {
      from[i] = to[i] = sccCol[i];
      toCover.push_back(sccCol[i]);
    }
    else
    {
      from[i] = n;
      to[i] = -1;
      for (int j : b[i])
      {
        from[i] = min(from[i], from[j]);
        to[i] = max(to[i], to[j]);
      }
    }
    if (from[i] <= to[i])
      ranges.push_back({from[i], to[i]});
  }

  int ans = 0, covered = -1;
  sort(toCover.begin(), toCover.end());
  sort(ranges.begin(), ranges.end());
  for (int i = 0, j = 0; i < toCover.size(); i++)
    if (toCover[i] > covered)
    {
      ans++;
      while (j < ranges.size() && ranges[j].first <= toCover[i])
        covered = max(covered, ranges[j++].second);
    }

  cout << ans << endl;
}