#include <bits/stdc++.h>
using namespace std;

int m, n, parity[100100], start, visited[100100], need[100100];
vector <int> a[100100], aTree[100100], ans;

void bfs()
{
  queue <int> q;
  q.push(start);
  visited[start] = 1;
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int i = 0; i < int(a[x].size()); i++)
    {
      int y = a[x][i];
      if (!visited[y])
      {
        visited[y] = 1;
        q.push(y);
        aTree[x].push_back(y);
        aTree[y].push_back(x);
      }
    }
  }
}

void dfs(int x, int par)
{
  need[x] = parity[x];
  
  for (int i = 0; i < int(aTree[x].size()); i++)
  {
    int y = aTree[x][i];
    if (y == par) continue;
    dfs(y, x);
    need[x] |= need[y];
  }
}

void findPath(int x, int par)
{
  ans.push_back(x);
  parity[x] ^= 1;
  for (int i = 0; i < int(aTree[x].size()); i++)
  {
    int y = aTree[x][i];
    if (y == par) continue;
    if (need[y]) 
    {
      findPath(y, x);
      parity[x] ^= 1;
      ans.push_back(x);
    }
  }
  
  if (parity[x])
  {
    if (par > 0)
    {
      ans.push_back(par);
      parity[par] ^= 1;
      ans.push_back(x);
      parity[x] ^= 1;
    }
    else
    {
      ans.pop_back();
      parity[x] ^= 1;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  //freopen("c.in", "r", stdin);
  int x, y;
  
  cin >> n >> m;
  while (m--)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  
  for (int i = 1; i <= n; i++) 
  {
    cin >> parity[i];
    if (parity[i]) start = i;
  }
  
  bfs();
  
  dfs(start, -1);  
  
  findPath(start, -1);
  for (int i = 1; i <= n; i++)
    if (parity[i])
    {
      cout << -1 << endl;
      return 0;
    }
    
  cout << ans.size() << endl;
  for (int i = 0; i < int(ans.size()); i++) cout << ans[i] << ' ';
}