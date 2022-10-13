#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> m[100100];

void trace(int x, int y, int z)
{
  for (int u : m[x][y])
    if (u != z)
    {
      trace(x, u, y);
      cout << u << ' ';
      trace(u, y, x);
    }
}

void add(int x, int y, int z)
{
  if (!m[x].count(y)) m[x][y] = {z};
  else m[x][y].push_back(z);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0), flag(n, 0), a[100100];
    vector<vector<int>> triangles;
    for (int i = 0; i < n - 2; i++)
    {
      int x, y, z;
      cin >> x >> y >> z;
      triangles.push_back({x, y, z});
      add(x, y, z);
      add(x, z, y);
      add(y, x, z);
      add(y, z, x);
      add(z, x, y);
      add(z, y, x);
      for (int u : triangles[i])
      {
        a[u].push_back(i);
        cnt[u]++;
      }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
      if (cnt[i] == 1)
        q.push(i);

    vector<int> order;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for (int i : a[x])
        if (!flag[i])
        {
          flag[i] = 1;
          order.push_back(i);
          for (int &y : triangles[i])
            if (--cnt[y] == 1)
              q.push(y);
        }
    }

    int lastId = order.back();
    int x = triangles[lastId][0], y = triangles[lastId][1], z = triangles[lastId][2];
    cout << x << ' ';
    trace(x, y, z);
    cout << y << ' ';
    trace(y, z, x);
    cout << z << ' ';
    trace(z, x, y);
    cout << '\n';

    for (int i = 0; i < n - 2; i++)
      cout << order[i] + 1 << " \n"[i == n - 3];

    for (int i = 1; i <= n; i++)
      m[i].clear();
  }
}