#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 9;

int n, k, dist[2020][2020];
string a[2020];
pair<int, int> tr[2020][2020];
long long val[2020][2020];

// fill as many "a"s as possible
void fillA()
{
  deque<pair<int, int>> q;
  memset(dist, -1, sizeof dist);
  dist[0][0] = a[0][0] != 'a';
  q.push_back({0, 0});

  while (!q.empty())
  {
    int x = q.front().first, y = q.front().second;
    q.pop_front();

    if (x + 1 < n)
    {
      int newDist = dist[x][y] + (a[x + 1][y] != 'a');
      if (dist[x + 1][y] < 0 || dist[x + 1][y] > newDist)
      {
        dist[x + 1][y] = newDist;
        if (newDist > dist[x][y]) q.push_back({x + 1, y});
        else q.push_front({x + 1, y});
      }
    }

    if (y + 1 < n)
    {
      int newDist = dist[x][y] + (a[x][y + 1] != 'a');
      if (dist[x][y + 1] < 0 || dist[x][y + 1] > newDist)
      {
        dist[x][y + 1] = newDist;
        if (newDist > dist[x][y]) q.push_back({x, y + 1});
        else q.push_front({x, y + 1});
      }
    }
  }
}

// find min remaining path
void findRemainingPath(int dia)
{
  for (int i = 0; i <= dia; i++)
    cout << 'a';

  if (dia == n * 2 - 2)
    exit(0);

  vector<pair<int, int>> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      tr[i][j] = {-1, -1};
  if (dia < 0)
  {
    q.push_back({0, 0});
    val[0][0] = a[0][0] - 'a' + 1;
  }
  else
  {
    vector<pair<int, int>> cells[26];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (dist[i][j] <= k && i + j == dia)
        {
          if (i + 1 < n && !val[i + 1][j])
          {
            cells[a[i + 1][j] - 'a'].push_back({i + 1, j});
            val[i + 1][j] = a[i + 1][j] - 'a' + 1;
          }
          if (j + 1 < n && !val[i][j + 1])
          {
            cells[a[i][j + 1] - 'a'].push_back({i, j + 1});
            val[i][j + 1] = a[i][j + 1] - 'a' + 1;
          }
        }

    for (int c = 0; c < 26; c++)
      for (auto u : cells[c])
        q.push_back(u);
  }

  vector<pair<int, int>> cells[26];
  for (int i = 0; i < q.size();)
  {
    int x = q[i].first, y = q[i].second, j = i;
    while (j < q.size())
    {
      int xx = q[j].first, yy = q[j].second;
      if (xx + yy != x + y || val[xx][yy] != val[x][y])
        break;

      if (xx + 1 < n && tr[xx + 1][yy].first < 0)
      {
        tr[xx + 1][yy] = {xx, yy};
        val[xx + 1][yy] = (val[xx][yy] * 29 + a[xx + 1][yy] - 'a' + 1) % BASE;
        cells[a[xx + 1][yy] - 'a'].push_back({xx + 1, yy});
      }
      if (yy + 1 < n && tr[xx][yy + 1].first < 0)
      {
        tr[xx][yy + 1] = {xx, yy};
        val[xx][yy + 1] = (val[xx][yy] * 29 + a[xx][yy + 1] - 'a' + 1) % BASE;
        cells[a[xx][yy + 1] - 'a'].push_back({xx, yy + 1});
      }
      j++;
    }

    for (int c = 0; c < 26; c++)
    {
      for (auto u : cells[c])
        q.push_back(u);
      cells[c].clear();
    }

    i = j;
  }
}

void trace(int x, int y)
{
  if (tr[x][y].first >= 0)
    trace(tr[x][y].first, tr[x][y].second);
  cout << a[x][y];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  fillA();

  int dia = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (dist[i][j] <= k)
        dia = max(dia, i + j);

  findRemainingPath(dia);
  trace(n - 1, n - 1);
  cout << endl;
}