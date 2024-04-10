#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, ans = 1;
  cin >> n >> m;
  map<int, int> s[100100];
  while (m--)
  {
    int x, y, z;
    cin >> x >> y >> z;

    int len = 1;
    auto it = s[x].lower_bound(z);
    if (it != begin(s[x]))
      len = (--it)->second + 1;
    ans = max(ans, len);

    auto low = s[y].upper_bound(z);
    if (low != begin(s[y]) && prev(low)->second >= len)
      continue;

    s[y][z] = len;
    while (1)
    {
      auto up = s[y].upper_bound(z);
      if (up == end(s[y]) || up->second > len)
        break;
      s[y].erase(up);
    }
  }

  cout << ans << endl;
}