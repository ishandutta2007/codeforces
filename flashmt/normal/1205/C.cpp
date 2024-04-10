#include <bits/stdc++.h>
using namespace std;

int n, a[55][55], f[2][55][55][55][55];
vector<tuple<int, int, int>> edges[55][55];

int ask(int ii, int jj, int i, int j)
{
  int resp;
  cout << "? " << ii << ' ' << jj << ' ' << i << ' ' << j << '\n';
  cout.flush();
  cin >> resp;
  return resp;
}

void write()
{
  cout << "!\n";
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      cout << a[i][j];
    cout << '\n';
  }
}

void dfs(int x, int y, int v)
{
  a[x][y] = v;
  for (auto u : edges[x][y])
  {
    int xx = get<0>(u), yy = get<1>(u), isEqual = get<2>(u);
    if (a[xx][yy] < 0)
      dfs(xx, yy, v ^ 1 ^ isEqual);
  }
}

int checkPalin(int ii, int jj, int i, int j)
{
  if (a[ii][jj] != a[i][j])
    return 0;
  if (ii == i)
    return a[ii][jj + 1] == a[i][j - 1];
  if (ii + 1 == i)
    return a[ii][jj + 1] == a[i - 1][j] || a[ii][jj + 1] == a[i][j - 1];
  if (ii + 2 == i)
    return a[ii + 1][jj] == a[i - 1][j] || a[ii + 1][jj] == a[i][j - 1];
  return a[ii + 1][jj] == a[i - 1][j];
}

void init()
{
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i % 2 != j % 2)
        a[i][j] = -1;
}

void attempt(int v)
{
  init();
  dfs(1, 2, v);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int di = 0; di <= 3; di++)
      {
        int ii = i - di, jj = j - (3 - di);
        if (ii < 1 || jj < 1)
          continue;
        f[v][ii][jj][i][j] = checkPalin(ii, jj, i, j);
      }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(a, -1, sizeof a);
  cin >> n;
  a[1][1] = 1;
  a[n][n] = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i % 2 == j % 2)
      {
        if (i + j == 2 || i + j == n * 2)
          continue;
        int ii = i, jj = j;
        if (j > 2) jj -= 2;
        else if (i > 2) ii -= 2;
        else ii = jj = 1;
        int isPalin = ask(ii, jj, i, j);
        a[i][j] = a[ii][jj] ^ 1 ^ isPalin;
      }
      else
      {
        if (i + j == 3)
          continue;
        int ii = i, jj = j;
        if (i == 1) jj -= 2;
        else if (j == 1) ii -= 2;
        else
        {
          ii--;
          jj--;
        }
        int isPalin = ask(ii, jj, i, j);
        edges[i][j].push_back({ii, jj, isPalin});
        edges[ii][jj].push_back({i, j, isPalin});
      }

  int isPalin = ask(1, 2, 3, 2);
  edges[1][2].push_back({3, 2, isPalin});
  edges[3][2].push_back({1, 2, isPalin});

  for (int v = 0; v < 2; v++)
    attempt(v);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int di = 0; di <= 3; di++)
      {
        int ii = i - di, jj = j - (3 - di);
        if (ii < 1 || jj < 1)
          continue;
        if (f[0][ii][jj][i][j] != f[1][ii][jj][i][j])
        {
          int isPalin = ask(ii, jj, i, j), v;
          if (isPalin == f[0][ii][jj][i][j]) v = 0;
          else v = 1;
          init();
          dfs(1, 2, v);
          write();
          return 0;
        }
      }
}