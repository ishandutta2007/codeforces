#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  pair<int, int> a[20];
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i].first >> a[i].second;

  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++)
      if (a[i].second < a[j].second)
        swap(a[i], a[j]);

  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    ans += min(a[i].first, n) * a[i].second;
    n -= min(a[i].first, n);
  }

  cout << ans << endl;
}