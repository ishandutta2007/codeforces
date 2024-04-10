#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, b[300300], x;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    a.push_back({x, i + 1});
  }

  for (int i = 0; i < n; i++)
    cin >> b[i];

  sort(a.begin(), a.end());
  sort(b, b + n);

  vector<int> candidates;
  vector<tuple<int, int, int>> ans;
  for (int i = 0; i < n; i++)
    if (a[i].first < b[i]) candidates.push_back(i);
    else if (a[i].first > b[i])
    {
      while (!candidates.empty() && a[i].first > b[i])
      {
        int j = candidates.back();
        candidates.pop_back();
        int d = min(a[i].first - b[i], b[j] - a[j].first);
        ans.push_back({a[j].second, a[i].second, d});
        a[i].first -= d;
        a[j].first += d;
        if (a[j].first < b[j])
          candidates.push_back(j);
      }

      if (a[i].first > b[i])
      {
        cout << "NO" << endl;
        return 0;
      }
    }

  if (!candidates.empty())
  {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES\n" << ans.size() << '\n';
  for (auto t : ans)
    cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
}