#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, l, a[100100] = {0}, ans = 0;
  cin >> n >> m >> l;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    if (a[i] > l && a[i - 1] <= l)
      ans++;
  }

  while (m--)
  {
    int op, i, x;
    cin >> op;
    if (!op) cout << ans << '\n';
    else
    {
      cin >> i >> x;
      if (a[i] <= l && a[i] + x > l)
      {
        if (a[i - 1] > l && a[i + 1] > l) ans--;
        else if (a[i - 1] <= l && a[i + 1] <= l) ans++;
      }
      a[i] = min(a[i] + x, l + 1);
    }
  }
}