#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  map<long long, vector<pair<long long, long long>>> a;
  for (int i = 0; i < n; i++)
  {
    long long w, h, c;
    cin >> w >> h >> c;
    a[w].push_back({h, c});
  }

  long long g = 0;
  for (auto &[k, v] : a)
  {
    sort(begin(v), end(v));
    long long curG = 0;
    for (auto [h, c] : v)
      curG = gcd(curG, c);
    for (auto &[_, c] : v)
      c /= curG;
    g = gcd(g, curG);
  }

  int isValid = 1;
  for (auto [_, v]: a)
    if (v != begin(a)->second)
      isValid = 0;

  if (!isValid) cout << 0 << endl;
  else
  {
    long long ans = 0;
    for (int i = 1; 1LL * i * i <= g; i++)
      if (g % i == 0)
      {
        ans++;
        ans += 1LL * i * i < g;
      }

    cout << ans << endl;
  }
}