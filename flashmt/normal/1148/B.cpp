#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n, ta, tb, k, x;
  cin >> m >> n >> ta >> tb >> k;
  vector<pair<int, int>> a;
  for (int i = 0; i < m; i++)
  {
    cin >> x;
    a.push_back({x + ta, 0});
  }
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    a.push_back({x, 1});
  }
  sort(a.begin(), a.end());

  int open = 0;
  for (auto u : a)
    if (!u.second) open++;
    else if (open)
    {
      if (!k)
      {
        cout << u.first + tb << endl;
        return 0;
      }
      k--;
      open--;
    }

  cout << -1 << endl;
}