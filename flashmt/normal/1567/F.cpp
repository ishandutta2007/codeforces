#include <bits/stdc++.h>
using namespace std;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

vector<int> adj[250250];
int c[250250];

void noAns()
{
  cout << "NO" << endl;
  exit(0);
}

void go(int x, int curC)
{
  c[x] = curC;
  for (int y : adj[x])
    if (c[y] < 0) go(y, 5 - curC);
    else if (c[x] + c[y] != 5) noAns();
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<string> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];

  vector<pair<int, int>> isolated;
  memset(c, -1, sizeof c);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == 'X')
      {
        vector<pair<int, int>> neighbors;
        for (int k = 0; k < 4; k++)
        {
          int ii = i + DX[k], jj = j + DY[k];
          if (ii >= 0 && ii < m && jj >= 0 && jj < n && a[ii][jj] == '.')
            neighbors.push_back({ii, jj});
        }

        if (size(neighbors) % 2)
          noAns();

        c[i * n + j] = size(neighbors) / 2 * 5;
        if (size(neighbors) == 4)
        {
          isolated.push_back({i, j});
          adj[(i - 1) * n + j].push_back(i * n + j - 1);
          adj[i * n + j - 1].push_back((i - 1) * n + j);
          adj[i * n + j + 1].push_back((i + 1) * n + j);
          adj[(i + 1) * n + j].push_back(i * n + j + 1);
        }
        else if (size(neighbors) == 2)
        {
          auto [x, y] = neighbors[0];
          auto [xx, yy] = neighbors[1];
          adj[x * n + y].push_back(xx * n + yy);
          adj[xx * n + yy].push_back(x * n + y);
        }
      }

  for (int i = 0; i < m * n; i++)
    if (c[i] < 0)
      go(i, 1);

  for (auto [x, y] : isolated)
  {
    vector<int> cnt(5);
    for (int i = 0; i < 4; i++)
    {
      int xx = x + DX[i], yy = y + DY[i];
      cnt[c[xx * n + yy]]++;
    }
    if (cnt[1] > 2 || cnt[4] > 2)
      noAns();
  }

  cout << "YES\n";
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      if (a[i][j] == 'X') cout << c[i * n + j];
      else cout << max(c[i * n + j], 1);
      cout << " \n"[j == n - 1];
    }
}