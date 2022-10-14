#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    map<pair<int, int>, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      int x, y, u, v;
      cin >> x >> y >> u >> v;
      u -= x;
      v -= y;
      int g = __gcd(abs(u), abs(v));
      u /= g;
      v /= g;
      ans += cnt[{-u, -v}];
      cnt[{u, v}]++;
    }
    cout << ans << endl;
  }
}