#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;

  auto cmp = [&](pair<int, int> u, pair<int, int> v)
  {
    if ((u.second < 0) ^ (v.second < 0))
      return u.second < 0;
    return 1LL * u.first * v.second - 1LL * v.first * u.second > 0;
  };

  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    vector<pair<int, int>> b;
    for (int j = 0; j < n; j++)
      if (j != i)
        b.push_back({a[j].first - a[i].first, a[j].second - a[i].second});

    sort(begin(b), end(b), cmp);
    for (int j = 0; j < n - 1; j++)
      b.push_back(b[j]);

    ans += (n - 1LL) * (n - 2) * (n - 3) / 6;
    for (int j = 0, jj = 1; j < n - 1; j++)
    {
      jj = max(jj, j + 1);
      while (jj < n * 2 - 2)
      {
        long long ccw = 1LL * b[j].first * b[jj].second - 1LL * b[jj].first * b[j].second;
        if (ccw > 0) jj++;
        else break;
      }
      ans -= (jj - j - 1LL) * (jj - j - 2) / 2;
    }
  }

  cout << ans * (n - 4) / 2 << endl;
}