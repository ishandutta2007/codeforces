#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  map <int, int> m;
  int n, x, y;
  cin >> n;
  while (n--)
  {
    cin >> x >> y;
    m[x] = y;
  }
  cin >> n;
  while (n--)
  {
    cin >> x >> y;
    m[x] = max(m[x], y);
  }
  long long ans = 0;
  for (auto u : m)
    ans += u.second;
  cout << ans << endl;
}