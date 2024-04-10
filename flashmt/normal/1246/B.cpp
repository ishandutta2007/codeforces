#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  long long ans = 0;
  map<vector<pair<int, int>>, int> m;
  int cntEmpty = 0;
  while (n--)
  {
    int x;
    cin >> x;
    vector<pair<int, int>> d;
    for (int i = 2; i * i <= x; i++)
      if (x % i == 0)
      {
        int p = 0;
        while (x % i == 0)
        {
          x /= i;
          p++;
        }

        if (p % k)
          d.push_back({i, p % k});
      }
    if (x > 1)
      d.push_back({x, 1});

    if (d.empty()) ans += cntEmpty++;
    else
    {
      vector<pair<int, int>> complement;
      for (int i = 0; i < d.size(); i++)
        complement.push_back({d[i].first, k - d[i].second});
      if (m.count(complement))
        ans += m[complement];
      m[d]++;
    }
  }

  cout << ans << endl;
}