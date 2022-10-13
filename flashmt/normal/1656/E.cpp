#include <bits/stdc++.h>
using namespace std;
const int N = 100100;

vector<int> a[N];
int c[N];

void dfs(int x, int par)
{
  for (int y : a[x])
    if (y != par)
    {
      c[y] = c[x] ^ 1;
      dfs(y, x);
    }
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
    for (int i = 0; i < n; i++)
      a[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
      a[y].push_back(x);
    }

    c[0] = 0;
    dfs(0, -1);
    for (int i = 0; i < n; i++)
    {
      int deg = size(a[i]);
      cout << (c[i] ? deg : -deg) << " \n"[i == n - 1];
    }
  }
}