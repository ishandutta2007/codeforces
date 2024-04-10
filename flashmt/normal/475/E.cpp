#include <bits/stdc++.h>
using namespace std;

int n, components, dfsStep, d[2020], low[2020], num[2020], st[2020], last;
int cntVertex[2020], cntUp[2020], cntDown[2020], subtree[2020];
vector <int> a[2020], b[2020];

void visit(int x, int par)
{
  num[x] = low[x] = ++dfsStep;
  st[++last] = x;
  for (int i = 0; i < int(a[x].size()); i++)
  {
    int y = a[x][i];
    if (y == par) continue;
    if (num[y]) low[x] = min(low[x], num[y]);
    else 
    {
      visit(y, x);
      low[x] = min(low[x], low[y]);
    }
  }
  
  if (num[x] != low[x]) return;
  
  components++;
  while (1)
  {
    int y = st[last--];
    d[y] = components;
    cntVertex[components]++;
    if (y == x) break;
  }
}

void calcDown(int x, int par)
{
  cntDown[x] = cntVertex[x] * cntVertex[x];
  subtree[x] = cntVertex[x];
  
  for (int i = 0; i < int(b[x].size()); i++)
  {
    int y = b[x][i];
    if (y == par) continue;
    
    calcDown(y, x);
    cntDown[x] += cntVertex[x] * subtree[y];
    cntDown[x] += cntDown[y];
    subtree[x] += subtree[y];
  }
}

int optimal(vector <int> a)
{
  int f[2020] = {1}, sum = 0;
  for (int i = 0; i < int(a.size()); i++) sum += a[i];
  for (int i = 0; i < int(a.size()); i++) 
    for (int j = sum; j >= a[i]; j--)
      f[j] |= f[j - a[i]];
      
  int res = 0;
  for (int j = 0; j <= sum; j++)
    if (f[j])
      res = max(res, j * (sum - j));
  
  return res;
}

int main()
{
  //freopen("i.in", "r", stdin);
  int m, x, y;
  cin >> n >> m;
  while (m--)
  {
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  
  for (int i = 1; i <= n; i++)
    if (!d[i])
      visit(i, 0);
      
  for (int x = 1; x <= n; x++)
    for (int i = 0; i < int(a[x].size()); i++)
    {
      int y = a[x][i];
      if (d[x] >= d[y]) continue;
      b[d[x]].push_back(d[y]);
      b[d[y]].push_back(d[x]);
    }
    
  int ans = 0;
  for (int x = 1; x <= components; x++)
  {
    int res = cntVertex[x] * cntVertex[x];
    vector <int> subtrees;
    for (int i = 0; i < int(b[x].size()); i++)
    {
      int y = b[x][i];
      calcDown(y, x);
      res += cntDown[y];
      res += cntVertex[x] * subtree[y];
      subtrees.push_back(subtree[y]);
    }
    
    res += optimal(subtrees);
    ans = max(ans, res);
  }
  
  cout << ans << endl;
}