#include <bits/stdc++.h>
using namespace std;
const int N = 300300;

int n;
vector<int> a[N], ans, tr;

vector<int> trace(int x)
{
  vector<int> res;
  while (x >= 0)
  {
    res.push_back(x);
    x = tr[x];
  }
  reverse(begin(res), end(res));
  return res;
}

void bfs()
{
  queue<int> q;
  vector<int> dist(n, -1);
  dist[0] = 0;
  tr.assign(n, -1);
  q.push(0);
  while (!empty(q))
  {
    int x = q.front();
    q.pop();
    for (int y : a[x])
      if (dist[y] < 0)
      {
        dist[y] = dist[x] + 1;
        tr[y] = x;
        q.push(y);
      }
  }

  if (dist[n - 1] >= 0)
    ans = trace(n - 1);

  // 0 -> x -> y -> 0 -> n - 1
  if (dist[n - 1] < 0 || dist[n - 1] > 4)
    for (int i = 1; i < n - 1; i++)
      if (dist[i] == 2)
      {
        ans = trace(i);
        ans.push_back(0);
        ans.push_back(n - 1);
        return;
      }
}

void checkNeighbors()
{
  vector<int> flag(n);
  for (int x : a[0])
    a[x].erase(find(begin(a[x]), end(a[x]), 0));
  for (int x : a[0])
  {
    for (int y : a[x])
      flag[y] = x;
    for (int y : a[x])
      for (int z : a[y])
        if (z != x && flag[z] != x)
        {
          if (empty(ans) || size(ans) > 6)
            ans = {0, x, y, z, x, n - 1};
          return;
        }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  if (find(begin(a[0]), end(a[0]), n - 1) != end(a[0]))
  {
    cout << 1 << endl;
    cout << 1 << ' ' << n << endl;
    return 0;
  }

  bfs();
  checkNeighbors();

  if (empty(ans)) cout << -1 << endl;
  else
  {
    cout << size(ans) - 1 << endl;
    for (int x : ans)
      cout << x + 1 << ' ';
  }
}