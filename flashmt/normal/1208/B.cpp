#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[2020];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = n - 1;
  set<int> s;
  for (int i = 0; i <= n; i++)
  {
    set<int> t = s;
    ans = min(ans, n - i);
    for (int j = n - 1; j >= i; j--)
    {
      if (t.count(a[j]))
        break;
      ans = min(ans, j - i);
      t.insert(a[j]);
    }

    if (i == n)
      break;

    if (s.count(a[i]))
      break;
    s.insert(a[i]);
  }

  cout << ans << endl;
}