#include <bits/stdc++.h>
using namespace std;

vector<int> a[100100];
int flag[100100];

void dfs(int x)
{
  flag[x] = 1;
  for (int y : a[x])
    if (!flag[y]) dfs(y);
    else if (flag[y] > 0)
    {
      cout << "Draw" << endl;
      exit(0);
    }
  flag[x] = -1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    int sz, j;
    cin >> sz;
    while (sz--)
    {
      cin >> j;
      a[i].push_back(--j);
    }
  }

  int s;
  cin >> s;
  s--;

  vector<vector<int>> tr(n, vector<int>(2, -1));
  tr[s][0] = 0;
  queue<pair<int, int>> q;
  q.push({s, 0});
  while (!empty(q))
  {
    auto [x, p] = q.front();
    q.pop();
    for (int y : a[x])
      if (tr[y][p ^ 1] < 0)
      {
        tr[y][p ^ 1] = x;
        q.push({y, p ^ 1});
      }
  }

  for (int x = 0; x < n; x++)
    if (empty(a[x]) && tr[x][1] >= 0)
    {
      cout << "Win" << endl;
      int p = 1;
      vector<int> path;
      while (1)
      {
        path.push_back(x);
        if (x == s && !p)
          break;
        x = tr[x][p];
        p ^= 1;
      }

      reverse(begin(path), end(path));
      for (int y : path)
        cout << y + 1 << ' ';
      return 0;
    }

  dfs(s);
  cout << "Lose" << endl;
}