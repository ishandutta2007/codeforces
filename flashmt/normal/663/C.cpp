#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int oo = 27081993;

vector<pair<int, int>> a[N];
int done[N], flipped[N][2];

vector<int> solve(int u)
{
  vector<int> q = {u}, res(2);
  done[u] = 1;
  for (int i = 0; i < size(q); i++)
  {
    int x = q[i];
    for (auto [y, c] : a[x])
      if (!done[y])
      {
        done[y] = 1;
        q.push_back(y);
        for (int goal = 0; goal < 2; goal++)
        {
          flipped[y][goal] = c ^ flipped[x][goal] ^ goal;
          res[goal] = min(oo, res[goal] + flipped[y][goal]);
        }
      }
      else
      {
        for (int goal = 0; goal < 2; goal++)
          if ((c ^ flipped[x][goal] ^ flipped[y][goal]) != goal)
            res[goal] = oo;
      }
  }

  for (int i = 0; i < 2; i++)
    if (res[i] != oo && size(q) - res[i] < res[i])
    {
      res[i] = size(q) - res[i];
      for (int x : q)
        flipped[x][i] ^= 1;
    }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    char c;
    cin >> x >> y >> c;
    a[--x].push_back({--y, int(c == 'R')});
    a[y].push_back({x, c == 'R'});
  }

  vector<int> ans(2);
  for (int i = 0; i < n; i++)
    if (!done[i])
    {
      vector<int> res = solve(i);
      for (int j = 0; j < 2; j++)
        ans[j] = min(oo, ans[j] + res[j]);
    }

  int goal = ans[1] < ans[0];
  if (ans[goal] == oo) cout << -1 << endl;
  else
  {
    cout << ans[goal] << endl;
    for (int i = 0; i < n; i++)
      if (flipped[i][goal])
        cout << i + 1 << ' ';
  }
}