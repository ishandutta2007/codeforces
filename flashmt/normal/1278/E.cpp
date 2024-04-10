#include <bits/stdc++.h>
using namespace std;

int n, child[500500], sibling[500500], isLastChild[500500], par[500500];
int counter, l[500500], r[500500];
vector<int> a[500500];

void dfs(int x)
{
  int lastChild = 0;
  for (int y : a[x])
    if (y != par[x])
    {
      if (!lastChild) child[x] = y;
      else sibling[lastChild] = y;
      lastChild = y;
      par[y] = x;
      dfs(y);
    }
  isLastChild[lastChild] = 1;
}

void solve(int x)
{
  if (child[x]) solve(child[x]);
  else l[x] = ++counter;
  if (isLastChild[x])
    l[par[x]] = ++counter;
  if (sibling[x])
    solve(sibling[x]);
  r[x] = ++counter;

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dfs(1);
  solve(1);
  for (int i = 1; i <= n; i++)
    cout << l[i] << ' ' << r[i] << '\n';
}