#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m), has(1 << n);
  for (int i = 0; i < m; i++)
  {
    cin >> a[i];
    has[a[i]] = 1;
  }

  vector<int> flag(1 << n + 1);
  int maskAll = (1 << n) - 1;

  function<int(int)> go = [&](int mask)
  {
    if (flag[mask])
      return 0;

    flag[mask] = 1;
    if (mask < 1 << n) go((mask ^ maskAll) | 1 << n);
    else
    {
      if (has[mask ^ 1 << n])
        go(mask ^ 1 << n);
      for (int i = 0; i < n; i++)
        if (mask >> i & 1)
          go(mask ^ 1 << i);
    }
    return 1;
  };

  int ans = 0;
  for (int x : a)
    ans += go(x);

  cout << ans << endl;
}