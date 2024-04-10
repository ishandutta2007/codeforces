#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

vector<int> path;
int tr[100100][3][3], color[100100];

void trace(int i, int x, int y)
{
  color[path[i]] = y;
  color[path[i - 1]] = x;
  if (i == 1)
    return;
  trace(i - 1, tr[i][x][y], x);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, c[3][100100];
  vector<int> a[100100];
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 1; j <= n; j++)
      cin >> c[i][j];

  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  int x = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].size() > 2)
    {
      cout << -1 << endl;
      return 0;
    }
    else if (a[i].size() == 1)
      x = i;

  int last = 0;
  while (1)
  {
    path.push_back(x);
    int found = 0;
    for (int y : a[x])
      if (y != last)
      {
        last = x;
        x = y;
        found = 1;
        break;
      }
    if (!found)
      break;
  }

  vector<vector<long long>> f = vector<vector<long long>>(3, vector<long long>(3, oo));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (i != j)
        f[i][j] = c[i][path[0]] + c[j][path[1]];

  for (int i = 2; i < n; i++)
  {
    vector<vector<long long>> newF = vector<vector<long long>>(3, vector<long long>(3, oo));
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        if (j != k)
        {
          int p = 3 - j - k;
          if (newF[k][p] > f[j][k] + c[p][path[i]])
          {
            newF[k][p] = f[j][k] + c[p][path[i]];
            tr[i][k][p] = j;
          }
        }
    f = newF;
  }

  long long ans = oo;
  int y;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (ans > f[i][j])
      {
        ans = f[i][j];
        x = i;
        y = j;
      }

  cout << ans << endl;
  trace(n - 1, x, y);
  for (int i = 1; i <= n; i++)
    cout << color[i] + 1 << ' ';
}