#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> m >> n;

  vector < pair<int, int> > a;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      a.push_back({i, j});

  for (int i = 0, j = m * n - 1; i <= j; i++, j--)
  {
    printf("%d %d\n", a[i].first, a[i].second);
    if (i < j)
      printf("%d %d\n", a[j].first, a[j].second);
  }
}