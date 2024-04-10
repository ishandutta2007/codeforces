#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[200200], flag[200200] = {0};
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    flag[a[i]] = 1;
  }

  vector<pair<int, int>> paths;
  for (int i = 1; i <= n; i++)
    if (!flag[i])
    {
      int x = i;
      while (a[x])
        x = a[x];
      paths.push_back({i, x});
    }

  int sz = paths.size();
  for (int i = 0; i < sz; i++)
    a[paths[i].second] = paths[(i + 1) % sz].first;

  for (int i = 1; i <= n; i++)
    cout << a[i] << " \n"[i == n];
}