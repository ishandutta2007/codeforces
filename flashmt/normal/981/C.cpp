#include <bits/stdc++.h>
using namespace std;

vector <int> a[100100];

int leaf(int x, int par)
{
  for (int y : a[x])
    if (y != par)
      return leaf(y, x);
  return x;
}

int main()
{
  ios::sync_with_stdio(0);
  int x, y, n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  int root = 1;
  for (int i = 2; i <= n; i++)
    if (a[i].size() > a[root].size())
      root = i;

  for (int i = 1; i <= n; i++)
    if (i != root && a[i].size() > 2)
    {
      cout << "No\n";
      return 0;
    }

  cout << "Yes\n" << a[root].size() << '\n';
  for (int x : a[root])
    cout << root << ' ' << leaf(x, root) << '\n';
}