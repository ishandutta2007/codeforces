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
    for (int &x : a)
      cin >> x;
    sort(begin(a), end(a));

    if (n % 2) cout << "NO\n";
    else
    {
      vector<int> b(n);
      for (int i = 0; i < n / 2; i++)
      {
        b[i * 2] = a[i];
        b[i * 2 + 1] = a[n / 2 + i];
      }

      int isGood = 1;
      for (int i = 0; i < n; i++)
        if (1LL * (b[i] - b[(i + 1) % n]) * (b[i] - b[(i + n - 1) % n]) <= 0)
          isGood = 0;

      if (!isGood) cout << "NO\n";
      else
      {
        cout << "YES\n";
        for (int x : b)
          cout << x << ' ';
        cout << '\n';
      }
    }
  }
}