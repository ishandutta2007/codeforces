#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int N = 200200;

int n, k, dist[2][N], tree[2][N * 2];
vector<int> a[N];

void bfs(int s, int dist[])
{
  queue<int> q;
  for (int i = 1; i <= n; i++)
    dist[i] = -1;
  q.push(s);
  dist[s] = 0;
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int y : a[x])
      if (dist[y] < 0)
      {
        dist[y] = dist[x] + 1;
        q.push(y);
      }
  }
}

void add(int x, int v, int tree[])
{
  for (int i = x + N; i < N * 2; i += i & -i)
    tree[i] = max(tree[i], v);
}

int get(int x, int tree[])
{
  int res = -oo;
  for (int i = x + N; i; i -= i & -i)
    res = max(res, tree[i]);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> n >> m >> k;
  vector<int> b(k);
  for (int i = 0; i < k; i++)
    cin >> b[i];
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  bfs(1, dist[0]);
  bfs(n, dist[1]);
  int minDist = dist[0][n];

  for (int i = 0; i < N * 2; i++)
    tree[0][i] = tree[1][i] = -oo;
  int ans = -1;
  for (int x : b)
  {
    int diff = dist[1][x] - dist[0][x];
    int newDist = max(get(diff, tree[1]) + dist[0][x], get(-diff, tree[0]) + dist[1][x]) + 1;
    ans = max(ans, min(minDist, newDist));
    add(diff, dist[1][x], tree[1]);
    add(-diff, dist[0][x], tree[0]);
  }

  cout << ans << endl;
}