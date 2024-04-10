#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];

  long long ans = 0, x = 0;
  vector<pair<long long, long long>> segs;
  for (int i = 0; i < n; i++)
    if (i % 2 == 0)
    {
      segs.push_back({x, x + c[i]});
      x += c[i];
    }
    else
    {
      for (auto [l, r] : segs)
        ans += max(0LL, min(r, x - 1) - max(l, x - c[i]) + 1);
      while (!empty(segs))
      {
        auto [l, r] = segs.back();
        segs.pop_back();
        if (l <= x - c[i])
        {
          segs.push_back({l, x - c[i]});
          break;
        }
      }
      x = max(0LL, x - c[i]);
    }

  cout << ans << endl;
}