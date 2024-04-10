#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    vector<pair<int, int>> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i].first + a[i].second > a[j].first + a[j].second)
          swap(a[i], a[j]);

    int hasAns = 1;
    string ans;
    for (int i = 0, x = 0, y = 0; i < n; i++)
      if (x > a[i].first || y > a[i].second) hasAns = 0;
      else
      {
        while (x < a[i].first)
        {
          x++;
          ans += 'R';
        }
        while (y < a[i].second)
        {
          y++;
          ans += 'U';
        }
      }

    if (!hasAns) cout << "NO\n";
    else cout << "YES\n" << ans << '\n';
  }
}