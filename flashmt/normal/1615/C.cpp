#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
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
    string a, b;
    cin >> n >> a >> b;
    if (a == b)
    {
      cout << 0 << '\n';
      continue;
    }

    vector<int> same(2), diff(2);
    for (int i = 0; i < n; i++)
      if (a[i] == b[i]) same[a[i] - '0']++;
      else diff[a[i] - '0']++;

    int ans = n + 1;
    if (same[1] == same[0] + 1)
      ans = min(ans, same[0] + same[1]);
    if (diff[0] == diff[1])
      ans = min(ans, diff[0] + diff[1]);
    if (ans > n)
      ans = -1;
    cout << ans << '\n';
  }
}