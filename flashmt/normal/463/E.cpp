#include <bits/stdc++.h>
using namespace std;

int n, values[100100], par[100100], ans[100100], depth[100100];
vector <int> a[100100], divisors[100100], multiples[2000200];

void factorize(int i)
{
  divisors[i].clear();
  int v = values[i];
  
  for (int d = 2; d * d <= v; d++)
    if (v % d == 0)
    {
      divisors[i].push_back(d);
      while (v % d == 0) v /= d;
    }
    
  if (v > 1) divisors[i].push_back(v);
}

void visit(int x)
{
  ans[x] = -1;
  for (int i = 0; i < int(divisors[x].size()); i++)
  {
    int d = divisors[x][i];
    if (!multiples[d].empty()) 
    {
      int y = multiples[d].back();
      if (ans[x] < 0 || depth[ans[x]] < depth[y])
        ans[x] = y;
    }
    multiples[d].push_back(x);
  }
  
  for (int i = 0; i < int(a[x].size()); i++)
  {
    int y = a[x][i];
    if (y == par[x]) continue;
    par[y] = x;
    depth[y] = depth[x] + 1;
    visit(y);
  }
  
  for (int i = 0; i < int(divisors[x].size()); i++)
    multiples[divisors[x][i]].pop_back();
}

int main()
{
  ios::sync_with_stdio(0);
  //freopen("e.in", "r", stdin);
  int q, x, y, type, v;
  
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> values[i];
    
  for (int i = 1; i < n; i++) 
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  
  for (int i = 1; i <= n; i++) factorize(i);
  visit(1);
  
  while (q--)
  {
    cin >> type;
    if (type == 1)
    {
      cin >> x;
      cout << ans[x] << '\n';
    }
    else
    {
      cin >> x >> v;
      values[x] = v;
      factorize(x);
      visit(1);
    }
  }
}