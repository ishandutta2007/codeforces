#include <bits/stdc++.h>
using namespace std;
const int MOD = 2520, N = 1010;

int n, k[N], m[N], a[N][10], to[N * MOD], inEdge[N * MOD], flag[N * MOD], ans[N * MOD];

void go(int x)
{
  int cnt = 1;
  vector<int> path;
  while (!flag[x])
  {
    flag[x] = cnt++;
    path.push_back(x);
    x = to[x];
  }

  int cycle = ans[x];
  if (flag[x] > 0)
  {
    set<int> s;
    for (int i = flag[x] - 1; i < path.size(); i++)
      s.insert(path[i] / MOD);
    cycle = s.size();
  }

  for (int u : path)
  {
    ans[u] = cycle;
    flag[u] = -1;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> k[i];
    k[i] = (k[i] + 1000001520) % MOD;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> m[i];
    for (int j = 0; j < m[i]; j++)
    {
      cin >> a[i][j];
      a[i][j]--;
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < MOD; j++)
    {
      int jj = (j + k[i]) % MOD, ii = a[i][jj % m[i]];
      to[i * MOD + j] = ii * MOD + jj;
      inEdge[ii * MOD + jj] = 1;
    }

  for (int i = 0; i < n * MOD; i++)
    if (!flag[i] && !inEdge[i])
      go(i);

  for (int i = 0; i < n * MOD; i++)
    if (!flag[i])
      go(i);

  int q, x, y;
  cin >> q;
  while (q--)
  {
    cin >> x >> y;
    y = (y + 1000001520) % MOD;
    cout << ans[(x - 1) * MOD + y] << '\n';
  }
}