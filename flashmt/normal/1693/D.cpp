#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  long long ans = 1;
  vector<int> f(n, oo); // max decreasing value when a[i] is increasing
  vector<int> g(n, -oo); // min increasing value when a[i] is decreasing
  for (int i = n - 2, bound = n - 1; i >= 0; i--)
  {
    for (int j = i + 1; j <= bound; j++)
    {
      int oldF = f[j], oldG = g[j];
      if (a[j - 1] < a[j])
      {
        if (f[j - 1] > a[j]) g[j] = a[j - 1];
        else g[j] = oo;
        f[j] = f[j - 1];
        if (g[j - 1] < a[j])
          f[j] = max(f[j], a[j - 1]);
      }
      else
      {
        if (g[j - 1] < a[j]) f[j] = a[j - 1];
        else f[j] = -oo;
        g[j] = g[j - 1];
        if (f[j - 1] > a[j])
          g[j] = min(g[j], a[j - 1]);
      }

      if (f[j] == oldF && g[j] == oldG)
        break;

      if (f[j] < 0 && g[j] > n)
      {
        bound = j - 1;
        break;
      }
    }
    ans += bound - i + 1;
  }

  cout << ans << endl;
}