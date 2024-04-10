#include <bits/stdc++.h>
using namespace std;

int n, a, b, p[100100], visited[100100], ans[100100];
map <int,int> id;
vector <int> edges[100100];

int solve(int start)
{
  vector <int> list;
  int x = start;
  while (!visited[x])
  {
    list.push_back(x);
    visited[x] = 1;
    for (int j = 0; j < int(edges[x].size()); j++)
    {
      int y = edges[x][j];
      if (visited[y]) continue;
      x = y;
      break;
    }
  }
  
  if (list.size() % 2)
  {
    if (p[start] * 2 == a || p[start] * 2 == b)
    {
      reverse(list.begin(), list.end());
      list.push_back(list.back());
    }
    else if (p[x] * 2 == a || p[x] * 2 == b) list.push_back(list.back());
    else return 0;
  }
  
  for (int j = 0; j < int(list.size()); j += 2)
    if (p[list[j]] + p[list[j + 1]] == b) ans[list[j]] = ans[list[j + 1]] = 1;
  
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> a >> b;
  
  for (int i = 0; i < n; i++) 
  {
    cin >> p[i];
    id[p[i]] = i;
  }

  for (int i = 0; i < n; i++)
  {
    if (id.count(a - p[i]) && p[i] * 2 != a) edges[i].push_back(id[a - p[i]]);
    if (id.count(b - p[i]) && p[i] * 2 != b && a != b) edges[i].push_back(id[b - p[i]]);
  }
  
  for (int i = 0; i < n; i++)
    if (!visited[i] && edges[i].size() < 2)
      if (!solve(i))
      {
        cout << "NO" << endl;
        return 0;
      }
    
  for (int i = 0; i < n; i++) assert(visited[i] > 0);
    
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}