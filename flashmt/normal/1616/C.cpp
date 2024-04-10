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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ans = n - 1;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
      {
        int good = 0;
        for (int k = j + 1; k < n; k++)
          if ((a[j] - a[i]) * (k - j) == (a[k] - a[j]) * (j - i))
            good++;
        ans = min(ans, n - good - 2);
      }

    cout << ans << endl;
  }
}